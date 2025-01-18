#include "tardismanagerscreen.h"
#include "ui_tardismanagerscreen.h"
#include "createtardisscreen.h"
#include "vars.h"
#include "clickablelabel.h"
#include "mainmanagerscreen.h"

void TardisManagerScreen::reloadItems() {
    int row = 0;
    int col = 0;
    int maxCols = 4;
    while (QLayoutItem *item = ui->gridLayout->takeAt(0)) {
        if (QWidget *widget = item->widget()) {
            widget->deleteLater();
        }
    }
    for (auto& exterior : addonPack->clientExteriors) {
        ClickableLabel  *iconLabel = new ClickableLabel(ui->scrollAreaWidgetContents);
        iconLabel->contentId = exterior.getId();
        iconLabel->setBaseSize(80, 80);
        QIcon icon(QStringLiteral(":/resources/tardis_exterior.png"));
        iconLabel->setPixmap(icon.pixmap(80, 80));
        qDebug() << row;
        qDebug() << col;

        QLabel *textLabel = new QLabel(QString::fromUtf8(exterior.getId()), ui->scrollAreaWidgetContents);
        connect(iconLabel, &ClickableLabel::clicked, this, &TardisManagerScreen::onIconLabelClicked);

        ui->gridLayout->addWidget(iconLabel, row, col * 2, Qt::AlignLeft | Qt::AlignTop);
        ui->gridLayout->addWidget(textLabel, row, col * 2 + 1, Qt::AlignLeft | Qt::AlignTop);
        ++col;
        if(col >= maxCols) {
            col = 0;
            ++row;
        }
    }
    ui->scrollAreaWidgetContents->setLayout(ui->gridLayout);
    ui->scrollArea->setWidget(ui->scrollAreaWidgetContents);
}

TardisManagerScreen::TardisManagerScreen(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::TardisManagerScreen)
{
    ui->setupUi(this);
    //ui->gridLayout->setSpacing(10);
    //ui->gridLayout->setContentsMargins(10, 10, 10, 10);
    reloadItems();
    ui->tardisManagerLabel->setText(QString::fromStdString(addonPack->packData.name + " - TARDIS MANAGER"));
}

TardisManagerScreen::~TardisManagerScreen()
{
    delete ui;
}

void TardisManagerScreen::onIconLabelClicked()
{
    ClickableLabel *label = qobject_cast<ClickableLabel*>(sender());
    if (label) {
        string builder = "";
        for (auto& exterior : addonPack->serverExteriors) {
            if(exterior.getId() == label->contentId) {
                builder = exterior.getBuilder();
                break;
            }
        }
        for (auto& exterior : addonPack->clientExteriors) {
            if(exterior.getId() == label->contentId) {
                CreateTardisScreen* screen = new CreateTardisScreen(nullptr, exterior, builder);
                screen->managerScreen = this;
                screen->show();
                break;
            }
        }
    }
}

void TardisManagerScreen::on_pushButton_clicked()
{
    CreateTardisScreen* screen = new CreateTardisScreen();
    screen->managerScreen = this;
    screen->show();
}


void TardisManagerScreen::on_backButton_clicked()
{
    MainManagerScreen* screen = new MainManagerScreen();
    screen->show();
    close();
}

