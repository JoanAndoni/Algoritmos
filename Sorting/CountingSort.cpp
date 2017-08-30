#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <math.h>
//#include <chrono>

using namespace std;
//using namespace chrono; // Doesnt work in raspberyPi cause libraries


void countingSort(int arr[], int sz) {
    int i, j, k;
    int idx = 0;
    int min, max;
    
    min = max = arr[0];
    for(i = 1; i < sz; i++) {
        min = (arr[i] < min) ? arr[i] : min;
        max = (arr[i] > max) ? arr[i] : max;
    }
    
    k = max - min + 1;
    /* creates k buckets */
    int *B = new int [k];
    for(i = 0; i < k; i++) B[i] = 0;
    
    for(i = 0; i < sz; i++) B[arr[i] - min]++;
    for(i = min; i <= max; i++)
        for(j = 0; j < B[i - min]; j++) arr[idx++] = i;
    
    
    delete [] B;
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
//	high_resolution_clock::time_point t1 = high_resolution_clock::now();//Start chrono
	clock_t cl = clock();

	countingSort(array, n);

//	high_resolution_clock::time_point t2 = high_resolution_clock::now();//Stop chrono
//	time(&end); // STOP THE CLOCK

	cout << "Sorted list in ascending order:\n";

	for (int c = 0; c < n; c++)
		cout << array[c] << endl;

//	auto duration = duration_cast<seconds>(t2 - t1).count(); //Total time
//	double dif = difftime(end, start);

//	cout << "El tiempo de ejecucion fue de: " << duration << " milisegundos" << endl; //Doesnt work in raspberyPi cause libraries
//	cout << "El tiempo de ejecucion fue de: " << dif << " segundos" << endl;
	cout << "El tiempo de ejecucion fue de: " << (clock()-cl*1000/CLOCKS_PER_SEC) << " ms" << endl;

	return 0;
}