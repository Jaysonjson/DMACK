#include "startscreen.h"
#include "./ui_startscreen.h"
#include <QFileDialog>
#include <QMessageBox>
#include "mainmanagerscreen.h"
#include "createaddonscreen.h"
#include "vars.h"
#include <QPropertyAnimation>

StartScreen::StartScreen(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::StartScreen)
{
    ui->setupUi(this);
}

StartScreen::~StartScreen()
{
    delete ui;
}

void StartScreen::on_loadAddon_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Load DM Addon"), "", tr("DM Addon Packs (*.dma *.zip *.dmaddon)"));
    if (!fileName.isEmpty())
    {
        addonPack->load(fileName.toStdString(), "cache/");
        //QMessageBox::information(this, tr("File Selected"), tr("You selected: %1").arg(fileName));
        MainManagerScreen* screen = new MainManagerScreen();
        screen->show();
        this->close();
    }
}


void StartScreen::on_createAddon_clicked()
{
    CreateAddonScreen* screen = new CreateAddonScreen();
    screen->show();
    this->close();
}

