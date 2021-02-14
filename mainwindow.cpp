#include "mainwindow.h"

#include "mainwindow.h"

Widget::Widget(QWidget *parent) : QWidget(parent) {

    //рейсаз окна виджета
    this->resize(1150,370);
    
    //создаю площадку для таблицы, предопределяя 10x10 ячеек
    matrix = new QTableWidget(10,10,this);
    
    //выставляю размер и положение
    matrix->setGeometry(0,0, 1100, 370);
    
    //создаю ячейки и заполняю случ числами
    matrixF();
    
    //кнопочка для смены чисел
    act = new QPushButton("Сменить числа");
    
    //выводимые данные о ячейке
    pos_c = new QLabel;
    pos_r = new QLabel;
    number = new QLabel;
    la_2 = new QLabel;
    la_3 = new QLabel;
    
    //структурирую в лейаут окна выводимой информации
    QVBoxLayout* infoLabels = new QVBoxLayout;
    infoLabels->addWidget(act);
    infoLabels->addWidget(pos_c);
    infoLabels->addWidget(pos_r);
    infoLabels->addWidget(number);
    infoLabels->addWidget(la_2);
    infoLabels->addWidget(la_3);

    //собираю таблицу и инфолейблы в структуру
    QHBoxLayout* layout = new QHBoxLayout;
    layout->addWidget(matrix);
    layout->addLayout(infoLabels);
    
    //устанавливаю стили
    setLayout(layout);
    
    //Соединяю кнопку смены чисел и пересоздание ячеек
    connect(act,SIGNAL(clicked()), this,SLOT(matrixF()));
    //Соединяю клик по ячейки и вывод информации о ячейке
    connect(matrix, SIGNAL(cellClicked(int, int)), SLOT(itemClicked(int, int)));
    
}

void Widget::matrixF() {
    
    //пробегаемся по всем координатам таблицы
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            //создаю ячейку
            QTableWidgetItem *item = new QTableWidgetItem();
            
            //ставлю флаг на запрет редактированию
            item->setFlags(item->flags() & ~(Qt::ItemIsEditable));
            
            //случайное значения в ячейку
            int n = rand()% 20;
            QString s = QString::number(n);
            item->setText(s);
            
            //ТулТип для вывода значения по наведению мыши
            item->setToolTip(s);
            
            //закидываю в матрицу ячейку по адрессу i, j
            matrix->setItem(i,j,item);
        }
    }
    
}


void Widget::itemClicked(int column, int row) {
    
    //ячейка для обработки
    QTableWidgetItem *item = new QTableWidgetItem;
    
    //получаю в неё данные нажатой ячейки
    item = matrix->item(column,row);

    //вычисляю порядковый номер числа
    int num = column * 10 + row + 1;
    
    //вывожу очевидное
    pos_c->setText("Строка: " + QString::number(column + 1));
    pos_r->setText("Колонка: " + QString::number(row + 1));
    number->setText("Номер: " + QString::number(num));

    //Далее считаю квадрат и куб и тоже вывожу
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
    
    //горячая клавиша для заполнения новыми числами
    if (event->key() == Qt::Key_Shift) {
        matrixF();
    }
    
}

