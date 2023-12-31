#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <thread>
#include <chrono> 
#include "task.h"

#ifndef _ALGO_
#define _ALGO_

void Schedul(std::vector<Task>& tasks);
void ExecuteTask(std::string taskName, int time);
void FinishMessage(std::string taskName, int time);
void printTasks(std::vector<Task>& tasks);

// FCFS -> first come first served
void FCFS(std::vector<Task> tasks){
    std::cout << "\n\n\033[0;31m*** FCFS -> first come first served ***\033[0m" << std::endl;
    printTasks(tasks);

    int time = 0;
    for(Task& T : tasks){
        ExecuteTask(T.getName(), T.getBrust());
        time += T.getBrust();
        FinishMessage(T.getName(), time);        
    }
}

// SJF -> Shortest-job-first 
void SJF(std::vector<Task> tasks){
    std::cout << "\n\n\033[0;31m*** SJF -> Shortest-job-first ***\033[0m" << endl;
    printTasks(tasks);

    int time = 0;
    // sort them according to the least cpu brust
    auto comp = [](Task& T1, Task& T2){
        return T1.getBrust() < T2.getBrust();
    };
    sort(tasks.begin(), tasks.end(), comp);

    for(Task& T : tasks){
        ExecuteTask(T.getName(), T.getBrust());
        time += T.getBrust();
        FinishMessage(T.getName(), time);
    }
}

// Priority scheduling
void PriorityScheduling(std::vector<Task> tasks){
    std::cout << "\n\n\033[0;31m*** Priority scheduling ***\033[0m" << std::endl;
    printTasks(tasks);

    int time = 0;
    // sort tasks accroding to the priority
    auto comp = [](Task& T1, Task& T2){
        return T1.getPriority() > T2.getPriority();
    };
    sort(tasks.begin(), tasks.end(), comp);

    for(Task& T : tasks){
        ExecuteTask(T.getName(), T.getBrust());
        time += T.getBrust();
        FinishMessage(T.getName(), time);        
    }
}

// Round-robin (RR) scheduling
void RoundRobin(std::vector<Task> tasks){
    std::cout << "\n\n\033[0;31m*** Round-robin (RR) scheduling ***\033[0m" << std::endl;
    printTasks(tasks);

    queue<Task> taskQueue;
    for(auto& T : tasks){
        taskQueue.push(T);
    }
    // iterate over the queue and execute each task
    // for amount of time (decrement the brust by one) and if it's not finished
    // push it back onto the queue
    int time = 0;

    while(!taskQueue.empty()){
        Task T = taskQueue.front();
        taskQueue.pop();

        ExecuteTask(T.getName(), 1);
        T.setBrust(T.getBrust() - 1);
        time++;

        if(T.getBrust() > 0){
            taskQueue.push(T);
        } else {
            FinishMessage(T.getName(), time);
        }

        
    }  
}

void ExecuteTask(std::string taskName, int time){
    cout << "Task: " << taskName << ", is running" << endl;
    std::this_thread::sleep_until(std::chrono::system_clock::now() + std::chrono::seconds(time));
}

void FinishMessage(std::string taskName, int time){
    std::cout << "\033[32m" << "Task: " << taskName << ", has Finished after: " << time << " Seconds." << "\033[0m" << std::endl;
}

void printTasks(std::vector<Task>& tasks){
    std::cout << "----------------------------------------------\n";
    for(Task& T : tasks){
        std::cout << "TASK: " << T.getName() << "\t, PRIORITY: " << T.getPriority() << "\t, CPU_BRUST: " << T.getBrust() << std::endl;
    }
    std::cout << "----------------------------------------------\n";
}

void Schedul(std::vector<Task>& tasks){
    FCFS(tasks);
    SJF(tasks);
    PriorityScheduling(tasks);
    RoundRobin(tasks);
}

#endif