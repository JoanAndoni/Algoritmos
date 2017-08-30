#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <math.h>
//#include <chrono> //Doesnt work in raspberyPi cause libraries

using namespace std;
//using namespace chrono; // Doesnt work in raspberyPi cause libraries


void bucketSort(int sarray[], int array_size) {
    const int max = array_size;
    // use bucket[x][max] to hold the current count
	int bucket[10][max + 1];
    // init bucket counters
    for(int x=0;x<10;x++){
        bucket[x][max] = 0;
    }
    // main loop for each digit position
    for(int digit = 1; digit <= 1000000000; digit *= 10) {
        // array to bucket
        for(int i = 0; i < max; i++) {
            // get the digit 0-9
            int dig = (sarray[i] / digit) % 10;
            // add to bucket and increment count
            bucket[dig][bucket[dig][max]++] = sarray[i];
        }
        // bucket to array
        int idx = 0;
        for(int x = 0; x < 10; x++) {
            for(int y = 0; y < bucket[x][max]; y++) {
                sarray[idx++] = bucket[x][y];
            }
            // reset the internal bucket counters
            bucket[x][max] = 0;
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


//	time(&start); //START THE CLOCK
//  high_resolution_clock::time_point t1 = high_resolution_clock::now();//Start chrono
    clock_t cl = clock();

	bucketSort(array, n);

//	time(&end); // STOP THE CLOCK
//  high_resolution_clock::time_point t2 = high_resolution_clock::now();//Stop chrono

//	cout << "Sorted list in ascending order:\n";

	for (c = 0; c < n; c++)
		cout << array[c] << endl;

//    auto duration = duration_cast<seconds>(t2 - t1).count(); //Total time
//	double dif = difftime(end, start);

//    cout << "El tiempo de ejecucion fue de: " << duration << " milisegundos" << endl; //Doesnt work in raspberyPi cause libraries
//	cout << "El tiempo de ejecucion fue de: " << dif << " segundos" << endl;
    cout << "El tiempo de ejecucion fue de: " << (clock()-cl*1000/CLOCKS_PER_SEC) << " ms" << endl;

	return 0;
}