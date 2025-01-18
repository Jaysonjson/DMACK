#ifndef ADDEXTERIORLAYERSCREEN_H
#define ADDEXTERIORLAYERSCREEN_H

#include <QDialog>

namespace Ui {
class AddExteriorLayerScreen;
}

class CreateTardisScreen;

class AddExteriorLayerScreen : public QDialog
{
    Q_OBJECT

public:
    CreateTardisScreen* tardisScreen = nullptr;
    std::string texturePath = "";
    explicit AddExteriorLayerScreen(QWidget *parent = nullptr, CreateTardisScreen* tardisScreen = nullptr);
    ~AddExteriorLayerScreen();

private slots:
    void on_addButton_clicked();

    void on_textureButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::AddExteriorLayerScreen *ui;
};

#endif // ADDEXTERIORLAYERSCREEN_H
