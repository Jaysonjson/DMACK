#ifndef MAINMANAGERSCREEN_H
#define MAINMANAGERSCREEN_H

#include <QDialog>

namespace Ui {
class MainManagerScreen;
}

class MainManagerScreen : public QDialog
{
    Q_OBJECT

public:
    explicit MainManagerScreen(QWidget *parent = nullptr);
    ~MainManagerScreen();

private slots:
    void on_pushButton_clicked();

    void on_packButton_clicked();

private:
    Ui::MainManagerScreen *ui;
};

#endif // MAINMANAGERSCREEN_H
