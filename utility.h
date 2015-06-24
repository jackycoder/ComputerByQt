#ifndef UTILITY
#define UTILITY
#include <QString>
#include <QStack>


const int DEFAULT_MODE = 1;
const int INSERT_MODE = 2;
const int DELETE_MODE = 5;

 /**
  * @brief inToPost: InfixExpression to PostFixExpression
  * @param infixexp
  * @return
  */
 bool inToPost(QString &infixexp, vector<QString> &postfixexp);

 bool handleOperator(char oper, QStack<char> & stack , vector<Qstring> & postfixexp);


#endif // UTILITY

