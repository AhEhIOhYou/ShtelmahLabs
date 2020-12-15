#pragma once
#include <QtWidgets>

class mainWidgetClass: public QWidget {
    Q_OBJECT
private:
    QString sName = "Владимиров";
    QString separator ="";
    QString name = "";
    QString text = "";
    QString mainText;

    QLabel *outputTitle;
    QLabel *outLine;
    QLabel *inputTitle;
    QLineEdit *inLine;

    QRadioButton *sep1;
    QRadioButton *sep2;
    QRadioButton *sep3;
    QRadioButton *noneSep;
    QCheckBox *c_name;

    QPushButton *actButton;
    QPushButton *resetButton;
    QPushButton *exitButton;
public:
    mainWidgetClass(QWidget *parent = 0);
private slots:
    void AddRazdel();
    void AddName();
    void reText();
    void doText();
    void showText();
    void Connections();
    void Styles();
};
