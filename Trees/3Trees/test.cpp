#include <iostream>
#include "BinarySearchTree.h"

//Librerias de lectura de datos
#include <fstream>
#include <sstream>

#include <chrono>

//Floor
#include <math.h>
//Time
#include <ctime>
//Shuffle
#include <algorithm>

void menu();

using namespace std;
using namespace std::chrono;

//Generar Archivod e 100000 sin repetidos
int tam = 100000;
int * vec = new int[tam];

//SWAP
void swapT(int a,int b){
    int temporal = vec[b];
    vec[b] = vec[a];
    vec[a] = temporal;
}


//SHUFFLE
void maShuffle(int tam){        //Version mejorada del Durstenfeld el cual es una version mejorada del
    //Iniciar seed              //Fisher-Yates algorithm con complejidad O(n), en comparación con O(n^2)
    srand ( unsigned ( time(0) ) );
    
    for (int i = tam - 1; i > 0; i--) {
        int index = floor(rand()%i);
        swapT(i, index);
    }
}

void numRandNotRepeated(int tam){
    ofstream myfile;
    string fileName = to_string(tam);
    myfile.open ( fileName + ".txt");
    
    myfile << tam << '\n';  //Se guarda la cantidad de numeres a genera al principio
    
    for(int index=1; index<=tam; index++){
        vec[index] = index;
    }
    maShuffle(tam);
    
    for(int index=0; index<tam; index++){
        myfile << vec[index] << '\n';
    }
    
    myfile.close();
}

int main(){
    //numRandNotRepeated(tam);
    
    
    BinarySearchTree<int> tree;
    
    ifstream archivo_entrada; //Declarar variable que se usa para acceder a las funciones de ifstream
    archivo_entrada.open("100000.txt");
    
    if (archivo_entrada.fail()) {
        cout << "Error al abrir el archivo" << endl;

        return 0;
    }
    
    char linea[128];
    
    //Usando la variable linea se extrae toda la primera linea del archivo de texto
    archivo_entrada.getline(linea, sizeof(linea));
    high_resolution_clock::time_point t1 = high_resolution_clock::now();
    for (int i = 0;i<100000;i++) {
        archivo_entrada.getline(linea, sizeof(linea));
        tree.insert(stoi(linea));
    }
    
    high_resolution_clock::time_point t2 = high_resolution_clock::now();
    
    duration<double> time_span = duration_cast<duration<double> >(t2 - t1);
    
    cout << "Tiempo de ejecucion: " << time_span.count()  << "seconds" << endl;
    archivo_entrada.close();
    
    //Busqueda 1
    t1 = high_resolution_clock::now();
    tree.search(10);
    t2 = high_resolution_clock::now();
    time_span = duration_cast<duration<double> >(t2 - t1);
    cout << "Busq 1: " << time_span.count()  << "seconds" << endl;
    
     //Busqueda 2
    t1 = high_resolution_clock::now();
    tree.search(99999);
    t2 = high_resolution_clock::now();
    time_span = duration_cast<duration<double> >(t2 - t1);
    cout << "Busq 2: " << time_span.count()  << "seconds" << endl;
    
    //Busqueda 3
    t1 = high_resolution_clock::now();
    tree.search(34718);
    t2 = high_resolution_clock::now();
    time_span = duration_cast<duration<double> >(t2 - t1);
     cout << "Busq 3: " << time_span.count()  << "seconds" << endl;
    
    //Busqueda 4
    t1 = high_resolution_clock::now();
    tree.search(666);
    t2 = high_resolution_clock::now();
    time_span = duration_cast<duration<double> >(t2 - t1);
     cout << "Busq 4: " << time_span.count()  << "seconds" << endl;
    
    //Busqueda 5
    t1 = high_resolution_clock::now();
    tree.search(13000);
    t2 = high_resolution_clock::now();
    time_span = duration_cast<duration<double> >(t2 - t1);
     cout << "Busq 5: " << time_span.count()  << "seconds" << endl;
    
    //Busqueda 6
    t1 = high_resolution_clock::now();
    tree.search(60000);
    t2 = high_resolution_clock::now();
    time_span = duration_cast<duration<double> >(t2 - t1);
    cout << "Busq 6: " << time_span.count()  << "seconds" << endl;
  
    //Busqueda 7
    t1 = high_resolution_clock::now();
    tree.search(9441);
    t2 = high_resolution_clock::now();
    time_span = duration_cast<duration<double> >(t2 - t1);
    cout << "Busq 7: " << time_span.count()  << "seconds" << endl; 
 
    //Busqueda 8
    t1 = high_resolution_clock::now();
    tree.search(65703);
    t2 = high_resolution_clock::now();
    time_span = duration_cast<duration<double> >(t2 - t1);
    cout << "Busq 8: " << time_span.count()  << "seconds" << endl;
    
  
    //Busqueda 9
    t1 = high_resolution_clock::now();
    tree.search(79986);
    t2 = high_resolution_clock::now();
    time_span = duration_cast<duration<double> >(t2 - t1);
    cout << "Busq 9: " << time_span.count()  << "seconds" << endl;
  
    //Busqueda 10
    t1 = high_resolution_clock::now();
    tree.search(56345);
    t2 = high_resolution_clock::now();
    time_span = duration_cast<duration<double> >(t2 - t1);
    cout << "Busq 10: " << time_span.count()  << "seconds" << endl;
    //tree.printInOrder();
    
    int xx;
    cin >> xx;
    return 0;
}


