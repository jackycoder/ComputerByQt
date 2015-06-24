#ifndef UTILITY
#define UTILITY
#include <QString>


const int DEFAULT_MODE = 1;
const int INSERT_MODE = 2;
const int DELETE_MODE = 5;

 /**
  * @brief inToPost: InfixExpression to PostFixExpression
  * @param infixexp
  * @return
  */
 void inToPost(QString &infixexp, vector<QString> &postfixexp);


#endif // UTILITY

