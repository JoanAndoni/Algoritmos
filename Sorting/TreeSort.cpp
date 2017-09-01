#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <math.h>
//#include <chrono>

using namespace std;
//using namespace chrono;

struct Node{
	int key;
	struct Node *left, *right;
};

struct Node *newNode(int item){
	struct Node *temp = new Node;
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}

void storeSorted(Node *root, int vec[], int &i){
	if (root != NULL){
		storeSorted(root->left, vec, i);
		vec[i++] = root->key;
		storeSorted(root->right, vec, i);
	}
}

Node* insert(Node* node, int key){
	/* If the tree is empty, return a new Node */
	if (node == NULL) return newNode(key);

	/* Otherwise, recur down the tree */
	if (key < node->key)
		node->left = insert(node->left, key);
	else if (key >= node->key)
		node->right = insert(node->right, key);

	/* return the (unchanged) Node pointer */
	return node;
}

void treeSort(int vec[] ,int tam ){
	struct Node *root = NULL;

	// Construct the BST
	root = insert(root, vec[0]);
	for (int i = 1; i<tam; i++)
		insert(root, vec[i]);

	// Store inoder traversal of the BST
	// in arr[]
	int i = 0;
	storeSorted(root, vec, i);
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
	/*
	cout << "Sorted list in ascending order:\n";

	for (c = 0; c < n; c++)
		cout << array[c] << endl;
*/
//  auto duration = duration_cast<seconds>(t2 - t1).count(); //Total time
//	double dif = difftime(end, start);

//  cout << "El tiempo de ejecucion fue de: " << duration << " milisegundos" << endl; //Doesnt work in raspberyPi cause libraries
//	cout << "El tiempo de ejecucion fue de: " << dif << " segundos" << endl;
    cout << "El tiempo de ejecucion fue de: " << (clock()-cl*1000/CLOCKS_PER_SEC) << " ms" << endl;

	return 0;
}