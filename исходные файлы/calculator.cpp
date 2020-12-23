#include "calculator.h"

calculator::calculator(QWidget* pwgt) :QWidget(pwgt) {
    outputLCD = new QLCDNumber(12);
    outputLCD->setSegmentStyle(QLCDNumber::Filled);
    outputLCD->setMinimumSize(150,50);

    QChar doButtons[4][4] = {
        {'7','8','9','/'},
        {'4','5','6','*'},
        {'1','2','3','-'},
        {'0','.','=','+'}
    };
    QGridLayout *mainLayout = new QGridLayout;
    mainLayout ->addWidget(outputLCD, 0, 0, 1, 4);
    mainLayout ->addWidget(defaultButton("CE"), 1, 3);
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            mainLayout ->addWidget(defaultButton(doButtons[i][j]), i + 2, j);
        }
    }
    setWindowTitle("Калькулятор");
    setLayout(mainLayout);
}

QPushButton* calculator::defaultButton(const QString &str) {
    QPushButton* bttn = new QPushButton(str);
    bttn->setMinimumSize(70,40);
    connect(bttn, SIGNAL(clicked()), SLOT(whenClicked()));
    return bttn;
}

void calculator::calculate() {
    qreal fOperand2 = numStk.pop().toFloat();
    QString strOperation = numStk.pop();
    qreal fOperand1 = numStk.pop().toFloat();
    qreal fResult = 0;

    if (strOperation == "+") {
        fResult = fOperand1 + fOperand2;
    }
    if (strOperation == "-") {
        fResult = fOperand1 - fOperand2;
    }
    if (strOperation == "/") {
        fResult = fOperand1 / fOperand2;
    }
    if (strOperation == "*") {
        fResult = fOperand1 * fOperand2;
    }

    outputLCD->display(fResult);
}

void calculator::whenClicked() {
    QString str = ((QPushButton*)sender())->text();

    if (str == "CE") {
        numStk.clear();
        inDataStr = "";
        outputLCD->display("0");
        return;
    }
    if (str.contains(QRegularExpression("[0-9]"))) {
        inDataStr += str;
        outputLCD->display(inDataStr.toDouble());
    }
    else if (str == ".") {
        inDataStr += str;
        outputLCD->display(inDataStr);
    } 
    else {
        if (numStk.count() >= 2) {
            numStk.push(QString().setNum(outputLCD->value()));
            calculate();
            numStk.clear();
            numStk.push(QString().setNum(outputLCD->value()));
            if (str != "=") {
                numStk.push(str);
            }
        }
        else {
            numStk.push(QString().setNum(outputLCD->value()));
            numStk.push(str);
            inDataStr = "";
        }
    }
}
