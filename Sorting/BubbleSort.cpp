#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <time.h>
#include <math.h>
#include <chrono> //Doesnt work in raspberyPi cause libraries

using namespace std;
using namespace chrono; // Doesnt work in raspberyPi cause libraries

int main() 
{
	int* array = new int[1000000];
	int n, c, d, swap;

	cout << "Enter number of elements" << endl;
	cin >> n;
	time_t start, end;

	cout << "The " << n << " integers will be generated automatically" << endl;

	for (c = 0; c < n; c++)
		array[c] = (rand() % 1000);       

	time(&start); //START THE CLOCK
	high_resolution_clock::time_point t1 = high_resolution_clock::now();//Start chrono

	for (c = 0; c < (n - 1); c++)
	{
		for (d = 0; d < n - c - 1; d++)
		{
			if (array[d] > array[d + 1]) /* For decreasing order use < */
			{
				swap = array[d];
				array[d] = array[d + 1];
				array[d + 1] = swap;
			}
		}
	}

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