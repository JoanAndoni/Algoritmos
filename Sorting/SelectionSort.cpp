#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <time.h>
#include <math.h>

using namespace std;


int main() 
{
	int array[1000000], n, c, d, min, loc, temp;

	cout << "Enter number of elements" << endl;
	cin >> n;
	time_t start, end;

	cout << "The " << n << " integers will be generated automatically" << endl;

	for (c = 0; c < n; c++)
		array[c] = (rand() % 1000);       

	time(&start); //START THE CLOCK

 	for(c=0; c<n-1; c++)
    {
        min=array[c];
        loc=c;
        for(d=c+1;d<n;d++)
        {
            if(min>array[d])
            {
                min=array[d];
                loc=d;
            }
        }
            
        temp=array[c];
        array[c]=array[loc];
        array[loc]=temp;
    }

	time(&end); // STOP THE CLOCK

	cout << "Sorted list in ascending order:\n";

	for (c = 0; c < n; c++)
		cout << array[c] << endl;

	double dif = difftime(end, start);

	cout << "El tiempo de ejecucion fue de: " << dif << " milisegundos" << endl;

	return 0;
}