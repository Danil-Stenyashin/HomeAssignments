/* Danil Stenyashin st128493@student.spbu.ru
Assigment2b_calculator program / main
*/


#include "head.h"
#include "calculatorPL.cpp"
 
int main() 
{
    std::string expression;
    std::cout << "Input your expression in reverse Polish entry: ";
    getline(std::cin, expression);
    
    int result = calculatorPL(expression);
    std::cout << "Your result: " << result << std::endl;
    return 0;
}


