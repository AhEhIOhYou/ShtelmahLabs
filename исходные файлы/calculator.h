#pragma once

#include <QtWidgets>

class calculator : public QWidget {
    Q_OBJECT
private:
    QLCDNumber* outputLCD;
    QStack<QString> numStk;
    QString inDataStr;
public:
    calculator(QWidget* pwgt = 0);
    QPushButton* defaultButton(const QString& str);
    void calculate();
public slots:
    void whenClicked();
};
