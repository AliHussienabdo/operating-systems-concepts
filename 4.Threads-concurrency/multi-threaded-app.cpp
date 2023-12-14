#include <thread>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

void getMax(vector<int>, int&);
void getMin(vector<int>, int&);
void getAverage(vector<int>, int&);

int main(int argc, char const *argv[])
{   // max: 95, min: 72, average: 82
    vector<int> values = {90, 82, 78, 95, 79, 72, 85}; 

    int min, max, average = 0;

    cout << "**Threads are launched now!**\n\n" << endl;
    // we pass the function and it's parameters
    // You can't pass references directly to the std::thread() constructor. You must wrap them in std::ref().
    thread thread_calc_max(getMax, values, ref(max));
    thread thread_calc_min(getMin, values, ref(min));
    thread thread_calc_average(getAverage, values, ref(average));

    // to wait for the threads to finish their work we use std::thread::join function
    thread_calc_max.join();
    cout << "thread_calc_max has finished his work" << endl;

    thread_calc_min.join();
    cout << "thread_calc_min has finished his work" << endl;

    thread_calc_average.join();
    cout << "thread_calc_average has finished his work\n\n" << endl;


    cout<< "The Max: " << max << ", The min: " << min << ", The average: " << average << endl;

    system("pause");
}

void getMax(vector<int> values, int& max)
{
    max = values[0];

    for (int i : values){
        max = i > max ? i : max;
    }
}

void getMin(vector<int> values, int& min)
{
    min = values[0];

    for (int i : values){
        min = i < min ? i : min;
    }
}

void getAverage(vector<int> values, int& average)
{
    sort(values.begin(), values.end());
    average = values[values.size() / 2];
}