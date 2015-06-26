#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <iostream>
#include "utility.h"

using namespace std;

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();


private slots:
    //void appendExpression(QString substring);
    //void updateExpression(QString expression);//update the expression
    void refreshInputLine(QString &expression , int mode = DEFAULT_MODE);//display in the text line
    void getDigitInput();
    void getOperatorInput();
    void deleteDigitInput();
    void getComputeResult();

private:
    void setReadOnlyForButton();
    QString& getSequenceExpression() ;
    void appendSequenceExpression(const QString &exp);
    void updateSequenceExpression(const QString &exp);

private:
    Ui::Widget *ui;
    QString sequenceExp;
};

#endif // WIDGET_H
