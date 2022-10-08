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
}

void Operation() {
    char op = opStack.pop();
    input.fraction = numStack.pop();
    if (op == '=') {
            dictionary.add(input.string, input.fraction);
    } else if (op == '+' or op == '-' or op == '*' or op == '/' ) {

    }
}

void Evaluate(std::string s) {
   numStack.clear();
   opStack.clear();
   opStack.push('$');
   unsigned int first = 1;

   while (first < s.length()) {
       if (isdigit(s[first])) {
           std::string digit(1, s[first]);
           std::stringstream num(digit);
           Fraction lhs;
           num >> lhs;
           input.string = s[first];
           input.fraction = lhs;
           dictionary.add(input.string, input.fraction);
           numStack.push(lhs);
           first++;
       } else if (isalpha(s[first])) {
           std::string name;
           while (s[first] != ' ') {
               name += s[first];
               first++;
           }
           input.string = name;
           dictionary.add(input.string, input.fraction);
       } else if (s[first] == '('){
           opStack.push(s[first]);
           first++;

       } else if (s[first] == ')') {
           while (opStack.peek() != '(') {
               opStack.pop();
           }
           opStack.pop();
           first++;
       } else if (s[first] == '+' or s[first] == '-' or s[first] == '*' or s[first] == '/') {
           bool precedence = Precedence(opStack.pop(), s[first]);
           while (precedence) {
               opStack.peek();
           }
           opStack.push(s[first]);
           first++;
       } else {
           first++;
       }
   }
   while (opStack.size() != '$') {
       opStack.peek();
   }
   std::cout << numStack.size() << std::endl;
}

int main() {
    std::string String = "(4 + 5) * 4";
    Evaluate(String);
    return 0;

}
