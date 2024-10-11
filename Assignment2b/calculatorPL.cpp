/* Danil Stenyashin st128493@student.spbu.ru
Assigment2b_calculator program / reading and calculating expression
*/

int calculatorPL(const std::string& expression){
    std::string str;
    int size_stack = 100; // Set the size of the stack 
    int* stack = new int[size_stack];
    int top = -1; // Pointer to the stack
    
   
   // Sorting through the char
    for (size_t i = 0; i < expression.length(); i++){
        while (isspace(expression[i])) {i++;}
        
        // Add the number
        if (isdigit(expression[i])){
        int number = 0;
            while (isdigit(expression[i])){
                number = number * 10 + (expression[i] - '0');
                i++;
            }
        stack[++top] = number; // Add the number in the top of the stack
        
        }
        
        
        // Writing operands
        //The loop changes each previos stack and reaches the 0 element of the stack
        else { 
            if (expression[i] == '+') {
                while (top != 0){
                stack[top - 1] += stack[top];
                top--;
                }
                
            } else if (expression[i] == '-') {   // The loop first performs operations on numbers, then writes an element to 0
                while (top != 1){
                stack[top - 1] += stack[top];
                top--;
                }
                stack[0] -= stack[1];
                top--;
                
            } else if (expression[i] == '*') {
                while (top != 0){
                stack[top - 1] *= stack[top];
                top--;
                }
                
            } else if (expression[i] == '/') {  //This part check if you devision by zero
                if (stack[top] == 0) {
                    std::cout << "Devision by zero!!" << std::endl;
                    delete[] stack; // Clean a stack
                    return 0;
                }
                
                while (top != 1){ // The loop first performs operations on numbers, then writes an element to 0
                stack[top - 1] *= stack[top];
                top--;
                }
                stack[0] /= stack[1];
                top--;	
            }
            i++;  
         }  
    }
    int result = stack[top]; // The result is on the top of the stack
    delete[] stack; // Clean a stack
    return result; // Return result to main
    
}

