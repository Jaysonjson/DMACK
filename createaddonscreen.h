#ifndef CREATEADDONSCREEN_H
#define CREATEADDONSCREEN_H

#include <QDialog>

namespace Ui {
class CreateAddonScreen;
}

class CreateAddonScreen : public QDialog
{
    Q_OBJECT

public:
    explicit CreateAddonScreen(QWidget *parent = nullptr);
    ~CreateAddonScreen();

private slots:
    void on_pushButton_clicked();

private:
    Ui::CreateAddonScreen *ui;
};

#endif // CREATEADDONSCREEN_H
