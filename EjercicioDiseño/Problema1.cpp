#include <cstdio>
#include <iostream>
#include <fstream>
#define MAX 100

using namespace std;

typedef struct element{
    float peso;
    int beneficio;
} element;

void read(element elements[], int n)
{
	ifstream infile;
	infile.open("Elements.txt");
    for(int i = 0; i < n; i++)
    {
        infile >> elements[i].peso;
        infile >> elements[i].beneficio;
    }

	infile.close();
}

void resolver(element elementos[], int nElementos, float capMochila, element elemMochila[])
{
    float peso_en_curso; int i;
    for (i=1 ; i < MAX; ++i) elemMochila[i].peso = 0.0;
    
    peso_en_curso = 0.0;
    i=1;
    
    while ((peso_en_curso < capMochila) && (i<=nElementos))
    {
        if ((elementos[i].peso + peso_en_curso) <= capMochila) { elemMochila[i].peso = 1.0; }
        else { elemMochila[i].peso = (capMochila - peso_en_curso) / elementos[i].peso; }
    
        peso_en_curso = peso_en_curso + (elemMochila[i].peso * elementos[i].peso);
        ++i;
    }
}

int main()
{
    element elementos[MAX]; // Array de elementos
    int n = 10; // Número de elemntos
    read(elementos, n);
	float capMochila = 15.0;
	element elemMochila[10];
    resolver(elementos, n, capMochila, elemMochila);


    cout << "Solución de los elementos de la mochila\n" << endl;
    for(int i = 0; i < n; i++)
    {
        cout << elemMochila[i].peso << endl;
        cout << elemMochila[i].beneficio << endl;
    }
    return 0;
}