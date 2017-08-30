#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <math.h>
//#include <chrono>

using namespace std;
//using namespace chrono;

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
	int* array = new int[1000000];
    int n, c;

	cout << "Enter number of elements" << endl;
	cin >> n;
//	time_t start, end;

	cout << "The " << n << " integers will be generated automatically" << endl;

	for (c = 0; c < n; c++)
		array[c] = (rand() % 1000);    

    clock_t cl = clock();   

//	time(&start); //START THE CLOCK
//  high_resolution_clock::time_point t1 = high_resolution_clock::now();//Start chrono

	shellSort( array, n );

//  high_resolution_clock::time_point t2 = high_resolution_clock::now();//Stop chrono
//	time(&end); // STOP THE CLOCK

	cout << "Sorted list in ascending order:\n";

	for (c = 0; c < n; c++)
		cout << array[c] << endl;

//  auto duration = duration_cast<seconds>(t2 - t1).count(); //Total time
//	double dif = difftime(end, start);

//  cout << "El tiempo de ejecucion fue de: " << duration << " milisegundos" << endl; //Doesnt work in raspberyPi cause libraries
//	cout << "El tiempo de ejecucion fue de: " << dif << " segundos" << endl;
    cout << "El tiempo de ejecucion fue de: " << (clock()-cl*1000/CLOCKS_PER_SEC) << " ms" << endl;

	return 0;
}