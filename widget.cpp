#include "widget.h"
using namespace Qt;

mainWidgetClass::mainWidgetClass(QWidget *parent):QWidget(parent)
{
    inputTitle = new QLabel(tr("&Текст"));
    inLine = new QLineEdit;
    inputTitle->setBuddy(inLine);
    QVBoxLayout *in = new QVBoxLayout();
    in->addWidget(inputTitle);
    in->addWidget(inLine);

    outLine = new QLabel;
    outputTitle = new QLabel(tr("Вывод"));
    QVBoxLayout *out = new QVBoxLayout();
    out->addWidget(outputTitle);
    out->addWidget(outLine);

    //инициализация чекбокса имени и радиокнопок разделителей
    c_name = new QCheckBox(tr("&Добавить имя"));
    sep1 = new QRadioButton(tr("&---"));
    sep2 = new QRadioButton(tr("&***"));
    sep3 = new QRadioButton(tr("&==="));
    noneSep = new QRadioButton(tr("&Без"));
    noneSep->setChecked(true);

    //группа флагов
    QVBoxLayout *flags = new QVBoxLayout;
    flags->setSpacing(5);
    flags->addWidget(sep1);
    flags->addWidget(sep2);
    flags->addWidget(sep3);
    flags->addWidget(noneSep);
    flags->addWidget(c_name);

    //расстановка группы флагов
    QGroupBox *fbox = new QGroupBox(tr("&Выбери разделитель"));
    fbox->setLayout(flags);
    fbox->setFixedSize(400,300);

    //инициализация всех остальных кнопок
    actButton = new QPushButton(tr("&Ввод"));
    resetButton = new QPushButton(tr("&Сброс"));
    exitButton = new QPushButton(tr("&Выход"));


    QVBoxLayout *bbox = new QVBoxLayout;
    bbox->addWidget(actButton);
    bbox->addWidget(resetButton);
    bbox->addWidget(exitButton);

    QHBoxLayout *lineLayout = new QHBoxLayout;
    lineLayout->addWidget(inputTitle);
    lineLayout->addWidget(inLine);

    QHBoxLayout *activeLayout = new QHBoxLayout;
    activeLayout->addWidget(fbox);
    activeLayout->addLayout(bbox);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(in);
    mainLayout->addLayout(activeLayout);
    mainLayout->addLayout(out);

    setLayout(mainLayout);

    Connections();

    Styles();

}
//основная логика
void mainWidgetClass::doText() {
    mainText = sName;
    if (inLine->text() != "") {
        mainText = mainText + separator + name + "(" + inLine->text() + ")";
    } else {
        mainText = mainText + separator + name;
    }
}

void mainWidgetClass::showText() {
    outLine->setText(mainText);
}

void mainWidgetClass::reText() {
    mainText = "";
    noneSep->setChecked(true);
    separator = "";
    c_name->setChecked(false);
    name = "";
    inLine->clear();
    outLine->clear();
}

void mainWidgetClass::AddRazdel() {
    if(sep1->isChecked()) {
        separator = "---";
    } else if (sep2->isChecked()) {
            separator = "***";
    } else if (sep3->isChecked()) {
        separator = "===";
    } else if (noneSep->isChecked()) {
        separator = "";
    }
}

void mainWidgetClass::AddName() {
    if(c_name->isChecked() == true) {
        name = "Дима";
    } else {
        name = "";
    }
}

//все связи
void mainWidgetClass::Connections() {
    connect(sep1, SIGNAL(clicked()), SLOT(AddRazdel()));
    connect(sep2, SIGNAL(clicked()), SLOT(AddRazdel()));
    connect(sep3, SIGNAL(clicked()), SLOT(AddRazdel()));
    connect(noneSep, SIGNAL(clicked()), SLOT(AddRazdel()));
    connect(c_name,SIGNAL(clicked()), SLOT(AddName()));
    connect(actButton,SIGNAL(clicked()), SLOT(doText()));
    connect(actButton,SIGNAL(clicked()), SLOT(showText()));
    connect(resetButton, SIGNAL(clicked()), SLOT(reText()));
    connect(exitButton, SIGNAL(clicked()), qApp, SLOT(closeAllWindows()));
}

//все кастомные штучки для красоты и эстетичности
void mainWidgetClass::Styles() {
    sep1->setCursor(PointingHandCursor);
    sep2->setCursor(PointingHandCursor);
    sep3->setCursor(PointingHandCursor);
    noneSep->setCursor(PointingHandCursor);
    c_name->setCursor(PointingHandCursor);
    actButton->setCursor(PointingHandCursor);
    resetButton->setCursor(PointingHandCursor);
    exitButton->setCursor(PointingHandCursor);

    inLine->setFixedHeight(30);
    inputTitle->setFixedHeight(30);
    outLine->setFixedHeight(40);
    outLine->setFrameStyle(QFrame::Box | QFrame::Raised);
    outputTitle->setFixedHeight(30);

    actButton->setFixedSize(100,50);
    resetButton->setFixedSize(100,50);
    exitButton->setFixedSize(100,50);
}
