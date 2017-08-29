#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <time.h>
#include <math.h>

using namespace std;

void shell_sort( int array[], int n )
{
    static constexpr int gap_sequence[] = { 13, 9, 5, 2, 1 } ;
    
    // for (gap = n/2; gap > 0; gap /= 2)
    for( int gap : gap_sequence ) if( gap < n )
    {
        // for (i = gap; i < n; i++)
        for( int i = gap ; i < n; ++i )
            
            // for (j=i-gap; j>=0 && v[j]>v[j+gap]; j-=gap)
            for ( int j = i-gap ; j >= 0 && array[j] > array[j+gap] ; j -= gap )
            /*
             temp = v[j];
             v[j] = v[j+gap];
             v[j+gap] = temp;
             */
                std::swap( array[j], array[j+gap] ) ;
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

	shell_sort( array, n );

	time(&end); // STOP THE CLOCK

	cout << "Sorted list in ascending order:\n";

	for (c = 0; c < n; c++)
		cout << array[c] << endl;

	double dif = difftime(end, start);

	cout << "El tiempo de ejecucion fue de: " << dif << " milisegundos" << endl;

	return 0;
}