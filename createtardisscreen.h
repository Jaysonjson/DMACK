#ifndef CREATETARDISSCREEN_H
#define CREATETARDISSCREEN_H

#include <QDialog>
#include "dm/tardis.hpp"

namespace Ui {
class CreateTardisScreen;
}
class TardisManagerScreen;
class CreateTardisScreen : public QDialog
{
    Q_OBJECT

public:
    std::string animationPath;
    std::string modelpath;
    std::string texturePath;
    TardisManagerScreen* managerScreen;
    std::map<std::string, DM::Tardis::ClientLayer> layers{};
    explicit CreateTardisScreen(QWidget *parent = nullptr, DM::Tardis::ClientExterior clientExterior = {}, const string& builder = "");
    ~CreateTardisScreen();
    void reloadLayers();
private slots:
    void on_pushButton_clicked();

    void on_modelButton_clicked();

    void on_animationButton_clicked();

    void on_textureButton_clicked();

    void on_createButton_clicked();
    void onLayerClicked();
private:
    Ui::CreateTardisScreen *ui;
};

#endif // CREATETARDISSCREEN_H
