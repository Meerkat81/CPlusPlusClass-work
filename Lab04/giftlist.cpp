//
//  main.cpp
//  Lab04
//
//  Created by Casey Meurer on 3/24/20.
//  Copyright © 2020 Casey Meurer. All rights reserved.
//

#include <iostream>
#include <list>
#include <string>
#include <iterator>
#include "Person.h"
int main() {
    std::string entry;
    std::string gift;
    std::list<class person> goodList;
    
    do{
        std::cout << "Name for nice list: ";
        std::getline(std::cin, entry);
       
        if (!entry.empty()){
            class person nicelist;
            nicelist.set_name(entry);
             std::cout << "add gifts for " << entry << "\n";
            do{
                std::cout << "gift: ";
                std::getline(std::cin, gift);
                nicelist.set_items(gift);
            }while(!gift.empty());
            goodList.push_back(nicelist);
        }
    
    
    }while(!entry.empty());
    std::cout << "The list contains" << "\n";
    for(std::list<class person>::iterator it=goodList.begin(); it!=goodList.end(); ++it)
    {
        it->get_name();
        it->get_items();
    }
    return 0;
}
