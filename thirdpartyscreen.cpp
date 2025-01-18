#include "thirdpartyscreen.h"
#include "ui_thirdpartyscreen.h"

ThirdPartyScreen::ThirdPartyScreen(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ThirdPartyScreen)
{
    ui->setupUi(this);
}

ThirdPartyScreen::~ThirdPartyScreen()
{
    delete ui;
}
