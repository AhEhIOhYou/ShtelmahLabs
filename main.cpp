#include "widget.h"
#include <QApplication>

int main(int argc, char *argv[])
{

    QApplication app(argc, argv);

    QFont newFont("Playtime Cyrillic", 12,75,false);
    app.setFont(newFont);
    QPalette pall;
    pall.setColor(QPalette::Window, Qt::white);
    app.setPalette(pall);

    mainWidgetClass thisIsMainWidget;
    thisIsMainWidget.resize(800,510);

    thisIsMainWidget.show();

    return app.exec();
}
