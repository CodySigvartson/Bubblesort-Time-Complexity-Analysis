#include "BubbleSort.h"

/*Programmer: Cody Sigvartson
Description: This is a bubble sort program that will test a range of inputs
	     and time how long each input takes to complete the sort.
*/

int main(void){
	vector<int> vec, vecS, vecU;
	float times[TIMES] = {}, optimalTimes[TIMES]={}, worstTimes[TIMES]={};
	float average = 0.0, optimalTime = 0.0, worstTime = 0.0;
	int n = 100000; //size of N inputs

	for(int i = 0;i<TIMES;i++) //run bubble sort 5 times to get 5 averages
	{
		vecU = generateReverse(n); //sets vecU equal to a vector generated in reverse order
		vecS = generateSorted(n); //sets vecS equal to a vector generated in order
		vec = generateArray(n); //sets vec equal to a randomly generated vec of size n
		times[i] = bubbleSort(vec, n); //sort randomly generated vector of size N
		optimalTimes[i] = bubbleSort(vecS, n); //sort  in order vector of size N
		worstTimes[i] = bubbleSort(vecU, n); //sort reversed vector of size N
	}
	average = getAvg(times); //get average time to sort randomly generated vector
	optimalTime = getAvg(optimalTimes); //get avg time to sort a vector already sorted
	worstTime = getAvg(worstTimes); //get avg time to sort a vector in reverse order

	ofstream myCSV;
	myCSV.open ("BSStats.csv", ofstream::out | ofstream::app); //open csv file in output/append mode
	myCSV << n << "," << optimalTime << "," <<  worstTime << "," << average << ",";
	for(int j = 0; j < TIMES; j++)
	{
		myCSV << times[j] << ","; //output each trial time
	}
	myCSV << endl;
	myCSV.close();

	return 0;
}
