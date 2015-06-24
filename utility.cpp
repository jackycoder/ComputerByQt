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
bool inToPost(QString &infixexp , vector<QString> &postfixexp)
 {
    if(infixexp.isNull()) return ;
    QString *number = new QString();
    QStack<char> stack;
    for(int var = 0; var < infixexp.size(); ++var)
    {
        if(infixexp.at(var)>='0' && infixexp.at(var)<='9'){
            number->append(infixexp.at(var));
        }else if('(' == infixexp.at(var)) {
            stack.push_back(infixexp.at(var));
        }else if (')' == infixexp.at(var)) {
            if(stack.isEmpty()) return false;
            char oper;
            while(!stack.isEmpty()){
                oper = stack.pop();
                if(oper != '(')
                    postfixexp.push_back(oper);
            }
        }else if (isoperator(infixexp.at(var))){
            if(!number->isEmpty()){
                postfixexp.push(*number);
                number->clear();
            }
            //operator handle

        }else{
            //Invalid input
            return false;
        }
    }
    return true;
 }


bool handleOperator(char oper, QStack<char> & stack , vector<Qstring> & postfixexp)
{
    while(!stack.isEmpty())
    {

    }
}
