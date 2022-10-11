#include "dictionary.h"
#include "stack.h"
#include <sstream>
#include <cstring>

Stack<Input> numStack;
Stack<char> opStack;
Dictionary dictionary;


bool Precedence(char a , char b) {
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

void Operation() {
    char op = opStack.pop();
    if (op == '=') {
        Input rhs = numStack.pop();
        Input equal = numStack.pop();
        dictionary.add(equal.string,rhs.fraction);
        numStack.push(rhs);
    } else {
        Input rhs, lhs, newFraction;
        rhs = numStack.pop();
        lhs = numStack.pop();
        if (op == '+') {
            newFraction.fraction = lhs.fraction + rhs.fraction;
        } else if (op == '-') {
            newFraction.fraction = lhs.fraction - rhs.fraction;
        } else if (op == '*') {
            newFraction.fraction = lhs.fraction * rhs.fraction;
        } else if (op == '/') {
            newFraction.fraction = lhs.fraction / rhs.fraction;
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
           Input fraction;
           std::stringstream ss;
           Fraction num;
           int temp;
           std::string str;
           if (s[first] != ' ') {
               while (s[first] != ' ' && s[first] != ')'){
                   if (s[first] == '+' or s[first] == '-' or s[first] == '*' or s[first] == '/' or s[first] == '=' or s[first] == '\0') {
                       break;
                   } else {
                       str += s[first];
                       first++;
                   }
               }
           } else {
               str = s[first];
               first++;
           }

           ss << str;
           ss >> temp;
           num = temp;
           fraction.fraction = num;
           fraction.string = str;
           numStack.push(fraction);
       } else if (isalpha(s[first])) {
           Input name;
           if (s[first] != ' ') {
               while (s[first] != ' ' && s[first] != ')') {
                   if (s[first] == '+' or s[first] == '-' or s[first] == '*' or s[first] == '/' or s[first] == '=' or s[first] == '\0') {
                       break;
                   } else {
                       name.string += s[first];
                       first++;
                   }
               }
           } else {
               name.string = s[first];
               first++;
               }
           if (dictionary.contains(name.string)) {
               name.fraction = dictionary.search(name.string);
           } else {
               dictionary.add(name.string, name.fraction);
           }
           numStack.push(name);
       } else if (s[first] == '('){
           opStack.push('(');
           first++;
       } else if (s[first] == ')') {
           while (opStack.peek() != '(') {
               Operation();
           }
           opStack.pop();
           first++;
       } else if (s[first] == '+' or s[first] == '-' or s[first] == '*' or s[first] == '/' or s[first] == '=') {
           bool precedence = Precedence(opStack.peek(), s[first]);
           if (precedence) {
               Operation();
           }
           opStack.push(s[first]);
           first++;
       } else {
           first++;
       }
   }
   while (opStack.size() != 1){
       Operation();
   }
   Input output = numStack.pop();
   std::cout << output.fraction << std::endl;
}


int main() {
    int variableCount, numExpressions;
    std::string expression;
        std::cout << "Please enter how many expressions you wish to answer: ";
        std:: cin >> numExpressions;
            for (size_t i = 0; i < numExpressions; i++) {
                try {
                    std::getline(std::cin >> std::ws, expression);
                    Evaluate(expression);
                } catch (const std::overflow_error &e) {
                    std::cout << "You exceeded the amount of variables able to be stored in the dictionary (100)." << std::endl;
                    std::cout << " Overflow Error: " << e.what() << std::endl;
                }

            }


    return 0;

}
