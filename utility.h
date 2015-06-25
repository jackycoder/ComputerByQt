#ifndef UTILITY
#define UTILITY
#include <QString>
#include <QStack>
#include <QVector>
#include <QDebug>


const int DEFAULT_MODE = 1;
const int INSERT_MODE = 2;
const int DELETE_MODE = 5;

 /**
  * @brief inToPost: InfixExpression to PostFixExpression
  * @param infixexp
  * @return
  */
 bool inToPost(QString &infixexp, QVector<QString> &postfixexp);

 /**
  * @brief handleOperator
  * @param oper
  * @param stack
  * @param postfixexp
  * @return
  */
 bool handleOperator(QChar oper, QStack<QChar> & stack , QVector<QString> & postfixexp);

 /**
  * @brief isHigherPriority: Only support + - * / %
  * @param oper1
  * @param oper2
  * @return
  */
 bool isHigherPriority(const QChar oper1, const QChar oper2);


 bool isoperator(QChar oper);


 void printQVector(QVector<QString> & vec);


#endif // UTILITY

