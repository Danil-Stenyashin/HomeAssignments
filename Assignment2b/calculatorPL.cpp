/* Danil Stenyashin st128493@student.spbu.ru
Assigment2b_calculator program / reading and calculating expression
*/

int calculatorPL(const std::string& expression){
    std::string str;
    int size_stack = 100; // Set the size of the stack 
    int* stack = new int[size_stack];
    int top = -1; // Pointer to the stack
    
   
    for (size_t i = 0; i < expression.length(); i++){
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
        
        
        // Writing operands
        else { 
            if (expression[i] == '+') {
                while (top != 0){
                stack[top - 1] += stack[top];
                std::cout << stack[top - 1] << std::endl;
                stack[top] = '\0';
                top--;
                }
            } else if (expression[i] == '-') {
                while (top != 1){
                stack[top - 1] += stack[top];
                std::cout << stack[top - 1] << std::endl;
                stack[top] = '\0';
                top--;
                }
                stack[0] = stack[0] - stack[1];
                stack[1] = '\0';
                top--;
            } else if (expression[i] == '*') {
                while (top != 0){
                stack[top - 1] *= stack[top];
                stack[top] = '\0';
                top--;
                }
            } else if (expression[i] == '/') {
                if (stack[top] == 0) {
                    std::cout << "Devision on zero!!" << std::endl;
                    delete[] stack;
                    return 0;
                }
                while (top != 1){
                stack[top - 1] *= stack[top];
                stack[top] = '\0';
                top--;
                }
                stack[0] = stack[0] / stack[1];
                stack[1] = '\0';
                top--;	
            }
            i++;  
         }  
    }
    int result = stack[top];
    
    return result;
    
}

