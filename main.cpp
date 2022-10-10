#include "dictionary.h"
#include "stack.h"
#include <sstream>

Stack<Fraction> numStack;
Stack<char> opStack;
Dictionary dictionary;
Input input;


bool Precedence(char a , char b) {
    if (a == '*' or a == '/'){
        if (b == '*' or b == '/')
            return true;
        else if ( b == '+' or b == '-')
            return true;
        else if (b == '=')
            return true;
    } else if (a == '+' or a == '-') {
        if (b == '*' or b == '/')
            return false;
        else if (b == '+' or b == '-')
            return true;
        else if (b == '=')
            return true;
    } else if (a == '=' or a == '(' or a == '$') {
        if (b == '*' or b == '/')
            return false;
        else if (b == '+' or b == '-')
            return false;
        else if (b == '=')
            return false;
    }
    return false;
}

void Operation() {
    char op = opStack.pop();
    Fraction rhs = numStack.pop();
    Fraction lhs = numStack.pop();
    Fraction newFraction;
    if (op == '=') {
        char otherOp = opStack.pop();
        if (otherOp == '+') {
            newFraction = rhs + lhs;
        } else if (otherOp == '-') {
            newFraction = rhs - lhs;
        } else if (otherOp == '*') {
            newFraction = rhs * lhs;
        } else if (otherOp == '/') {
            newFraction = rhs / lhs;
        }
        dictionary.add(input.string, newFraction);
    } else if (op == '+') {
        newFraction = rhs + lhs;
    } else if (op == '-'){
        newFraction = rhs - lhs;
    } else if (op == '*'){
        newFraction = rhs * lhs;
    } else if (op == '/' ) {
        newFraction = lhs / rhs;
    }
    numStack.push(newFraction);
}

void Evaluate(std::string s) {
   numStack.clear();
   opStack.clear();
   opStack.push('$');
   unsigned int first = 0;

   while (first < s.length()) {
       if (isdigit(s[first])) {
           std::stringstream ss;
           Fraction lhs;
           int temp = 0;
           while (s[first] != ' ') {
               if (first == s.length() - 1) {
                   ss << s[first];
                   first++;
                   break;
               }else{
                   ss << s[first];
                   first++;
               }

           }
           ss >> temp;
           lhs = temp;
           numStack.push(lhs);
       } else if (isalpha(s[first])) {
           std::string name;
           while (s[first] != ' ') {
               name += s[first];
               first++;
           }
           input.string = name;
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
   std::cout << numStack.pop() << std::endl;
}

int main() {
    std::string String = "10 * 5 + 4";
    Evaluate(String);
    return 0;

}
