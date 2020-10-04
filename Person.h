#ifndef _Person_H_
#define _Person_H_
#include "Event.h"
#include <iostream>
#include <vector>
using namespace std;

class Person{
protected:
    vector<Event>e;
    vector<Permanent>p;

public:
    // Constructors
    Person() {
        for (int i = 0; i < 10; i++){
            // p.push_back(new Permanent); // causes an error for some reason
        }
    }

    void addEvent(Event m) {
        e.push_back(m);
    }
};


#endif  // _Person_H_