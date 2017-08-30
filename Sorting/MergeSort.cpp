#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <time.h>
#include <math.h>
#include <chrono>

using namespace std;
using namespace chrono;

void Merge(int *a, int low, int high, int mid)
{
    // We have low to mid and mid+1 to high already sorted.
    int i, j, k, temp[high-low+1];
    i = low;
    k = 0;
    j = mid + 1;
    
    // Merge the two parts into temp[].
    while (i <= mid && j <= high)
    {
        if (a[i] < a[j])
        {
            temp[k] = a[i];
            k++;
            i++;
        }
        else
        {
            temp[k] = a[j];
            k++;
            j++;
        }
    }
    
    // Insert all the remaining values from i to mid into temp[].
    while (i <= mid)
    {
        temp[k] = a[i];
        k++;
        i++;
    }
    
    // Insert all the remaining values from j to high into temp[].
    while (j <= high)
    {
        temp[k] = a[j];
        k++;
        j++;
    }
    
    
    // Assign sorted data stored in temp[] to a[].
    for (i = low; i <= high; i++)
    {
        a[i] = temp[i-low];
    }
}

// A function to split array into two parts.
void MergeSort(int *a, int low, int high)
{
    int mid;
    if (low < high)
    {
        mid=(low+high)/2;
        // Split the data into two half.
        MergeSort(a, low, mid);
        MergeSort(a, mid+1, high);
        
        // Merge them to get sorted output.
        Merge(a, low, high, mid);
    }
}


int main() 
{
	int* array = new int[1000000];
    int n, c;

	cout << "Enter number of elements" << endl;
	cin >> n;
	time_t start, end;

	cout << "The " << n << " integers will be generated automatically" << endl;

	for (c = 0; c < n; c++)
		array[c] = (rand() % 1000);       

	time(&start); //START THE CLOCK
    high_resolution_clock::time_point t1 = high_resolution_clock::now();//Start chrono

	MergeSort(array, 0, n-1);

    high_resolution_clock::time_point t2 = high_resolution_clock::now();//Stop chrono
	time(&end); // STOP THE CLOCK

	cout << "Sorted list in ascending order:\n";

	for (c = 0; c < n; c++)
		cout << array[c] << endl;

    auto duration = duration_cast<seconds>(t2 - t1).count(); //Total time
	double dif = difftime(end, start);

    cout << "El tiempo de ejecucion fue de: " << duration << " milisegundos" << endl; //Doesnt work in raspberyPi cause libraries
	cout << "El tiempo de ejecucion fue de: " << dif << " segundos" << endl;

	return 0;
}