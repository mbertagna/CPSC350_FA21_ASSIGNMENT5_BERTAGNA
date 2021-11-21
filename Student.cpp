// a. Michael Bertagna
// b. 2353491
// c. bertagna@chapman.edu
// d. CPSC 350-01
// e. Assignment 5

/* Student.cpp is a class which implements a Student object with constructors, a destructor, and 5 methods:
1) getTimeNeeded: returns time student needs at a window
2) getWaitTime: returns time student waited for a window
3) updateTimeNeeded: decrements time needed
4) updateWaitTime: increments wait time
5) getArrivalTime: returns arrival time
 */

#include "Student.h"

// default constructor
Student::Student(){
    m_timeNeeded = 0;
    m_waitTime = 0;
}

// overloaded constructor
Student::Student(int time, int arrivalTime){
    m_timeNeeded = time;
    m_waitTime = 0;
    m_arrivalTime = arrivalTime;
}

// destructor
Student::~Student(){}

// returns time student needs at a window
int Student::getTimeNeeded(){
    return m_timeNeeded;
}

// returns time student waited for a window
int Student::getWaitTime(){
    return m_waitTime;
}

// decrements ticks needed
void Student::updateTimeNeeded(){
    --m_timeNeeded;
}

// increments wait time
void Student::updateWaitTime(){
    ++m_waitTime;
}

// returns arrival time
int Student::getArrivalTime(){
    return m_arrivalTime;
}