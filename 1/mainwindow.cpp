#include "mainwindow.h"

Widget::Widget(QWidget *parent) : QWidget(parent) {

    this->resize(200,130);

    outLine = new QLabel;

    QPalette pall;
    pall.setColor(outLine->backgroundRole(), Qt::white);
    outLine->setPalette(pall);
    outLine->setAutoFillBackground(true);

    act = new QPushButton("Convert");
    inLine = new QLineEdit(this);
    QVBoxLayout* layout = new QVBoxLayout;
    layout->addWidget(inLine);
    layout->addWidget(act);
    layout->addWidget(outLine);

    connect(inLine,SIGNAL(textChanged(QString)), this,SLOT(autoOut()));
    connect(act,SIGNAL(clicked()), this,SLOT(convert()));

    setLayout(layout);
}

void Widget::autoOut() {
    str = "input: " + inLine->text();
    outLine->setText(str);
}

void Widget::convert() {
    str.append("\nall lower: " + inLine->text().toLower());
    str.append("\nALL UPPER: " + inLine->text().toUpper());
    outLine->setText(str);
}


