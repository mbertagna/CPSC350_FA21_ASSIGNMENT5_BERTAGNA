// a. Michael Bertagna
// b. 2353491
// c. bertagna@chapman.edu
// d. CPSC 350-01
// e. Assignment 5

/* main.cpp contains the main method and creates an instance of the OfficeManager class
in order to simulate an day at the registar's office. It takes one command line arguement:
1) file path to input file
*/

#include "OfficeManager.h"

int main(int argc, char** argv) {

  try{
    if(argc < 2)
      throw runtime_error("ERROR: Please provide an input file path as the first command line arguement.");
  }
  catch(runtime_error &excpt){
    cerr << excpt.what() << endl;
    return -1;
  }

  string filePath = argv[1];
  OfficeManager *om = new OfficeManager(filePath);

  try{
    om->runDayAtOfficeAndPrintStats();
  }
  catch(runtime_error &excpt){
    cerr << excpt.what() << endl;
    return -1;
  }

  delete om;
  return 0;
}