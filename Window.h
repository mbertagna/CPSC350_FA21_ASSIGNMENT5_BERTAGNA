// a. Michael Bertagna
// b. 2353491
// c. bertagna@chapman.edu
// d. CPSC 350-01
// e. Assignment 5

/* Window.h is a class which lays out the components of a Window
 */

#ifndef WINDOW_H
#define WINDOW_H

#include <iostream>
#include "Student.h"
using namespace std;

class Window{
    public:
        // default constructor
        Window();
        // overloaded constructor
        Window(Student *s);
        // destructor
        ~Window();
        // time window has been idle
        int getIdletime();
        // increments idle time
        void updateIdleTime();
        // sets window busy
        void setWindowBusy();
        // sets window not busy
        void setWindowNotBusy();
        // returns student at window
        Student* getStudent();
        // sets student at window
        void setStudent(Student *s);
        // sets student at window NULL
        void removeStudent();
        // returns true if window is busy, else false
        bool isBusy();

    private:
        // # ticks/minutes window is idle
        int m_idleTime;
        // true if student at window, else false
        bool m_isBusy;
        // student at window
        Student *m_student;
};

#endif