//Radix sort
#include <iostream>
using namespace std;


int getMax(int arr[], int n) //to get maximum value in array
{
	int max = arr[0]; //consider 1st element as maximum element 
	for (int i = 1; i < n; i++) //loop to check maximum element  
	{
		if (arr[i] > max) //comparing element with max 
		{
			max = arr[i]; //if element of arr[i] is greater than max, save it in max
		}
	}
	return max;
}


void countSort(int* arr, int n, int pos)  // Count sort of arr[] with respect to position
{
	int* output = new int[n]; //dynamic memory allocation
	int i;
	int count[10] = { 0 }; //all count elements = 0 


	for (i = 0; i < n; i++) //loop for full original array
	{
		count[(arr[i] / pos) % 10]++;  //count number of times each digit occur at that position and store in that index
	}

	for (i = 1; i < 10; i++)
	{
		count[i] += count[i - 1]; // Calculating their cumulative count
	}

	for (i = n - 1; i >= 0; i--)
	{
		output[count[(arr[i] / pos) % 10] - 1] = arr[i]; //putting values in output array according to value in count array -1
		count[(arr[i] / pos) % 10]--; // decreasing count index value

	}

	for (i = 0; i < n; i++)
	{
		arr[i] = output[i];		//copy output array in original array
	}
}


void radixsort(int* arr, int n) //Radix sort
{
	int pos, m;
	m = getMax(arr, n); // function to get maximum element 

	for (pos = 1; m / pos > 0; pos *= 10)
	{
		countSort(arr, n, pos); // countSort function is called for every input
	}
}

int main()
{
	cout << "RADIX SORT" << endl;
	cout << "----------" << endl;

	int n, i;
	int arra[6] = { 20,14,2,153,451,12 };
	n = sizeof(arra) / sizeof(arra[0]); // finding the length of array 
	radixsort(arra, n);

	// Printing the sorted data.
	cout << "\nData After Sorting: \n";
	for (i = 0; i < n; i++)
	{
		cout << " " << arra[i];
	}
	cout << endl;
	system("pause");
	return 0;
}