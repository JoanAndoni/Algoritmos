#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <time.h>
#include <math.h>
#include <chrono>

using namespace std;
using namespace chrono;


void heapify(int arr[], int n, int i)
{
    int largest = i;  // Initialize largest as root
    int l = 2*i + 1;  // left = 2*i + 1
    int r = 2*i + 2;  // right = 2*i + 2
    
    // If left child is larger than root
    if (l < n && arr[l] > arr[largest])
        largest = l;
    
    // If right child is larger than largest so far
    if (r < n && arr[r] > arr[largest])
        largest = r;
    
    // If largest is not root
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        
        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}

// main function to do heap sort
void heapSort(int arr[], int n)
{
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    
    // One by one extract an element from heap
    for (int i=n-1; i>=0; i--)
    {
        // Move current root to end
        swap(arr[0], arr[i]);
        
        // call max heapify on the reduced heap
        heapify(arr, i, 0);
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

	heapSort(array, n);

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