// a. Michael Bertagna
// b. 2353491
// c. bertagna@chapman.edu
// d. CPSC 350-01
// e. Assignment 5

/* ListInterface.h is a pure virtual template interface which lays out the methods included in a list. */

#ifndef LISTINTERFACE_H
#define LISTINTERFACE_H

#include <iostream>
using namespace std;

template <class T>
class ListInterface{
    public:
        //inserts value at front of list
        virtual void append(T value) = 0;
        //inserts value at back of list
        virtual void prepend(T value) = 0;
        //inserts value after specified value
        virtual void insertAfter(T insertAfterValue, T value) = 0;
        //removes specified value
        virtual void remove(T value) = 0;
        //removes front value in list
        virtual void removeFront() = 0;
        //removes back value in list
        virtual void removeBack() = 0;
        //returns value if found, else null
        virtual int search(T value) = 0;
        //returns front value in list
        virtual T peek() = 0;
        //prints list items in order
        virtual void print() = 0;
        //prints list items in reverse order
        virtual void printReverse() = 0;
        //sorts list in acesending order
        virtual void sort() = 0;
        //returns true if list contains no items
        virtual bool isEmpty() = 0;
        //returns the number of items contained in the list
        virtual unsigned int getLength() = 0;
};

#endif