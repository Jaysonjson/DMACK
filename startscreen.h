#ifndef STARTSCREEN_H
#define STARTSCREEN_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class StartScreen;
}
QT_END_NAMESPACE

class StartScreen : public QMainWindow
{
    Q_OBJECT

public:
    StartScreen(QWidget *parent = nullptr);
    ~StartScreen();

private slots:
    void on_loadAddon_clicked();

    void on_createAddon_clicked();

private:
    Ui::StartScreen *ui;
};
#endif // STARTSCREEN_H
