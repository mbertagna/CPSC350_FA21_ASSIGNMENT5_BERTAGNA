// a. Michael Bertagna
// b. 2353491
// c. bertagna@chapman.edu
// d. CPSC 350-01
// e. Assignment 5

/* OfficeManager.h is a class which lays out the components of a OfficeManager
 */

#ifndef OFFICEMANAGER_H
#define OFFICEMANAGER_H

#include <iostream>
#include <fstream>
#include <algorithm>
#include <exception>
#include "Window.h"
#include "GenQueue.h"
using namespace std;

class OfficeManager{
    public:
        // default constructor
        OfficeManager();
        // overloaded constructor
        OfficeManager(string filePath);
        // destructor
        ~OfficeManager();
        // runs a day at office based on window and student information, then prints statistics about day
        void runDayAtOfficeAndPrintStats();
        // processes input file and updates members accordingly
        void processFile();
        // checks if string is an +integer or 0
        bool isPosIntOrZero(string maybeInt);
        // checks if string is an +integer
        bool isPosInt(string maybeInt);
        // sorts an array via bubble sort
        void bubbleSortArr(int *arr, int size);
        // calculates median value of an array
        int calcMedianArr(int *arr, int size);
        

    private:
        string m_filePath;
        int m_numWindows;
        int m_numStudents;
        // line of students waiting to be served by a window
        GenQueue<Student*> *m_studentLine;
        int m_time;
};

#endif