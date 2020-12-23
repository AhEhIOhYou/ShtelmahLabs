#include "calculator.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    calculator calc;
    calc.resize(250,300);
    calc.show();
    return a.exec();
}
