#include "BubbleSort.h"

float bubbleSort(vector<int> &arr, int n)
{
	time_point<system_clock> tStart, tEnd;
	int temp,i,j;
	bool swap;

	tStart = getTime(); //start clock for bubble sort

	for(i=0;i < n-1;i++) //for each pass through the array
	{
		swap = false;
		for(j=0;j < n-i-1;j++)
		{
			if(arr[j] > arr[j+1])
			{
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
				swap = true;
			}
		}
		if(swap == false) //no more passes if no swaps were made on a pass through the array
			break;
	}
	tEnd = getTime(); //end clock for bubble sort
	typedef duration<float> totalTime; //cast duration seconds to float
	totalTime time = tEnd - tStart; //calculate total time
	return time.count();
}

//get the current system clock time
time_point<system_clock> getTime()
{
	time_point<system_clock> time;
	return time=system_clock::now();
}

//generates a vector of random integers where n is the amount of integers
vector<int> generateArray(int n)
{
	vector<int> newV (n);
	int i;

	srand((unsigned)time(NULL));

	//generate n numbers and fill the vector
	for(i=0; i<n;i++)
	{
		newV[i] = rand() % 100 + 1; //1-100
	}
	return newV;
}

vector<int> generateSorted(int n)
{
	vector<int> sortedVec (n);

	for(int i=1;i<n;i++)
	{
		sortedVec[i] = i;
	}

	return sortedVec;
}

vector<int> generateReverse(int n)
{
	vector<int> unsortedVec (n);
	int num = n;
	for(int i=0;i<n;i++)
	{
		unsortedVec[i] = num;
		num--;
	}

	return unsortedVec;
}

//calculates average of times. Parameter is a reference to an array that
//holds the amount of times (5)
float getAvg(float (&a)[TIMES]){
	float sum = 0.0;
	int i = 0;

	for(i=0;i<TIMES;i++)
	{
		sum += a[i];
	}
	return (sum/TIMES); //returns the averages of the sums
}
