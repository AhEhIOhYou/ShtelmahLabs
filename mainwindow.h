#pragma once
#include <QMainWindow>
#include <QtWidgets>
#include <QKeyEvent>

class Widget : public QWidget
{
    Q_OBJECT
public:
    explicit Widget(QWidget *parent = 0);
public slots:
    void itemClicked(int row, int column);
    void matrixF();
private:
    QString str;
    QLabel *pos_c;
    QLabel *pos_r;
    QLabel *la_2;
    QLabel *la_3;
    QLabel *number;

    QPushButton *act;
    QLineEdit *inLine;
    QTableWidget *matrix;
protected:
   virtual void keyPressEvent(QKeyEvent *event);
};
