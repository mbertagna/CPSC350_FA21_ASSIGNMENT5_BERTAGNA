// a. Michael Bertagna
// b. 2353491
// c. bertagna@chapman.edu
// d. CPSC 350-01
// e. Assignment 5

/* Student.h is a class which lays out the components of a Student
 */

#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
using namespace std;

class Student{
    public:
        // default constructor
        Student();
        // overloaded constructor
        Student(int timeNeeded, int arrivalTime);
        // destructor
        ~Student();
        // returns time student needs at a window
        int getTimeNeeded();
        // returns time student waited for a window
        int getWaitTime();
        // decrements time needed
        void updateTimeNeeded();
        // increments wait time
        void updateWaitTime();
        // returns arrival time
        int getArrivalTime();

    private:
        // # of ticks/minutes student needs at a window
        int m_timeNeeded;
        // # of ticks/minutes student waited for a window
        int m_waitTime;
        // time when student arrives
        int m_arrivalTime;
};

#endif