#ifndef TARDISMANAGERSCREEN_H
#define TARDISMANAGERSCREEN_H

#include <QDialog>

namespace Ui {
class TardisManagerScreen;
}

class TardisManagerScreen : public QDialog
{
    Q_OBJECT

public:
    explicit TardisManagerScreen(QWidget *parent = nullptr);
    ~TardisManagerScreen();
    void reloadItems();
private:
    Ui::TardisManagerScreen *ui;
private slots:
    void onIconLabelClicked();
    void on_pushButton_clicked();
    void on_backButton_clicked();
};

#endif // TARDISMANAGERSCREEN_H
