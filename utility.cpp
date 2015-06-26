#include "utility.h"

/**
* 中序表达式转成后序表达式算法：
*
* 1）当输入的是操作数时，直接输出到后序表达式的序列中
* 2）当输入的是开括号时，把它压栈
* 3）当输入的是闭括号时，先判断栈是否为空，若为空，则发生错误并进行相关处理。若非空，把栈中元素依次弹出并输出到序列中，
*   直到遇到第一个开括号为止，若没有遇到开括号，也即发生错误，进行相关处理
* 4）当输入的是运算符op（+、- 、×、/）时，有两种情况需要处理：
*     a)执行循环，判断当（栈非空and栈顶不是开括号and栈顶运算符的优先级不低于输入的运算符的优先级）时，
*       反复将栈顶元素弹出并添加到序列中
*     b)否则把输入的运算符op压栈
* 5）当中序表达式的符号序列全部读入后，若栈内仍有元素，把它们依次弹出并放到后序表达式序列尾部。
*   若弹出的元素遇到空括号，则说明不匹配，发生错误，并进行相关处理
**/
bool inToPost(QString &infixexp , QVector<QString> &postfixexp)
 {
    if(infixexp.isNull()) return false;
    QString *number = new QString();
    QStack<QChar> stack;
    for(int var = 0; var < infixexp.size(); ++var)
    {
        if(infixexp.at(var)>='0' && infixexp.at(var)<='9'){
            number->append(infixexp.at(var));
            //qDebug() << *number;
        }else if('(' == infixexp.at(var)) {
            stack.push_back(infixexp.at(var));
        }else if (')' == infixexp.at(var)) {
            if(stack.isEmpty()) return false;
            QChar oper;
            while(!stack.isEmpty()){
                oper = stack.pop();
                if(oper != '(')
                    postfixexp.push_back(oper);
            }
        }else if (isoperator(infixexp.at(var))){
            if(!number->isEmpty()){
                postfixexp.push_back(*number);
                number->clear();
            }
            //operator handle
            handleOperator(infixexp.at(var),stack,postfixexp);
        }else{
            //Invalid input
            return false;
        }
    }

    if(!number->isEmpty())
        postfixexp.push_back(*number);

    while (!stack.isEmpty()) {
        QChar element= stack.pop();
        postfixexp.push_back(element);
    }
    return true;
 }


bool handleOperator(QChar oper, QStack<QChar> & stack , QVector<QString> &postfixexp)
{
    QChar topElement;
    while(!stack.isEmpty())
    {
        //popElement = stack.pop();
        topElement=stack.top();
        if(topElement == '(' || !isHigherPriority(oper , topElement)){
            postfixexp.push_back(stack.pop());
        }else{
            break;
        }
    }
    stack.push_back(oper);
    return true;
}


bool isHigherPriority(const QChar oper1, const QChar oper2)
{
    QChar higerOperator[3] = {'*' , '/' , '%'};
    QChar lowerOperator[2] = {'+' , 'c'};
    for (int var = 0; var < 3; ++var) {
        if(oper1 == higerOperator[var]){
            for (int i = 0; i < 2; ++i) {
                if(oper2 == lowerOperator[i]){
                    return true;
                }
            }
        }
    }
    return false;
}

bool isoperator(QChar oper)
{
    QChar operatorList[5] = {'+','-','*','/','%'};
    for (int var = 0; var < 5; ++var) {
         if(oper == operatorList[var])
             return true;
    }
    return false;
}

 void printQVector(QVector<QString> & vec)
 {
     QVector<QString>::iterator it_string = vec.begin();
     qDebug() << QString("postfixexpression size:") << vec.size();
     while(it_string != vec.end()){
         qDebug() << *it_string;
         it_string++;
     }

 }
