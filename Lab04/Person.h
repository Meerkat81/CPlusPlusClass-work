//
//  person.h
//  Lab04
//
//  Created by Casey Meurer on 3/24/20.
//  Copyright © 2020 Casey Meurer. All rights reserved.
//

#ifndef person_h
#define person_h
#include <list>
#include <string>
class person
{
private:
    std::string name;
    std::list<std::string> test;

public:
    void set_name(std::string);
    void set_items(std::string);
    void get_name();
    void get_items();
};

void person::set_name(std::string persons_name){
    name = persons_name;
}


void person::set_items(std::string item){
    this->test.push_back(item);
}

void person::get_name(){
    std::cout << name << " :";
}

void person::get_items(){
    
    for(std::list<std::string>::iterator it=this->test.begin(); it != this->test.end();++it)
        std::cout << *it <<' ';
    
    std::cout << "\n";
}
    
#endif /* person_h */
