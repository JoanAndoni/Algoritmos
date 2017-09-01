#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <math.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable: 4996)
//#include <chrono>

using namespace std;
//using namespace chrono; // Doesnt work in raspberyPi cause libraries

void CocktailSort(int vec[],int tam){
	bool swapped = true;
	int start = 0;
	int end = tam - 1;

	while (swapped){
		swapped = false;

		for (int i = start; i < end; ++i){
			if (vec[i] > vec[i + 1]){
				swap(vec[i], vec[i + 1]);
				swapped = true;
			}
		}

		if (!swapped)
			break;

		swapped = false;

		--end;

		for (int i = end - 1; i >= start; --i){
			if (vec[i] > vec[i + 1]){
				swap(vec[i], vec[i + 1]);
				swapped = true;
			}
		}
		++start;
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

	for (int c = 0; c < n; c++)
		array[c] = (rand() % 1000);       

//	time(&start); //START THE CLOCK
//    high_resolution_clock::time_point t1 = high_resolution_clock::now();//Start chrono
    clock_t cl = clock();

	CocktailSort(array, n);

//    high_resolution_clock::time_point t2 = high_resolution_clock::now();//Stop chrono
//	time(&end); // STOP THE CLOCK
	/*
	cout << "Sorted list in ascending order:\n";

	for (int c = 0; c < n; c++)
    	cout << array[c] << endl;*/

//    auto duration = duration_cast<seconds>(t2 - t1).count(); //Total time
//	double dif = difftime(end, start);

//  cout << "El tiempo de ejecucion fue de: " << duration << " milisegundos" << endl; //Doesnt work in raspberyPi cause libraries
//	cout << "El tiempo de ejecucion fue de: " << dif << " segundos" << endl;
    cout << "El tiempo de ejecucion fue de: " << (clock()-cl*1000/CLOCKS_PER_SEC) << " ms" << endl;

	return 0;
}