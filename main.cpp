#include "dictionary.h"
#include "stack.h"

Stack<Value> numStack;
Stack<char> opStack;
Dictionary dictionary;
Value number;

// Function that shows operator precedence over the previous stacked operator
bool hasPrecedence(char a , char b) {
    if (a == '*' or a == '/'){
            return true;
    } else if (a == '+' or a == '-') {
        if (b == '*' or b == '/')
            return false;
        else
            return true;
    } else if (a == '=' or a == '(' or a == '$') {
        return false;
    }
    return false;
}

// Top Operation
void doOperation() {
    char op = opStack.pop();
    if (op == '=') {                                                    // This branch serves to add a value to a variable
        Value rhs = numStack.pop();
        Value equal = numStack.pop();

        if (equal.name.empty()){                                       // This if statement checks to see if a name gets popped before a fraction eg, 4=x
            dictionary.add(rhs.name, equal.value);
            numStack.push(equal);
        } else {                                                        // If not, normally adds to dictionary. eg, x=4
            dictionary.add(equal.name, rhs.value);
            numStack.push(rhs);
        }
    } else {                                                            //This branch is used if the operator is one of the 4 arithmetic operations
        Value rhs, lhs, newFraction;
        rhs = numStack.pop();
        lhs = numStack.pop();
        if (op == '+') {
            newFraction.value = lhs.value + rhs.value;
        } else if (op == '-') {
            newFraction.value = lhs.value - rhs.value;
        } else if (op == '*') {
            newFraction.value = lhs.value * rhs.value;
        } else if (op == '/') {
            newFraction.value = lhs.value / rhs.value;
        }
        numStack.push(newFraction);
    }
}

void Evaluate(std::string s) {
   numStack.clear();
   opStack.clear();
   opStack.push('$');
   unsigned int first = 0;

   while (first < s.length()) {
       if (isdigit(s[first])) {
           number.name = "";
           number.value = 0;
           while (isdigit(s[first])) {
               number.value = number.value*10 + s[first] - '0';
               first++;
           }
           numStack.push(number);
       } else if (isalpha(s[first]) or s[first] == '_') {
           number.name  = "";
           number.value = 0;
           while (isalnum(s[first]) or s[first] == '_'){
               number.name += s[first];
               first++;
           }
           try {
               number.value = dictionary.search(number.name);                                           // if name exists in dictionary, update the value to this new value
           } catch (const std::domain_error&) {
               dictionary.add(number.name, number.value);                                               // if not, add name to dictionary with placeholder value
           }
           numStack.push(number);
       } else if (s[first] == '('){
           opStack.push('(');
           first++;
       } else if (s[first] == ')') {
           while (opStack.peek() != '(') {
               doOperation();
           }
           opStack.pop();
           first++;
       } else if (s[first] == '+' or s[first] == '-' or s[first] == '*' or s[first] == '/' or s[first] == '=') {
           bool precedence = hasPrecedence(opStack.peek(), s[first]);
           if (precedence) {
               doOperation();
           }
           opStack.push(s[first]);
           first++;
       } else {
           first++;
       }
   }
   while (opStack.size() != 1 && opStack.size() > 0){
       doOperation();
   }
   Value output = numStack.pop();
   std::cout << "Result: " <<  output.value << std::endl;
}

int main() {

    std::string expression;

    std::cout << "Enter an arithmetic expression. eg. x = 20 * (y = 4): ";
            while (expression != "quit"){
                try {
                    std::getline(std::cin, expression);
                    if (expression == "quit") {
                        break;
                    } else {
                        Evaluate(expression);
                        std::cout << "Enter another expression or type \"quit\" to quit: ";
                    }
                } catch (const std::overflow_error &e) {
                    std::cout << "Overflow Error: " << e.what() << std::endl;
                    std::cout << "You exceeded the amount of variables able to be stored in the dictionary (100)." << std::endl;
                }
            }

    return 0;

}
