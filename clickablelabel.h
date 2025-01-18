#ifndef CLICKABLELABEL_H
#define CLICKABLELABEL_H
#include <QLabel>
#include <QMouseEvent>
#include <QWidget>
#include <QIcon>

class ClickableLabel : public QLabel
{
    Q_OBJECT

public:
    std::string contentId = "";
    explicit ClickableLabel(QWidget *parent = nullptr) : QLabel(parent) {
        setAlignment(Qt::AlignCenter);
    }

signals:
    void clicked();

protected:
    void mousePressEvent(QMouseEvent *event) override {
        if (event->button() == Qt::LeftButton) {
            emit clicked();
        }
        QLabel::mousePressEvent(event);
    }
};

#endif // CLICKABLELABEL_H
