#include <iostream>
#include <vector>
#include <chrono>
#include <fstream>

#define TIMES 5

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::ofstream;
using namespace std::chrono; //for keeping track of time to sort

float bubbleSort(vector<int> &arr, int n);
time_point<system_clock> getTime();
float getAvg(float (&a)[TIMES]);
vector<int> generateArray(int n);
vector<int> generateSorted(int n);
vector<int>generateReverse(int n);
