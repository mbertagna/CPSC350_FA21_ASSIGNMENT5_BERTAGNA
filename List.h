// a. Michael Bertagna
// b. 2353491
// c. bertagna@chapman.edu
// d. CPSC 350-01
// e. Assignment 5

/* List.h is a template class which inherits from the ListInterface and implements a Doubly Linked List based List consisting of all common list methods. */

#ifndef LIST_H
#define LIST_H

#include <iostream>
#include "ListInterface.h"
#include "LinkedList.h"
using namespace std;

template <class T>
class List : public ListInterface<T>{
    public:
        List();
        ~List();
        //inserts value at front of list
        void append(T value) override;
        //inserts value at back of list
        void prepend(T value) override;
        //removes specified value
        void remove(T value) override;
        //removes front value in list
        void removeFront() override;
        //removes back value in list
        void removeBack() override;
        //returns value if found, else null
        int search(T value) override;
        //returns front value in list
        T peek() override;
        //prints list items in order
        void print() override;
        //returns true if list contains no items
        bool isEmpty() override;
        //returns the number of items contained in the list
        unsigned int getLength() override;
        //prints list items in reverse order
        void printReverse() override;
        //sorts list in acesending order
        void sort() override;
        //inserts value after specified value
        void insertAfter(T insertAfterValue, T value) override;

    private:
        DoublyLinkedList<T> *m_linkedList;
};

template <class T>
//default constructor
List<T>::List(){
    m_linkedList = new DoublyLinkedList<T>();
}

template <class T>
//destructor
List<T>::~List(){
    delete m_linkedList;
}

template <class T>
//inserts value at front of list
void List<T>::append(T value){
    m_linkedList->insertBack(value);
}

template <class T>
//inserts value at back of list
void List<T>::prepend(T value){
    m_linkedList->insertFront(value);
}

template <class T>
//removes specified value
void List<T>::remove(T value){
    m_linkedList->removeNode(value);
}

template <class T>
//removes front value in list
void List<T>::removeFront(){
    m_linkedList->removeFront();
}

template <class T>
//removes back value in list
void List<T>::removeBack(){
    m_linkedList->removeBack();
}

template <class T>
//returns value if found, else null
int List<T>::search(T value){
    m_linkedList->findValue(value);
}

template <class T>
//returns front value in list
T List<T>::peek(){
    m_linkedList->getFrontValue();
}

template <class T>
//prints list items in order
void List<T>::print(){
    m_linkedList->printList(1);
}

template <class T>
//returns true if list contains no items, else false
bool List<T>::isEmpty(){
    m_linkedList->isEmpty();
}

template <class T>
//returns the number of items contained in the list
unsigned int List<T>::getLength(){
    m_linkedList->getSize();
}

template <class T>
//prints list items in reverse order
void List<T>::printReverse(){
    m_linkedList->printReverseList(1);
}

template <class T>
//sorts list in acesending order
void List<T>::sort(){
    m_linkedList->bubbleSort();
}

template <class T>
//inserts value after specified value
void List<T>::insertAfter(T insertAfterValue, T value){
    m_linkedList->insertAfter(insertAfterValue, value);
}

#endif