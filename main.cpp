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
void Evaluate(std::string s) {
   numStack.clear();
   opStack.clear();
   opStack.push('$');
   unsigned int first = 1;

   while (first < s.length()) {
       if (isdigit(s[first])) {
           std::string digit(1, s[first]);
           std::stringstream num(s[first]);
           Fraction lhs;
           num >> lhs;
           input.string = s[first];
           input.fraction = lhs;
           dictionary.add(input.string, input.fraction);
           numStack.push(lhs);
           while (s[first] != ' ') {
               first++;
           }
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
               opStack.peek();
           }
           opStack.pop();
           first++;
       } else if (s[first] == s.find_first_of('+-*/')) {
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
    return 0;
}
