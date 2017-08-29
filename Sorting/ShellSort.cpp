#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <time.h>
#include <math.h>

using namespace std;

void shellSort(int arr[], int n)
{
    int gap, i, j, temp; 
    
    for(gap = n/2; gap > 0; gap = gap/2)
    {
        for(i = gap; i < n; i++)
        {
            for(j = i-gap; j >= 0; j = j-gap)
            {
                if(arr[j+gap] >= arr[j])
                    break; 
                else
                {			
                    temp = arr[j];
                    arr[j] = arr[j+gap];
                    arr[j+gap] = temp;
                }
            }
        }
    }
}
int main() 
{
	int array[1000000], n, c;

	cout << "Enter number of elements" << endl;
	cin >> n;
	time_t start, end;

	cout << "The " << n << " integers will be generated automatically" << endl;

	for (c = 0; c < n; c++)
		array[c] = (rand() % 1000);       

	time(&start); //START THE CLOCK

	shellSort( array, n );

	time(&end); // STOP THE CLOCK

	cout << "Sorted list in ascending order:\n";

	for (c = 0; c < n; c++)
		cout << array[c] << endl;

	double dif = difftime(end, start);

	cout << "El tiempo de ejecucion fue de: " << dif << " milisegundos" << endl;

	return 0;
}