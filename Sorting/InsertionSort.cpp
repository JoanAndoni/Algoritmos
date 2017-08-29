#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <time.h>
#include <math.h>

using namespace std;


int main() 
{
	int* array = new int[1000000];
	int n, c, d, swap, temp;

	cout << "Enter number of elements" << endl;
	cin >> n;
	time_t start, end;

	cout << "The " << n << " integers will be generated automatically" << endl;

	for (c = 0; c < n; c++)
		array[c] = (rand() % 1000);       

	time(&start); //START THE CLOCK

    for(c =1; c<=n-1;c++)
    {
        temp=array[c];
        d=c-1;
         
        while((temp<array[d])&&(d>=0))
        {
            array[d+1]=array[d];    //moves element forward
            d=d-1;
        }
            
          array[d+1]=temp;    //insert element in proper place
       }

	time(&end); // STOP THE CLOCK

	cout << "Sorted list in ascending order:\n";

	for (c = 0; c < n; c++)
		cout << array[c] << endl;

	double dif = difftime(end, start);

	cout << "El tiempo de ejecucion fue de: " << dif << " milisegundos" << endl;

	return 0;
}