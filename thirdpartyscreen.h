#ifndef THIRDPARTYSCREEN_H
#define THIRDPARTYSCREEN_H

#include <QDialog>

namespace Ui {
class ThirdPartyScreen;
}

class ThirdPartyScreen : public QDialog
{
    Q_OBJECT

public:
    explicit ThirdPartyScreen(QWidget *parent = nullptr);
    ~ThirdPartyScreen();

private:
    Ui::ThirdPartyScreen *ui;
};

#endif // THIRDPARTYSCREEN_H
