#include "dictionary.h"
#include "stack.h"
#include <sstream>

Stack<Fraction> numStack;
Stack<char> opStack;
Dictionary dictionary;
Input input;


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
        input.fraction = numStack.pop();
        dictionary.add(input.string,input.fraction);
    } else {
        Input rhs, lhs;
        rhs.fraction = numStack.pop();
        lhs.fraction = numStack.pop();
        Fraction newFraction;
        if (op == '+') {
            newFraction = rhs.fraction + lhs.fraction;
        } else if (op == '-') {
            newFraction = rhs.fraction - lhs.fraction;
        } else if (op == '*') {
            newFraction = rhs.fraction * lhs.fraction;
        } else if (op == '/') {
            newFraction = lhs.fraction / rhs.fraction;
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
           std::stringstream ss;
           Fraction lhs;
           int temp = 0;
           while (s[first] != ' ') {
               if (s[first] == ')'){
                   break;
               } else if (first == s.length() - 1) {
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
           dictionary.add(input.string, input.fraction);
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
   if (numStack.isEmpty()){
       Fraction var = dictionary.search(input.string);
       std::cout << input.string << " = " << var << std::endl;
   } else {
       std::cout << numStack.pop() << std::endl;
   }


}

int main() {
    std::string String = " randomVariable = 5 * 4 + 6";
    Evaluate(String);
    return 0;

}
