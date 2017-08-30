#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <time.h>
#include <math.h>
#include <chrono>

using namespace std;
using namespace chrono;

int divide(int *array, int lo, int hi) {
    int i,j;
    int v;
    int temp;
    
    v = array[lo];
    i = lo;
    j = hi;
    
    // Mientras no se cruzen los índices
    while (i < j) {
        while ((i < j) && (array[i] <= v)) {
            i++;
        }
        
        while (array[j] > v) {
            j--;
        }
        // Si todavía no se cruzan los indices seguimos intercambiando
        if (i < j) {
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }
    
    // Los índices ya se han cruzado, ponemos el pivot en el lugar que le corresponde
    temp = array[j];
    array[j] = array[lo];
    array[lo] = temp;
    // La nueva posición del pivot
    return j;
}


// Función recursiva para hacer el ordenamiento
void quickSort(int *array, int lo, int hi)
{
    
    int pivot;
    
    if (lo < hi) {
        pivot = divide(array, lo, hi);
        
        // Ordeno la lista de los menores
        quickSort(array, lo, pivot - 1);
        
        // Ordeno la lista de los mayores
        quickSort(array, pivot + 1, hi);
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

	for (c = 0; c < n; c++)
		array[c] = (rand() % 1000);       

	time(&start); //START THE CLOCK
    high_resolution_clock::time_point t1 = high_resolution_clock::now();//Start chrono

	quickSort(array, 0, n-1);

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