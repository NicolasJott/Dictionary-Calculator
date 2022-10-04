#include "dictionary.h"
#include "numStack.h"
#include "opStack.h"
#include <sstream>
#include <map>

NumStack nums;
OpStack chars;
Dictionary dictionary;
std::map<std::string, Fraction> structure;

void Evaluate(std::string s) {
   nums.clear();
   chars.clear();
   chars.push('$');
   unsigned int first = 1;

   while (first < s.length()) {
       if (isdigit(s[first])) {
           std::string digit(1, s[first]);
           std::stringstream num(s[first]);
           Fraction lhs;
           num >> lhs;
           structure.insert({digit, lhs});
           nums.push(lhs);
           first++;
       } else if (isalpha(s[first])) {
           std::string name(1, s[first]);
           std::stringstream num(s[first]);
           Fraction lhs;
           num >> lhs;
           structure.insert({name, lhs});
           nums.push(lhs);
           first++;

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
    std::string s = "4 + 5";
    Evaluate(s);
    return 0;
}
