#pragma once
#include <QtWidgets>

class Widget : public QWidget
{
    Q_OBJECT
public:
    explicit Widget(QWidget *parent = 0);
private slots:
    void autoOut();
    void convert();
private:
    QString str;
    QLabel *outLine;
    QPushButton *act;
    QLineEdit *inLine;
};