void menu(){
    BinarySearchTree<int> tree;
    TreeNode<int> * node;
    int number;
    
    char ans = 'a';
    bool found = false;
    int preset_data[] = {9, 2, 5, 12, 7, 18, 13, 14, 1, 29, 16};
    int preset_size = sizeof preset_data / sizeof preset_data[0];

    while (ans != 'q')
    {
        std::cout << "\n== Binary Search Tree Test Menu ==\n";
        std::cout << "\tf. Fill the tree with preset data\n";
        std::cout << "\ti. Insert a new number to the tree\n";
        std::cout << "\ts. Search for a number in the tree\n";
        std::cout << "\tr. Remove a number from the tree\n";
        std::cout << "\tc. Clear the tree\n";
        std::cout << "\tp. Print the data in the tree In-order\n";
        std::cout << "\to. Print the data in the tree Post-order\n";
        std::cout << "\tt. Print the data as a tree\n";
        std::cout << "\tm. Get the smallest number in the tree\n";
        std::cout << "\tl. Get the number of leaves in the tree\n";
        std::cout << "\tq. Quit the program\n";
        std::cout << "Enter your selection: ";
        std::cin >> ans;

        switch (ans)
        {
            // Fill with preset values
            case 'f':
                std::cout << "\tInserting: ";
                for (int i=0; i<preset_size; i++)
                {
                    std::cout << preset_data[i] << " ";
                    tree.insert(preset_data[i]);
                }
                std::cout << std::endl;
                break;
            // Insert a new data node
            case 'i':
                std::cout << "\tEnter the new number to insert: ";
                std::cin >> number;
                tree.insert(number);
                break;
            // Search for data in the tree
            case 's':
                std::cout << "\tEnter the number to search for: ";
                std::cin >> number;
                found = tree.search(number);
                std::cout << "\tNumber: " << number << " was " << (found ? "found" : "NOT found") << " in the tree" << std::endl;
                break;
            // Remove an element from the tree
            case 'r':
                std::cout << "\tEnter the new number to remove: ";
                std::cin >> number;
                tree.remove(number);
                break;
            // Clear the contents of the tree
            case 'c':
                tree.clear();
                break;
            // Print the tree in order
            case 'p':
                tree.printInOrder();
                break;
            // Print the tree post order
            case 'o':
                tree.printPostOrder();
                break;
            // Print the tree "graphically"
            case 't':
                tree.printTree();
                break;
            // Get the smallest value stored in the tree
            case 'm':
                node = tree.getMin();
                if (node)
                    std::cout << "\tSmallest number: " << node->getData() << std::endl;
                else
                    std::cout << "\tApparently the tree is empty" << std::endl;
                break;
            // Count the number of leaves in the tree
            case 'l':
                number = tree.countLeaves();
                std::cout << "\tNumber of leaves: " << number << std::endl;
                break;
            // Quit the program
            case 'q':
                std::cout << "See you later" << std::endl;
                break;
            default:
                std::cout << "Invalid option. Try again ..." << std::endl;
                break;
        }
    }
}


