#pragma once
#include <QtWidgets>

class Widget : public QWidget
{
    Q_OBJECT
public:
    explicit Widget(QWidget *parent = 0);
private slots:
    void out();
    void edit();
private:
    QString str;
    QLabel *outLine;
    QPushButton *act;
    QLineEdit *n1;
    QLineEdit *n2;
    QLineEdit *s1;
    QLineEdit *s2;
};
