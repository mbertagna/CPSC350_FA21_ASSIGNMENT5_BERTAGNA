// a. Michael Bertagna
// b. 2353491
// c. bertagna@chapman.edu
// d. CPSC 350-01
// e. Assignment 5

/* GenQueue.h is a template class which implements a standard list-based queue consisting of all common list methods. */

#ifndef GENQUEUE_H
#define GENQUEUE_H

#include <iostream>
#include <exception>
#include "List.h"
using namespace std;

template <class T>
class GenQueue{
  public:
    GenQueue();//default constructor
    ~GenQueue();//destructor

    //core fxns
    void enqueue(T data);//aka insert()
    T dequeue();//aka remove()

    //aux fxns
    T peek();
    bool isEmpty();
    size_t getSize();
    void printList();//this method prints the list, the "behind the scenes" data structure for our queue

  private:
    List<T> *myQueue;//pointer that will eventually point to our list
};


template <class T>
GenQueue<T>::GenQueue(){
  myQueue = new List<T>();
}

template <class T>
GenQueue<T>::~GenQueue(){
  delete myQueue;
}

template <class T>
void GenQueue<T>::enqueue(T data){
  myQueue->append(data);
}

template <class T>
T GenQueue<T>::dequeue(){
  if(isEmpty()){
    throw runtime_error("ERROR: Queue is empty.");
  }

  T temp = myQueue->peek();
  myQueue->removeFront();

  return temp;
}

template <class T>
T GenQueue<T>::peek(){
  if(isEmpty()){
    throw runtime_error("ERROR: Queue is empty.");
  }
  return myQueue->peek();
}

template <class T>
bool GenQueue<T>::isEmpty(){
  return myQueue->isEmpty();
}

template <class T>
size_t GenQueue<T>::getSize(){
  return myQueue->getLength();
}

template <class T>
void GenQueue<T>::printList(){
  myQueue->print();
}

#endif
