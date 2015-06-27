#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    setReadOnlyForButton();

    connect(ui->digitbutton00 , SIGNAL(clicked()), this, SLOT(getDigitInput()));
    connect(ui->digitbutton01 , SIGNAL(clicked()), this, SLOT(getDigitInput()));
    connect(ui->digitbutton02 , SIGNAL(clicked()), this, SLOT(getDigitInput()));
    connect(ui->digitbutton03 , SIGNAL(clicked()), this, SLOT(getDigitInput()));
    connect(ui->digitbutton04 , SIGNAL(clicked()), this, SLOT(getDigitInput()));
    connect(ui->digitbutton05 , SIGNAL(clicked()), this, SLOT(getDigitInput()));
    connect(ui->digitbutton06 , SIGNAL(clicked()), this, SLOT(getDigitInput()));
    connect(ui->digitbutton07 , SIGNAL(clicked()), this, SLOT(getDigitInput()));
    connect(ui->digitbutton08 , SIGNAL(clicked()), this, SLOT(getDigitInput()));
    connect(ui->digitbutton09 , SIGNAL(clicked()), this, SLOT(getDigitInput()));
    connect(ui->pointbutton , SIGNAL(clicked()), this, SLOT(getDigitInput()));

    connect(ui->operatorbuttonadd , SIGNAL(clicked()) , this, SLOT(getOperatorInput()));
    connect(ui->operatorbuttondivision , SIGNAL(clicked()) , this, SLOT(getOperatorInput()));
    connect(ui->operatorbuttonminus , SIGNAL(clicked()) , this, SLOT(getOperatorInput()));
    connect(ui->operatorbuttonmultiple , SIGNAL(clicked()) , this, SLOT(getOperatorInput()));
    connect(ui->operatorbuttonreminder , SIGNAL(clicked()) , this, SLOT(getOperatorInput()));

    connect(ui->backspacebutton , SIGNAL(clicked()) , this, SLOT(deleteDigitInput()));

    //connect(ui->operatorbuttonsqrt , SIGNAL(clicked()) , this, SLOT(getOperatorInput()));

    connect(ui->operatorbuttonequal , SIGNAL(clicked()) , this , SLOT(getComputeResult()));

}

Widget::~Widget()
{
    delete ui;
}

void Widget::refreshInputLine(QString &expression , int mode)
{
    if(expression.isNull()) return;

    if(DEFAULT_MODE == mode)
    {
       // ui->inputtext->appendPlainText(expression);
    }else if(INSERT_MODE == mode){
        //ui->inputtext->textCursor().insertText(expression);
    }else if(DELETE_MODE == mode)
    {

    }else{

    }
}

void Widget::getDigitInput()
{
    QPushButton *digitbutton = dynamic_cast<QPushButton*>(sender());
    if(digitbutton)
            ui->digitinput->insertPlainText(digitbutton->text());
}

void Widget::deleteDigitInput()
{
    QTextCursor cursor = ui->digitinput->textCursor();
    if(cursor.hasSelection())
        cursor.clearSelection();
    cursor.deletePreviousChar();
}

void Widget::getOperatorInput()
{
    QPushButton *operatorbutton = dynamic_cast<QPushButton*>(sender());
    if(operatorbutton)
    {
        appendSequenceExpression(ui->digitinput->toPlainText());
        appendSequenceExpression(operatorbutton->text());
        ui->expressiontext->setText(getSequenceExpression());
        ui->digitinput->clear();
    }
}

void Widget::setReadOnlyForButton()
{
   //set all the button text read only
}

QString & Widget::getSequenceExpression()
{
    return sequenceExp;
}

void Widget::appendSequenceExpression(const QString &exp)
{
    sequenceExp.append(exp);
}

void Widget::updateSequenceExpression(const QString &exp)
{
    sequenceExp.clear();
    sequenceExp = exp;
}

void Widget::initialTextValues()
{
    ui->digitinput->clear();
    ui->expressiontext->clear();
    sequenceExp.clear();
}

void Widget::getComputeResult()
{
    QVector<QString> vec;
    if(!ui->digitinput->toPlainText().isEmpty())
        appendSequenceExpression(ui->digitinput->toPlainText());
    //qDebug() << "irginal expression:" <<getSequenceExpression();
    inToPost(getSequenceExpression() , vec);
    int result =  computePostfixexpression(vec);
    qDebug() << result;
//    ui->digitinput->clear();
//    ui->expressiontext->clear();
    initialTextValues();
    ui->digitinput->appendPlainText(QString::number(result,10));

}
