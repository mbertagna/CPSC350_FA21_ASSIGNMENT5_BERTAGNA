// a. Michael Bertagna
// b. 2353491
// c. bertagna@chapman.edu
// d. CPSC 350-01
// e. Assignment 5

/* Window.cpp is a class which implements a Window object with constructors, a destructor, and 8 methods:
1) getIdletime: returns time window has been idle
2) updateIdleTime: increments idle time
3) setWindowBusy: sets window busy
4) setWindowNotBusy: sets window not busy
5) getStudent: returns student at window
6) setStudent: sets student at window
7) removeStudent: sets student at window NULL
8) isBusy: returns true if window is busy, else false
 */

#include "Window.h"

// default constructor
Window::Window(){
    m_student = NULL;
    m_idleTime = 0;
    m_isBusy = false;
}

// overloaded constructor
Window::Window(Student *s){
    m_student = s;
    m_idleTime = 0;
    m_isBusy = true;
}

// destructor
Window::~Window(){
    delete m_student;
}

// time window has been idle
int Window::getIdletime(){
    return m_idleTime;
}

// increments idle time
void Window::updateIdleTime(){
    ++m_idleTime;
}

// sets window busy
void Window::setWindowBusy(){
    m_isBusy = true;
}

// sets window not busy
void Window::setWindowNotBusy(){
    m_isBusy = false;
}

// returns student at window
Student* Window::getStudent(){
    return m_student;
}

// sets student at window
void Window::setStudent(Student *s){
    m_isBusy = true;
    m_student = s;
}

// sets student at window NULL
void Window::removeStudent(){
    m_isBusy = false;
    m_student = NULL;
}

// returns true if window is busy, else false
bool Window::isBusy(){
    return m_isBusy;
}