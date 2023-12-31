#include <string>
using namespace std;

#ifndef TASK_H
#define TASK_H

// each task has a name, priority, and cpu brust
// T1, 4, 20
// T2, 2, 25
// T3, 3, 25
// T4, 3, 15
// T5, 10, 10

class Task{
private:
    string name;
    int priority;
    int cpu_brust;

public:
    Task(string name, int priority, int cpu_brust){
        this->name = name;
        this->priority = priority;
        this->cpu_brust = cpu_brust;
    }

    void setBrust(int new_brust){
        this->cpu_brust = new_brust;
    }

    int getPriority() const{
        return this->priority;
    }

    int getBrust() const{
        return this->cpu_brust;
    }

    string getName() const{
        return this->name;
    }
};

#endif