//
//  main.cpp
//  Lab02
//
//  Created by Casey Meurer on 2/16/20.
//  Copyright © 2020 Casey Meurer. All rights reserved.
//
#include "LinkedChar.h"
#include <iostream>
#include <string>
int main() {
    int menuSelection;
    LinkedChar<char>* lab02 = nullptr;
    LinkedChar<char>* appstr = nullptr;
    std::string testString;
    char charTest;
    bool menu = true;
    
    //Prime read
    std::cout << "enter string: ";
    std::getline(std::cin,testString);
    lab02 = new LinkedChar<char>(testString);
   
    while(menu){
        std::cout << "\nSelect from the following: \n";
        std::cout << "Enter new string   :\t1\n";
        std::cout << "Get current length :\t2\n";
        std::cout << "Find index of char :\t3\n";
        std::cout << "Append             :\t4\n";
        std::cout << "SubMatch Test      :\t5\n";
        std::cout << "Quit               :\t6\n";
        std::cout << "Enter Selection: ";
        std::cin  >> menuSelection;
        switch (menuSelection) {
            case 1:{
                std::cout << "Enter a string to store in linked list:";
                std::getline(std::cin.ignore(), testString);
                lab02 = new LinkedChar<char> (testString);
                }
                break;
            case 2:
                std::cout <<"\n" << lab02->getCurrentSize() << "\n";
                
                break;
            case 3:
                std::cout << "Enter a char for index: \n";
                std::cin >> charTest;
                std::cout << lab02->index(charTest) << "\n";
                
                break;
           case 4:
            {
                std::cout << "Enter append string:";
                std::cin.ignore();
                std::getline(std::cin, testString);
                appstr = new LinkedChar<char>(testString);
                lab02->append(*appstr);
            }
                break;
            case 5:
            {
                std::cout << "Enter submatch string:";
                std::cin.ignore();
                std::getline(std::cin.ignore(), testString);
                appstr = new LinkedChar<char>(testString);
                std::cout << lab02->submatch(*appstr) << "\n";
            }
            case 6:
            {
                menu = false;
            }
                break;
            default:
                std::cout << "Please enter a valid selection";
                break;
        }
    }
    return 0;
}

