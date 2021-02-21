#include "mainwindow.h"

Widget::Widget(QWidget *parent) : QWidget(parent) {

    this->resize(200,130);

    outLine = new QLabel;

    act = new QPushButton("Преобразовать!");
    n1 = new QLineEdit;
    n2 = new QLineEdit;
    s1 = new QLineEdit;
    s2 = new QLineEdit;

    QLabel *t1 = new QLabel(tr("N1"));
    QLabel *t2 = new QLabel(tr("N2"));
    QLabel *t3 = new QLabel(tr("S1"));
    QLabel *t4 = new QLabel(tr("S2"));

    QHBoxLayout *l1 = new QHBoxLayout;
    l1->addWidget(t1);
    l1->addWidget(n1);
    l1->addWidget(t2);
    l1->addWidget(n2);
    QHBoxLayout *l2 = new QHBoxLayout;
    l2->addWidget(t3);
    l2->addWidget(s1);
    QHBoxLayout *l3 = new QHBoxLayout;
    l3->addWidget(t4);
    l3->addWidget(s2);

    QVBoxLayout* data = new QVBoxLayout;
    data->addLayout(l1);
    data->addLayout(l2);
    data->addLayout(l3);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(data);
    mainLayout->addWidget(act);
    mainLayout->addWidget(outLine);

    connect(act,SIGNAL(clicked()), this,SLOT(edit()));

    connect(act,SIGNAL(clicked()), this,SLOT(out()));

    setLayout(mainLayout);
}

void Widget::out() {
    outLine->setText(str);
}

void Widget::edit() {
    QString str1;
    QString str2;
    QString str3;
    QString str4;

    str1 = n1->text();
    str2 = n2->text();
    str3 = s1->text();
    str4 = s2->text();

    str3 = str3.left(str1.toInt());
    str4 = str4.right(str2.toInt());

    str = str3 + str4;
}


