// a. Michael Bertagna
// b. 2353491
// c. bertagna@chapman.edu
// d. CPSC 350-01
// e. Assignment 5

/* Window.cpp is a class which implements a Window object with constructors, a destructor, and 7 methods:
1) getIdletime: returns time window has been idle
2) runDayAtOfficeAndPrintStats: runs a day at office based on window and student information, then prints statistics about day
3) processFile: processes input file and updates members accordingly
4) isPosIntOrZero: checks if string is an +integer or 0
5) isPosInt: checks if string is an +integer
6) bubbleSortArr: sorts an array via bubble sort
7) calcMedianArr: calculates median value of an array
 */

#include "OfficeManager.h"

// default constructor
OfficeManager::OfficeManager(){}

// overloaded constructor
OfficeManager::OfficeManager(string filePath){
    m_filePath = filePath;
    m_time = 0;
    m_numWindows = 0;
    m_numStudents = 0;
    m_studentLine = new GenQueue<Student*>();
}

// destructor
OfficeManager::~OfficeManager(){
    delete m_studentLine;
}

// runs a day at office based on window and student information
void OfficeManager::runDayAtOfficeAndPrintStats(){
    processFile();
    // array holding students who have been finished being served at window
    Student *finishedStudents[m_numStudents];

    int numStudentsFinished = 0;

    int currQueueSize = 0;

    //array holding windows
    Window *windows[m_numWindows];

    //put windows will NULL students in arrays
    for(int i = 0 ; i < m_numWindows ; ++i){
        windows[i] = new Window();
    }

    while(!(numStudentsFinished == m_numStudents)){
        //loop thru windows
        for(int i = 0 ; i < m_numWindows ; ++i){
            //if window busy update student time needed
            if(windows[i]->isBusy()){
                windows[i]->getStudent()->updateTimeNeeded();
            }
            //if window busy and student time needed at window = 0  remove student from window and store student
            if(windows[i]->isBusy()){
                if(windows[i]->getStudent()->getTimeNeeded() == 0){
                    finishedStudents[numStudentsFinished++] = windows[i]->getStudent();
                    windows[i]->removeStudent();
                }
            }
        }

        //if for every open window, set student to window if arrived and students left in queue
        for(int i = 0 ; i < m_numWindows ; ++i){
            if(!(windows[i]->isBusy())){
                if(!(m_studentLine->isEmpty()))
                    if(m_time >= m_studentLine->peek()->getArrivalTime())
                        windows[i]->setStudent(m_studentLine->dequeue());
            }
        }

        //break if all students finished being served
        if(numStudentsFinished == m_numStudents){
            break;
        }

        //for each empty window, increment idle time
        for(int i = 0 ; i < m_numWindows ; ++i){
            if(!(windows[i]->isBusy())){
                windows[i]->updateIdleTime();
            }
        }

        currQueueSize = m_studentLine->getSize();

        //for each student if they have arrived, increment wait time
        for(int i = 0 ; i < currQueueSize ; ++i){
            if(m_time >= m_studentLine->peek()->getArrivalTime())
                m_studentLine->peek()->updateWaitTime();
            m_studentLine->enqueue(m_studentLine->dequeue());
        }
        //increment time
        ++m_time;
    }

    double sumStuWait = 0;
    double meanStuWait = 0;
    int medStuWait = 0;
    int maxStuWait = 0;
    int numStuWait10 = 0;


    double sumWindIdle = 0;
    double meanWindIdle = 0;
    int maxWindIdle = 0;
    int numWindIdle5 = 0;

    if(m_numStudents == 0){
    }
    else{
        int *windIdleArr = new int[m_numWindows];
        int *stuWaitArr = new int[m_numStudents];

        //put window idle times in arr
        for(int i = 0 ; i < m_numWindows ; ++i){
            windIdleArr[i] = windows[i]->getIdletime();
            sumWindIdle += windows[i]->getIdletime();
            //track num windows over 5 min idle
            if((windows[i]->getIdletime()) > 5){
                ++numWindIdle5;
            }
        }

        //put student wait times in arr
        for(int i = 0 ; i < m_numStudents ; ++i){
            stuWaitArr[i] = finishedStudents[i]->getWaitTime();
            sumStuWait += finishedStudents[i]->getWaitTime();
            //track num students over 10 min wait
            if((finishedStudents[i]->getWaitTime() > 10)){
                ++numStuWait10;
            }
        }

        bubbleSortArr(windIdleArr, m_numWindows);
        bubbleSortArr(stuWaitArr, m_numStudents);

        meanStuWait = sumStuWait/m_numStudents;
        meanWindIdle = sumWindIdle/m_numWindows;

        maxStuWait = stuWaitArr[m_numStudents-1];
        maxWindIdle = windIdleArr[m_numWindows-1];

        medStuWait = calcMedianArr(stuWaitArr, m_numStudents);

        delete windIdleArr;
        delete stuWaitArr;
    }
    //print stats
    cout << "                    MEAN STUDENT WAIT TIME: " << meanStuWait << endl;
    cout << "                  MEDIAN STUDENT WAIT TIME: " << medStuWait << endl;
    cout << "                 LONGEST STUDENT WAIT TIME: " << maxStuWait << endl;
    cout << "NUMBER OF STUDENTS WAITING OVER 10 MINUTES: " << numStuWait10 << endl;
    cout << "                     MEAN WINDOW IDLE TIME: " << meanWindIdle << endl;
    cout << "                  LONGEST WINDOW IDLE TIME: " << maxWindIdle << endl;
    cout << " NUMBER OF WINDOWS IDLE FOR OVER 5 MINUTES: " << numWindIdle5 << endl;
}

