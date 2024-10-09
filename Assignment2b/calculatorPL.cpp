/* Danil Stenyashin st128493@student.spbu.ru
Assigment2b_calculator program / reading and calculating expression
*/

int calculatorPL(const std::string& expression){
    std::string str;
    int size_stack = 100; // Set the size of the stack 
    int* stack = new int[size_stack];
    int top = -1; // Pointer to the stack
    
   
    for (int i = 0; i < expression.length(); i++){
        while (isspace(expression[i])) {i++;}
        
        // Add the number
        if (isdigit(expression[i])){
        int number = 0;
            while (isdigit(expression[i])){
                number = number * 10 + (expression[i] - '0');
                i++;
            }
        stack[++top] = number;
        }

        else { 
            if (expression[i] == '+') {
                while (top != 0){
                stack[top - 1] += stack[top];
                top--;
                }
            } else if (expression[i] == '-') {
                while (top != 0){
                stack[top - 1] -= stack[top];
                top--;
                }
            } else if (expression[i] == '*') {
                while (top != 0){
                stack[top - 1] *= stack[top];
                top--;
                }
            } else if (expression[i] == '/') {
                if (stack[top] == 0) {
                    std::cout << "Деление на ноль!" << std::endl;
                    delete[] stack;
                    return 0;
                }
                while (top != 0){
                stack[top - 1] /= stack[top];
                top--;
                }
            }
            i++; 
         }  
    }
    return stack[0];
}

