#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include "Date.h"
#include "Event.h"
using namespace std;

// Functions to read things from a file

int length_of(const char *s) {
  int len = 0;
  while (0 != s[len]) ++len;
  return len;
}

void read_stream(ifstream &f, char *array, int max_size) {
  int num_bytes;
  if (f.good()) {
    f.read(array, max_size);
    if (f) {
      cerr << "Warning in read_stream:  did not reach end of stream after " << max_size << " characters.";
      num_bytes = max_size - 1;
    } else {
      num_bytes = f.gcount();
      if (num_bytes >= max_size) num_bytes = max_size - 1;
    }
  } else {
    cerr << "Warning in read_stream: unable to read anything\n";
    num_bytes = 0;
  }
  array[num_bytes] = 0;  // assign null at end
}

void read_file(const char *fname, char *array, int max_size) {
  ifstream f(fname);
  read_stream(f, array, max_size);
  f.close();
}

// Actual test program

int main() {

  Event meeting;
  cout << "Event title is " << meeting.getTitle() << endl;
  cout << "Description is " << meeting.getDescription() << endl;

  meeting.setTitle("Epic");
  meeting.setDescription("Walkin' down the fightin' side of me");
  cout << "Event title is now " << meeting.getTitle() << endl;
  cout << "Description is now " << meeting.getDescription() << endl;

  ClassWork mathHomework;
  cout << "Event title is " << mathHomework.getTitle() << endl;
  cout << "Description is " << mathHomework.getDescription() << endl;
  cout << "Is mathHomework an exam? " << mathHomework.getExam() << endl;
  mathHomework.setDue(11, 20, 19);
  cout << "When is mathHomework due?\n";
  mathHomework.printDue();
  mathHomework.setStartDay(11, 18, 19);

  
  ofstream f("event.txt");  // create file stream object

  f.write(to_string(mathHomework.getStartYear()).c_str(), 3);
  f.write(to_string(mathHomework.getStartMonth()).c_str(), 3);
  f.write(to_string(mathHomework.getStartDay()).c_str(), 3);
  f.write(to_string(mathHomework.getStartTime()).c_str(),5);
  f.write(mathHomework.getTitle().c_str(), 20);
  f.write(mathHomework.getDescription().c_str(), 80);

  f.close();

  char testEvent[100];
  read_file("event.txt", testEvent, 121);
  cout << (testEvent + 20) << endl;
  
  // REFERENCE: f.write(to_string(mathHomework.getStartTime()).c_str(),5);

  return 0;
}