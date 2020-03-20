//
//  LinkedChar.h
//  DataStructures
//
//  Created by Casey Meurer on 2/17/20.
//  Copyright © 2020 Casey Meurer. All rights reserved.
//

#ifndef LinkedChar_h
#define LinkedChar_h


#include "Node.h"
#include <string>
#include <iostream>

template<class ItemType>
class LinkedChar
{
private:
    Node<ItemType>* headptr;            //points to first node
    int itemCount = 0;
    int length() const;                 //Current count of
    

public:
    LinkedChar();
    LinkedChar(const std::string s);
    void add(char item);
    int index(char ch) const;   //-1 if no match
    void append(const LinkedChar& lc);
    int  getCurrentSize();
    bool submatch(const LinkedChar& lc)const;
};

template<class ItemType>
LinkedChar<ItemType>::LinkedChar():headptr(nullptr)
{
}//end default constructor

template<class ItemType>
LinkedChar<ItemType>::LinkedChar(const std::string s)
{
    for(int i = 0; i < s.length(); i++)
    {
        add(s[i]);
        itemCount++;
    }
}

template<class ItemType>
int LinkedChar<ItemType>::getCurrentSize(){
    return itemCount;
}


template<class ItemType>
int LinkedChar<ItemType>::index(char ch) const
{
    int index = -1;
    bool found = false;
    Node<ItemType>* curPtr = headptr;
    while(curPtr != nullptr && !found)
    {
        if(ch != curPtr->getItem())
        {
            index++;
        }
        else if (ch == curPtr->getItem())
        {
            found = true;
            index++;
        }
        curPtr = curPtr->getNext();
    }
    if(!found)
        index =-1;
    
    return index;
}
template<class ItemType>
void LinkedChar<ItemType>::add(char item)
{
    Node<ItemType>* newNode = new Node<ItemType>(item);
    Node<ItemType>* currNode = headptr;
    Node<ItemType>* prevNode = currNode;

    if (headptr == nullptr) {
        newNode->setNext(headptr);
        headptr = newNode;
        return;
    }
    while (currNode != nullptr) {
        prevNode = currNode;
        currNode = currNode->getNext();
    }
    prevNode->setNext(newNode);
    

}
template<class ItemType>
void LinkedChar<ItemType>::append(const LinkedChar<ItemType>& lc)
{
    Node<ItemType>* curPtr = headptr;
    
    Node<ItemType>* appendChainPtr = lc.headptr;
    
        while (curPtr->getNext() != nullptr)//find nullptr of original LL
        {
     
            curPtr = curPtr->getNext();
        }
        while(appendChainPtr != nullptr)
        {
            itemCount++;
            ItemType data = appendChainPtr->getItem();
            Node<ItemType>* newNode = new Node<ItemType>(data);
            curPtr->setNext(newNode);
            appendChainPtr = appendChainPtr->getNext();
            curPtr = curPtr->getNext();
        }
}
template<class ItemType>
bool LinkedChar<ItemType>::submatch(const LinkedChar& lc)const
{
    Node<ItemType>* curPtr = headptr;
    Node<ItemType>* testPtr = lc.headptr;
    bool match = false;
    ItemType base;
    ItemType test;
    while(curPtr != nullptr and !match)
    {
        base = curPtr->getItem();
        test = testPtr->getItem();
        
        if(test==base)
        {
            Node<ItemType>* tempPtr = curPtr; //temp pointer to not lose node traves
            while(test==base and tempPtr != nullptr and testPtr != nullptr)
            {
                base = curPtr->getItem();
                test = testPtr->getItem();
                
                testPtr = testPtr->getNext();
                tempPtr = tempPtr->getNext();
            }
            if(testPtr == nullptr)
                match = true;
            testPtr = lc.headptr;
        }
        
        curPtr = curPtr->getNext();
        
    }
    return match;
}
#endif /* LinkedChar_h */
