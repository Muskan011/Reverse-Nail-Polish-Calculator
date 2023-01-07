Name: MUSKAN KUMAR
For part 1: I created a vector of doubles and then used push_back and pop_back functions to evalute the postfix notation.
            Additionally, I took care of some error such as: Division by 0, 0^0, root of negative numbers, insufficient number of operands, and insufficient number of operators.
For part 2: I first convert the postfix notation into prefix notation with brackets and spaces then I used https://www.geeksforgeeks.org/program-to-parse-a-comma-separated-string-in-c/
            for breaking the string at the spaces and stored it within a vector of strings.
            Then I used the strings to one by one put indentation as required and print the final output.
1) To change input the string test has to be changed in rpn.cpp
2) -l option has to be entered as user input
3) On error stdout prints error and return -1
4) Everytime there are more operators or operands the calculator errors and returns -1
5) 0^0 results in an error
6) root of negative numbers results in and error
7) When program is run with -l option the output of both part1 and part 2 will be displayed



Citations:
https://www.geeksforgeeks.org/program-to-parse-a-comma-separated-string-in-c/
https://en.wikipedia.org/wiki/Reverse_Polish_notation
https://www.cplusplus.com/reference/string/stof/
https://www.geeksforgeeks.org/vector-in-cpp-stl/
https://www.cplusplus.com/reference/vector/vector/
https://www.free-online-calculator-use.com/postfix-evaluator.html#calculator-start

Compile using:
    g++ -Wall rpn.cpp
Run using:
    ./a.out
    then choose -l/none
Note: to change string test[] update test in rpn.cpp and when -l is choosen the answers to both part 1 and 2 will be printed.
