#include <iostream>
#include <vector>
#include "task.h"
#include "scheduling_algorithms.h"

int main(){
    std::vector<Task> tasks;
    tasks.push_back(Task("t1", 5, 10));
    tasks.push_back(Task("t2", 2, 5));
    tasks.push_back(Task("t3", 1, 2));
    tasks.push_back(Task("t4", 7, 1));
    tasks.push_back(Task("t5", 4, 7));

    Schedul(tasks);
    system("pause");
}

