#include "addexteriorlayerscreen.h"
#include "ui_addexteriorlayerscreen.h"
#include "createtardisscreen.h"
#include "vars.h"
#include <QFileDialog>

AddExteriorLayerScreen::AddExteriorLayerScreen(QWidget *parent, CreateTardisScreen* tardisScreen)
    : QDialog(parent)
    , ui(new Ui::AddExteriorLayerScreen)
{
    ui->setupUi(this);
    this->tardisScreen = tardisScreen;
}

AddExteriorLayerScreen::~AddExteriorLayerScreen()
{
    delete ui;
}

void AddExteriorLayerScreen::on_addButton_clicked()
{
    qDebug() << ui->layerCombo->currentText().toStdString();
    qDebug() << texturePath;
    qDebug() << texturePath.substr(texturePath.find_last_of("/") + 1);
    qDebug() << ui->typeCombo->currentText().toStdString();
    this->tardisScreen->layers.emplace(ui->layerCombo->currentText().toStdString(), DM::Tardis::ClientLayer{addonPack->addTexture(texturePath, texturePath.substr(texturePath.find_last_of("/") + 1)).getPath(addonPack->packData), ui->typeCombo->currentText().toStdString()});
    ui->feedBackLabel->setText(QString::fromStdString("Layer " + ui->layerCombo->currentText().toStdString() + " Added!"));
    this->tardisScreen->reloadLayers();
}

void AddExteriorLayerScreen::on_textureButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Load Texture"), "", tr("Textures (*.png)"));
    if (!fileName.isEmpty()) {
        texturePath = fileName.toStdString();
        ui->textureLabel->setText(QString::fromStdString(texturePath.substr(texturePath.find_last_of("/") + 1)));
        QPixmap texture(QString::fromStdString(texturePath));
        ui->textureIconLabel->setPixmap(texture);
    }
}


void AddExteriorLayerScreen::on_pushButton_2_clicked()
{
    close();
}

