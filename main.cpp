#include "dictionary.h"
#include "numStack.h"
#include "opStack.h"
#include <sstream>

NumStack nums;
OpStack chars;

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
           nums.push(lhs);
           first++;
       } else if (isalpha(s[first])) {

       } else if (s[first] == s.find('(')){
           chars.push(s[first]);
           first++;

       } else if (s[first] == s.find(')')) {
           while (chars.size() != '(') {

           }
       } else if (s[first] == s.find_first_of('+-*/')) {

       } else {
           first++;
       }
   }

}


int main() {
    std::string s;
    std::cin >> s;

    return 0;
}
