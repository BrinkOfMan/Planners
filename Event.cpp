#include "Event.h"
#include <map>
#include <string>
#include <vector>

// ############################ Event class ############################

// ################
// ##Constructors##
// ################

// Default constructor
Event::Event() {
    title = "Event";
    priority = 0;
    startDay.setAll(11, 18, 19);
    startTime = 0;
    endTime = 60;
    reminderDay.setAll(11, 18, 19);
    reminderTime = 0;
    description = "Description";
}

// Copy constructor
Event::Event(const Event &e) {
    // Copy title
    title = e.title;

    // Copy description
    description = e.description;

    // Copy everything else
    priority = e.priority;
    startDay = e.startDay;
    startTime = e.startTime;
    endTime = e.endTime;
}

// ################
// ##Set function##
// ################

void Event::setTitle(const string str) {
    title = str;
}

void Event::setDescription(const string str) {
    description = str;
}

// ########################## ClassWork class ##########################

// ################
// ##Constructors##
// ################

// Default constructor
ClassWork::ClassWork() : Event() {
    exam = false;
    className = "class";
    due.setAll(11, 18, 19);
    startWorking.setAll(11, 18, 19);
    timeSpend = 1;
}

// Copy constructor
ClassWork::ClassWork(const ClassWork &c) : Event(){
    // Copy name
    className = c.className;
}

// ################
// ##Set function##
// ################

void ClassWork::setClassName(const string str) {
    className = str;
}