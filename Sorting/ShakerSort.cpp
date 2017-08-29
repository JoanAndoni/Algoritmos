#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <time.h>
#include <math.h>

using namespace std;

// A function to swap values using call by reference. 
void swap(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
 
// A function implementing shaker sort.
void ShakerSort(int a[], int n)
{
	int i, j, k;
	for(i = 0; i < n;)
	{
		// First phase for ascending highest value to the highest unsorted index.
		for(j = i+1; j < n; j++)
		{
			if(a[j] < a[j-1])
				swap(&a[j], &a[j-1]);
		}
		// Decrementing highest index. 
		n--;
 
		// Second phase for descending lowest value to the lowest unsorted index.
		for(k = n-1; k > i; k--)
		{
			if(a[k] < a[k-1])
				swap(&a[k], &a[k-1]);
		}
		// Incrementing lowest index.
		i++;
	}
}

int main() 
{
	int array[1000000], n, c, d, swap;

	cout << "Enter number of elements" << endl;
	cin >> n;
	time_t start, end;

	cout << "The " << n << " integers will be generated automatically" << endl;

	for (c = 0; c < n; c++)
		array[c] = (rand() % 1000);       

	time(&start); //START THE CLOCK

	ShakerSort(array, n);

	time(&end); // STOP THE CLOCK

	cout << "Sorted list in ascending order:\n";

	for (c = 0; c < n; c++)
		cout << array[c] << endl;

	double dif = difftime(end, start);

	cout << "El tiempo de ejecucion fue de: " << dif << " milisegundos" << endl;

	return 0;
}