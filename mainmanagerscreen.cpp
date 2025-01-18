#include "mainmanagerscreen.h"
#include "ui_mainmanagerscreen.h"
#include "tardismanagerscreen.h"
#include <QFileDialog>
#include "vars.h"

MainManagerScreen::MainManagerScreen(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::MainManagerScreen)
{
    ui->setupUi(this);
    ui->managerLabel->setText(QString::fromStdString(addonPack->packData.name + " - MANAGER"));
}

MainManagerScreen::~MainManagerScreen()
{
    delete ui;
}

void MainManagerScreen::on_pushButton_clicked()
{
    TardisManagerScreen* screen = new TardisManagerScreen();
    screen->show();
    this->close();
}


void MainManagerScreen::on_packButton_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Save File", QDir::homePath(), "DM Addon (*.dma *.dmaddon *.zip)");

    if (!fileName.isEmpty()) {
        addonPack->pack(fileName.toStdString(), true);
    }
}

