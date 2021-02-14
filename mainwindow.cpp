#include "mainwindow.h"

#include "mainwindow.h"

Widget::Widget(QWidget *parent) : QWidget(parent) {

    this->resize(1150,370);

    matrix = new QTableWidget(10,10,this);


    matrixF();

    matrix->setGeometry(0,0, 1100, 370);

    act = new QPushButton("Сменить числа");

    pos_c = new QLabel;
    pos_r = new QLabel;
    number = new QLabel;
    la_2 = new QLabel;
    la_3 = new QLabel;

    QVBoxLayout* infoLabels = new QVBoxLayout;
    infoLabels->addWidget(act);
    infoLabels->addWidget(pos_c);
    infoLabels->addWidget(pos_r);
    infoLabels->addWidget(number);
    infoLabels->addWidget(la_2);
    infoLabels->addWidget(la_3);

    QHBoxLayout* layout = new QHBoxLayout;
    layout->addWidget(matrix);
    layout->addLayout(infoLabels);

    connect(act,SIGNAL(clicked()), this,SLOT(matrixF()));
   // connect(matrix, SIGNAL(cellClicked(int, int)), SLOT(itemClicked(int, int)));
    setLayout(layout);
}

void Widget::matrixF() {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            QTableWidgetItem *item = new QTableWidgetItem();
            item->setFlags(item->flags() & ~(Qt::ItemIsEditable));
            int n = rand()% 20;
            QString s = QString::number(n);
            item->setText(s);
            item->setToolTip(s);
            matrix->setItem(i,j,item);
        }
    }
}


void Widget::itemClicked(int column, int row)
{
    QTableWidgetItem *item = new QTableWidgetItem;
    item = matrix->item(column,row);

    int num = column * 10 + row + 1;

    pos_c->setText("Строка: " + QString::number(column + 1));
    pos_r->setText("Колонка: " + QString::number(row + 1));
    number->setText("Номер: " + QString::number(num));

    QString data = item->text();

    int x = data.toInt();
    int y = x;
    x = x*x;
    QString s = QString::number(x);

    la_2->setText("Квдрат: " + QString::number(x));

    x = x*y;
    s = QString::number(x);

    la_3->setText("Куб: " + QString::number(x));

}

void Widget::keyPressEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_Shift) {
        matrixF();
    }
    while (event->key() == Qt::Key_Control && matrix->isActiveWindow()) {
        connect(matrix, SIGNAL(cellClicked(int, int)), SLOT(itemClicked(int, int)));
    }

}

