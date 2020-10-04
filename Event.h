#ifndef _Event_H_
#define _Event_H_
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "Date.h"
using namespace std;

class Event{
protected:
    string title;
    short priority;
    Date startDay;
    int startTime;
    int endTime;
    int reminderTime;
    Date reminderDay;
    string description;

    short eventType;
    /* Use this when displaying daily distribution 
    or daily calendar
    0: Event
    1: Sleep
    2/3/4: Breakfast/Lunch/Dinner
    5: Class
    6: Exam
    7: Homework
    */
public:
    // Constructors
    Event();
    Event(const Event &e);

    // Destructor
    ~Event() {;}

    // Get functions
    string &getTitle(){return title;}
    string &getDescription(){return description;}
    short getPriority(){return priority;}
    int getStartTime(){return startTime;}
    int getEndTime(){return endTime;}
    int getReminderTime(){return reminderTime;}

    // Set functions
    void setPriority(short val){priority = val;}
    void setStartTime(short time){startTime = time;}
    void setEndEtime(short time){endTime = time;}
    void setReminderTime(short time){reminderTime = time;}
    void setStartDay(short m, short d, short y) {startDay.setAll(m,d,y);}
    void setReminderDay(short m, short d, short y) {reminderDay.setAll(m,d,y);}

    // Set functions (definitions only)
    void setTitle(const string str);
    void setDescription(const string str);

    // Other functions
    
};

class ClassWork:public Event{
protected:
    bool exam;
    string className;
    Date due;
    Date startWorking;
    int timeSpend;
public:
    // Constructors
    ClassWork();
    ClassWork(const ClassWork &c);

    // Destructor
    ~ClassWork(){;}

    // Get functions
    bool getExam() {return exam;}
    string &getClass() {return className;}
    int getTimeSpend() {return timeSpend;}
    short getStartDay() {return startWorking.getDay();}
    short getStartMonth() {return startWorking.getMonth();}
    short getStartYear() {return startWorking.getYear();}
   
    // Set functions
    void setExam(bool e){exam = e;}
    void setTimeSpend(int time){timeSpend = time;}
    void setDue(short m, short d, short y){due.setAll(m,d,y);}
    void setStartWorking(short m, short d, short y){startWorking.setAll(m,d,y);}

    // Set functions (definitions only)
    void setClassName(const string str);

    // Other functions
    void printDue(){cout << due.getMonth() << "/" << due.getDay() << "/20" << due.getYear() << endl;}

};

class Work:public Event{
public:
    // Constructors
    Work();

    // Destructor
    ~Work();

    // Get functions
    short getPriority() {return priority;}
    int getTotalWorkTime(int startT, int endT) {return (endT-startT);}
};

class Permanent:public Event{
protected:
    int timesPerWeek;
public:
    Permanent():Event(){}
};

#endif  // _Event_H_