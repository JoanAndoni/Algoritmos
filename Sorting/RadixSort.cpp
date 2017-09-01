#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <math.h>
//#include <chrono>

using namespace std;
//using namespace chrono;

int getMax(int arr[], int n)
{
    int max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}

// Count sort of arr[].
void countSort(int arr[], int n, int exp)
{
    // Count[i] array will be counting the number of array values having that 'i' digit at their (exp)th place.
    int i, count[10] = {0};
	int *output = new int[n];
    // Count the number of times each digit occurred at (exp)th place in every input.
    for (i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;
    
    // Calculating their cumulative count.
    for (i = 1; i < 10; i++)
        count[i] += count[i-1];
    
    // Inserting values according to the digit '(arr[i] / exp) % 10' fetched into count[(arr[i] / exp) % 10].
    for (i = n - 1; i >= 0; i--)
    {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
    
    // Assigning the result to the arr pointer of main().
    for (i = 0; i < n; i++)
        arr[i] = output[i];
}

// Sort arr[] of size n using Radix Sort.
void radixsort(int arr[], int n)
{
    int exp, m;
    m = getMax(arr, n);
    
    // Calling countSort() for digit at (exp)th place in every input.
    for (exp = 1; m/exp > 0; exp *= 10)
        countSort(arr, n, exp);
}

int main() 
{
	int* array = new int[1000000];
    int n, c;

	cout << "Enter number of elements" << endl;
	cin >> n;
//	time_t start, end;

	cout << "The " << n << " integers will be generated automatically" << endl;

	for (c = 0; c < n; c++)
		array[c] = (rand() % 1000);       

//	time(&start); //START THE CLOCK
//  high_resolution_clock::time_point t1 = high_resolution_clock::now();//Start chrono
    clock_t cl = clock();

	radixsort(array, n);

//  high_resolution_clock::time_point t2 = high_resolution_clock::now();//Stop chrono
//	time(&end); // STOP THE CLOCK

/*	cout << "Sorted list in ascending order:\n";

	for (c = 0; c < n; c++)
		cout << array[c] << endl;
		*/
//  auto duration = duration_cast<seconds>(t2 - t1).count(); //Total time
//	double dif = difftime(end, start);

//  cout << "El tiempo de ejecucion fue de: " << duration << " milisegundos" << endl; //Doesnt work in raspberyPi cause libraries
//  cout << "El tiempo de ejecucion fue de: " << dif << " segundos" << endl;
    cout << "El tiempo de ejecucion fue de: " << (clock()-cl*1000/CLOCKS_PER_SEC) << " ms" << endl;

	return 0;
}