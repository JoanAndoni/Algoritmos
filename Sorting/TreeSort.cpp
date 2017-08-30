#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <math.h>
//#include <chrono>

using namespace std;
//using namespace chrono;

struct Node
{
    int key;
    struct Node *left, *right;
};
 
// A utility function to create a new BST Node
struct Node *newNode(int item)
{
    struct Node *temp = new Node;
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}
 
// Stores inoder traversal of the BST
// in arr[]
void storeSorted(Node *root, int arr[], int &i)
{
    if (root != NULL)
    {
        storeSorted(root->left, arr, i);
        arr[i++] = root->key;
        storeSorted(root->right, arr, i);
    }
}
 
/* A utility function to insert a new
   Node with given key in BST */
Node* insert(Node* node, int key)
{
    /* If the tree is empty, return a new Node */
    if (node == NULL) return newNode(key);
 
    /* Otherwise, recur down the tree */
    if (key < node->key)
        node->left  = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
 
    /* return the (unchanged) Node pointer */
    return node;
}
 
// This function sorts arr[0..n-1] using Tree Sort
void treeSort(int arr[], int n)
{
    struct Node *root = NULL;
 
    // Construct the BST
    root = insert(root, arr[0]);
    for (int i=1; i<n; i++)
        insert(root, arr[i]);
 
    // Store inoder traversal of the BST
    // in arr[]
    int i = 0;
    storeSorted(root, arr, i);
}


int main() 
{
	int* array = new int[1000000];
    int n, c, d, swap;

	cout << "Enter number of elements" << endl;
	cin >> n;
//	time_t start, end;

	cout << "The " << n << " integers will be generated automatically" << endl;

	for (c = 0; c < n; c++)
		array[c] = (rand() % 1000);       

//	time(&start); //START THE CLOCK
//  high_resolution_clock::time_point t1 = high_resolution_clock::now();//Start chrono
    clock_t cl = clock();

	treeSort(array, n);

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