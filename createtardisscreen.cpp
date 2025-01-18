#include "createtardisscreen.h"
#include "ui_createtardisscreen.h"
#include "tardismanagerscreen.h"
#include "vars.h"
#include <QFileDialog>
#include "addexteriorlayerscreen.h"
#include "clickablelabel.h"

CreateTardisScreen::CreateTardisScreen(QWidget *parent, DM::Tardis::ClientExterior exterior, const string& builder)
    : QDialog(parent)
    , ui(new Ui::CreateTardisScreen)
{
    ui->setupUi(this);
    if(!exterior.getId().empty()) {
        ui->idEdit->setText(QString::fromStdString(exterior.getId().substr(exterior.getId().find_last_of(":") + 1)));
        ui->nameEdit->setText(QString::fromStdString(exterior.name));
        ui->descriptionEdit->setText(QString::fromStdString(exterior.description));
        ui->builderBox->setEditText(QString::fromStdString(builder));
        modelpath = exterior.model;
        animationPath = exterior.animation;
        texturePath = exterior.texture;
        ui->modelLabel->setText(QString::fromStdString(modelpath.substr(modelpath.find_last_of("/") + 1)));
        ui->animationLabel->setText(QString::fromStdString(animationPath.substr(animationPath.find_last_of("/") + 1)));
        ui->textureLabel->setText(QString::fromStdString(texturePath.substr(texturePath.find_last_of("/") + 1)));
        qDebug() << texturePath;
        QPixmap texture(QString::fromStdString(addonPack->inputDir + texturePath));
        ui->textureIconLabel->setPixmap(texture);
        for (auto& pair : exterior.layers) {
            this->layers.emplace(pair.first, pair.second);
        }
        reloadLayers();
    }
}

CreateTardisScreen::~CreateTardisScreen()
{
    delete ui;
}

void CreateTardisScreen::reloadLayers()
{
    while (QLayoutItem *item = ui->verticalLayout->takeAt(0)) {
        if (QWidget *widget = item->widget()) {
            widget->deleteLater();
        }
    }
    int row = 0;
    for (auto& layer : layers) {
        QPushButton  *layerLabel = new QPushButton(ui->scrollAreaWidgetContents);
        layerLabel->setStyleSheet(
            "QPushButton {"
            "    border: none;"
            "    border-image: url(:/resources/button_normal.png) 0 0 0 0 stretch stretch;"
            "    color: #424242;"
            "    width: 125;"
            "    height: 20;"
            "    padding-bottom: 2px;"
            "}"
            "QPushButton:hover {"
            "    border-image: url(:/resources/button_hovered.png) 0 0 0 0 stretch stretch;"
            "    color: black;"
            "    padding-bottom: 2px;"
            "}"
            "QPushButton:pressed {"
            "    border-image: url(:/resources/button_pressed.png) 0 0 0 0 stretch stretch;"
            "    color: black;"
            "    padding-bottom: -6px;"
            "}"
            );
        layerLabel->setText(QString::fromStdString(layer.first));
        ui->verticalLayout->addWidget(layerLabel, row, Qt::AlignLeft | Qt::AlignTop);
        ++row;
    }
}

void CreateTardisScreen::on_modelButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Load Geo Model"), "", tr("Geo Models (*.geo.json)"));
    if (!fileName.isEmpty()) {
        modelpath = fileName.toStdString();
        ui->modelLabel->setText(QString::fromStdString(modelpath.substr(modelpath.find_last_of("/") + 1)));
    }
}



void CreateTardisScreen::on_animationButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Load Geo Animation"), "", tr("Geo Animation (*.animation.json)"));
    if (!fileName.isEmpty()) {
        animationPath = fileName.toStdString();
        ui->animationLabel->setText(QString::fromStdString(animationPath.substr(animationPath.find_last_of("/") + 1)));
    }
}


void CreateTardisScreen::on_textureButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Load Texture"), "", tr("Textures (*.png)"));
    if (!fileName.isEmpty()) {
        texturePath = fileName.toStdString();
        ui->textureLabel->setText(QString::fromStdString(texturePath.substr(texturePath.find_last_of("/") + 1)));
        QPixmap texture(QString::fromStdString(texturePath));
        ui->textureIconLabel->setPixmap(texture);
    }
}


void CreateTardisScreen::on_createButton_clicked()
{
    if(!modelpath.empty() && !animationPath.empty() && !texturePath.empty() && !ui->idEdit->text().toStdString().empty()) {
        addonPack->addExterior(ui->idEdit->text().toStdString(), ui->nameEdit->text().toStdString(), ui->descriptionEdit->text().toStdString(), modelpath.substr(modelpath.find_last_of("/") + 1),
                               modelpath, animationPath.substr(animationPath.find_last_of("/") + 1), animationPath, texturePath.substr(texturePath.find_last_of("/") + 1), texturePath, ui->builderBox->currentText().toStdString());

        for (auto& exterior : addonPack->clientExteriors) {
            if(exterior.getId() == addonPack->packData.id + ":" + ui->idEdit->text().toStdString()) {
                exterior.layers = layers;
                break;
            }
        }

        managerScreen->reloadItems();
        close();
    }
}

void CreateTardisScreen::onLayerClicked()
{
    ClickableLabel *label = qobject_cast<ClickableLabel*>(sender());
    if (label) {

    }
}

void CreateTardisScreen::on_pushButton_clicked()
{
    AddExteriorLayerScreen* screen = new AddExteriorLayerScreen(nullptr, this);
    screen->show();
}

