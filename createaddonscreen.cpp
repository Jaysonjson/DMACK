#include "createaddonscreen.h"
#include "ui_createaddonscreen.h"
#include "vars.h"
#include "mainmanagerscreen.h"

CreateAddonScreen::CreateAddonScreen(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::CreateAddonScreen)
{
    ui->setupUi(this);
}

CreateAddonScreen::~CreateAddonScreen()
{
    delete ui;
}

void CreateAddonScreen::on_pushButton_clicked()
{
    addonPack->packData.id = ui->idEdit->text().toStdString();
    addonPack->packData.name = ui->nameEdit->text().toStdString();
    MainManagerScreen* screen = new MainManagerScreen();
    screen->show();
    close();
}

