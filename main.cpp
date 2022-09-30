#include "dictionary.h"
#include "numStack.h"
#include "opStack.h"
#include <sstream>

NumStack nums;
OpStack chars;
Dictionary structure;

void Evaluate(std::string s) {
   nums.clear();
   chars.clear();
   chars.push('$');
   size_t first {1};

   while (first < s.length()) {
       if (isdigit(s[first])) {
           std::stringstream num(s[first]);
           Fraction lhs;
           num >> lhs;
           structure.add(s, lhs);
           nums.push(lhs);
           first++;
       } else if (isalpha(s[first])) {

       } else if (s[first] == '('){
           chars.push(s[first]);
           first++;

       } else if (s[first] == ')') {
           while (chars.peek() != '(') {
               chars.peek();
           }
           chars.pop();
           first++;
       } else if (s[first] == s.find_first_of('+-*/')) {

       } else {
           first++;
       }
   }
   while (chars.size() != '$') {
       chars.peek();
   }
   std::cout << nums.size() << std::endl;

}


int main() {
    std::string s;
    std::cin >> s;

    return 0;
}
