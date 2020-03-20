//
//  main.cpp
//  Lab03
//
//  Created by Casey Meurer on 3/5/20.
//  Copyright © 2020 Casey Meurer. All rights reserved.
//

#include <iostream>
#include <string>
#include "LinkedStacked.h"

int postFixEval(std::string testString)
{
    int intForPush = 0;
    int result = 0;
    LinkedStack<int>* LSTest = nullptr;
    LSTest = new LinkedStack<int>();
    
    for(int i = 0; i < testString.size(); i++)
        if(isdigit(testString[i]))
        {
            intForPush = testString[i] - '0';
            LSTest->push(intForPush);
        }else{
            int operand1;
            int operand2;
            operand2 = LSTest->peek();
            LSTest->pop();
            operand1 = LSTest->peek();
            LSTest->pop();
            
            switch(testString[i]){
                case '-':
                    result = operand1 - operand2;
                    break;
                case '+':
                    result = operand1 + operand2;
                    break;
                case '*':
                    result = operand1 * operand2;
                    break;
                case '/':
                    result = operand1 / operand2;
                    break;
                }
            LSTest->push(result);
            }
    LSTest->pop();
    return result;
}

int main(int argc, const char * argv[]) {
    std::string test;
    std::cout << "postfix equation> ";
    std::getline(std::cin, test);
    do {
        std::cout << postFixEval(test) << "\n";
        std::cout << "postfix equation> ";
        std::getline(std::cin, test);
    } while (!test.empty());
    return 0;
}