// processes input file and updates members accordingly
void OfficeManager::processFile(){
    ifstream inFS;// input file stream

    inFS.open(m_filePath);// open input file

    // if input file cannot be opened print error to user
    if (!inFS.is_open()) {
        throw runtime_error("ERROR: File on path could not be opened/may not exist.");
    }
    // if file successfully opened, read file
    else{
        string numWindows = "";

        getline(inFS, numWindows);// store first line in file data: height

        if(!(isPosInt(numWindows))){//return false if first two lines not +integers
            throw runtime_error("ERROR: File format is incorrect.");
        }

        m_numWindows = std::stoi(numWindows);

        string arrivalTime = "";
        string numStudents = "";
        int numStudentsInt = 0;
        
        string studentTimeNeeded = "";

        getline(inFS, arrivalTime);// store first line in file data

        getline(inFS, numStudents);

        // loop until the filestream is empty
        while (!inFS.fail()) {

            if(arrivalTime == "\n" || numStudents == "\n"){
                break;
            }

            if(!(isPosIntOrZero(arrivalTime) && isPosInt(numStudents))){//return false if first two lines not +integers
                throw runtime_error("ERROR: File format is incorrect.");
            }

            numStudentsInt = std::stoi(numStudents);

            m_numStudents += numStudentsInt;

            // get time needed at window for each student and make instance of student
            for(int i = 0 ; i < numStudentsInt ; ++i){

                getline(inFS, studentTimeNeeded);

                if(!(isPosInt(studentTimeNeeded))){//return false if first two lines not +integers
                    throw runtime_error("ERROR: File format is incorrect.");
                }

                m_studentLine->enqueue(new Student(std::stoi(studentTimeNeeded), std::stoi(arrivalTime)));
            }

        getline(inFS, arrivalTime);// store next line in file data
        getline(inFS, numStudents);
        }
    }
    inFS.close();// close input file stream    
}

// checks if string is an +integer or 0
bool OfficeManager::isPosIntOrZero(string maybeInt){
    if(maybeInt.length() == 0)//return false if string has length zero
        return false;

    for(int i = 0; i < maybeInt.length(); ++i){//loop through chars in string
        if(!(isdigit(maybeInt[i])))//if char is not numeric return false
            return false;
    }

    if(std::stoi(maybeInt) < 0)//if decimal value is not > 0
        return false;

    return true;//if all numeric and > 0
}

// checks if string is an +integer
bool OfficeManager::isPosInt(string maybeInt){
    if(maybeInt.length() == 0)//return false if string has length zero
        return false;

    for(int i = 0; i < maybeInt.length(); ++i){//loop through chars in string
        if(!(isdigit(maybeInt[i])))//if char is not numeric return false
            return false;
    }

    if(std::stoi(maybeInt) <= 0)//if decimal value is not > 0
        return false;

    return true;//if all numeric and > 0
}

// sorts an array via bubble sort
void OfficeManager::bubbleSortArr(int *arr, int size) {
   for (int i = 0; i < size - 1; ++i) {
      for (int j = 0; j < size - i - 1; ++j) {
         if (arr[j] > arr[j+1]) {
            int temp = arr[j];
            arr[j] = arr[j + 1];
            arr[j + 1] = temp;
         }
      }
   }
}

// calculates median value of an array
int OfficeManager::calcMedianArr(int *arr, int size) {
    if(size % 2 == 0){
        double mid1 = 0;
        double mid2 = 0;
        double med = 0;

        mid1 = arr[size/2 - 1];
        mid2 = arr[size/2];

        med = (mid1 + mid2)/(2.0);

        return med;
    }
    return arr[size/2];
}
 
