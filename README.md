# Dictionary Calculator
This program functions as a calculator that takes input as full mathematical expressions using the 4 basic arithmetic operators (+-*/).
## Consider the following
This program is able to process a sequence of valid arithmetic expressions that include the following:
<ul>
  <li>All numbers are non-negative integers</li>
  <li>The four basic arithmetic operations</li>
  <li>Parenthesis</li>
  <li>Variable names, up to 100 variables; follow the c++ naming rules</li>
  <li>Assignment in the form var = expression; note that the assignment is also an operator; its "result" is the expression on the right side of the =.</li>
</ul>
For each expression, the calculator evaluates it, displays the result and store the result in the appropriate variable, if necessary.

### Example 
<pre>
Input
x = 20 + (y=3)
Output
23 / 1
</pre>

### Example
<pre>
Input
x = 17
Output 
17 / 1

Input
y = 2
Output
2 / 1

Input
x / y
Output
17 / 2
</pre>

### Example
<pre>
Input
z = 18 - (2 * 3)
Output
12 / 1
</pre>
