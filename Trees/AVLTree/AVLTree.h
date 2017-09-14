#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <iomanip>
#include <algorithm>
#include "TreeNode.h"

using namespace std;


template <class T>
class AVLTree {
    private:
        TreeNode<T> * root = nullptr;
        int indent_increase = 6;
        
        void recursivePrintInOrder(TreeNode<T> * _root);
        void recursivePrintTree(TreeNode<T> * _root, int indent, char branch);
        void recursiveClear(TreeNode<T> * _root);
        TreeNode<T> * recursiveInsert(TreeNode<T> * _root, TreeNode<T> * _node);
        bool recursiveSearch(TreeNode<T> * _root, T _data);
		int recursiveSearchHeight(TreeNode<T> * _root, T _data);
        TreeNode<T> * recursiveRemove(TreeNode<T> * _root, T _data);
        TreeNode<T> * recursiveGetMin(TreeNode<T> * _root);
        int recursiveCountLeaves(TreeNode<T> * _root);

		void updateHeights(TreeNode<T> * _root);
		int getBalanceFactor(TreeNode<T> * _root);
		TreeNode<T> * balance(TreeNode<T> * _root);
		TreeNode<T> * rotateLeft(TreeNode<T> * _root);
		TreeNode<T> * rotateRight(TreeNode<T> * _root);

    public:
        AVLTree () {}
        AVLTree (TreeNode<T> * _node) { root = _node; }
        ~AVLTree () { clear(); }
        
        void setRoot (TreeNode<T> * _node) { root = _node; }
        TreeNode<T> * getRoot () { return root; }
        void clear  ();
        void insert (T _data);
        void insert (TreeNode<T> * _node);
        bool search (T _data);
		int searchHeight(T _data);
        void remove (T _data);
        void printInOrder ();
        void printTree ();
        TreeNode<T> * getMin();
        int countLeaves ();
};

template <class T>
void AVLTree<T>::insert(T _data)
{
    TreeNode<T> * node = new TreeNode<T> (_data);
    insert(node);
}

template <class T>
void AVLTree<T>::insert(TreeNode<T> * _node)
{
    if (root == nullptr)
        root = _node;
    else
        recursiveInsert(root, _node);
}

template <class T>
TreeNode<T> * AVLTree<T>::recursiveInsert(TreeNode<T> * _root, TreeNode<T> * _node)
{
    // Do not insert the same data item twice
    if (_root->getData() == _node->getData())
        return _root;
    if (_node->getData() < _root->getData())
    {
        if (_root->getLeft() == nullptr)
            _root->setLeft(_node);
        else
            _root->setLeft(recursiveInsert(_root->getLeft(), _node));
    }
    else if (_node->getData() > _root->getData())
    {
        if (_root->getRight() == nullptr)
            _root->setRight(_node);
        else
            _root->setRight(recursiveInsert(_root->getRight(), _node));
    }
    return balance(_root);
}

template <class T>
void AVLTree<T>::printInOrder()
{
    std::cout << "In-order: ";
    recursivePrintInOrder(root);
    std::cout << std::endl;
}

template <class T>
void AVLTree<T>::recursivePrintInOrder(TreeNode<T> * _root)
{
    if (_root)
    {
        recursivePrintInOrder(_root->getLeft());
        std::cout << _root->getData() << " ";
        recursivePrintInOrder(_root->getRight());
    }
}

template <class T>
void AVLTree<T>::printTree()
{
    std::cout << "Tree printed vertically:" << std::endl;
    recursivePrintTree(root, indent_increase, '-');
}

template <class T>
void AVLTree<T>::recursivePrintTree(TreeNode<T> * _root, int indent, char branch)
{
    if (_root)
    {
        recursivePrintTree(_root->getRight(), indent + indent_increase, '/');
        std::cout << std::setw(indent) << branch << " " << _root->getData() << std::endl;
        recursivePrintTree(_root->getLeft(), indent + indent_increase, '\\');
    }
}

template <class T>
void AVLTree<T>::clear()
{
    recursiveClear(root);
    // Set the pointer to null to indicate an empty tree
    root = nullptr;
}

template <class T>
void AVLTree<T>::recursiveClear(TreeNode<T> * _root)
{
    if (_root == nullptr)
        return;
    // Delete the subtrees first
    recursiveClear(_root->getLeft());
    recursiveClear(_root->getRight());
    // Delete this node
    delete _root;
}

template <class T>
bool AVLTree<T>::search(T _data)
{
    return recursiveSearch(root, _data);
}

template <class T>
bool AVLTree<T>::recursiveSearch(TreeNode<T> * _root, T _data)
{
    if (_root == nullptr)
        return false;
    if (_data == _root->getData())
        return true;
    if (_data < _root->getData())
        return recursiveSearch(_root->getLeft(), _data);
    else
        return recursiveSearch(_root->getRight(), _data);
}

/*
template <class T>
int AVLTree<T>::searchHeight(T _data)
{
	return recursiveSearchHeight(root, _data);
}

template <class T>
int AVLTree<T>::recursiveSearchHeight(TreeNode<T> * _root, T _data)
{
	if (_root == nullptr)
		return NULL;
	if (_data == _root->getData())
		return _root->height;
	if (_data < _root->getData())
		return recursiveSearch(_root->getLeft(), _data);
	else
		return recursiveSearch(_root->getRight(), _data);
}*/

template <class T>
void AVLTree<T>::remove(T _data)
{
    root = recursiveRemove(root, _data);
}

template <class T>
TreeNode<T> * AVLTree<T>::recursiveRemove(TreeNode<T> * _root, T _data)
{
   if (_root == nullptr)
        return nullptr;
    else if (_data < _root->getData())
    {
        _root->setLeft(recursiveRemove(_root->getLeft(), _data));
        return _root;
    }
    else if (_data > _root->getData())
    {
        _root->setRight(recursiveRemove(_root->getRight(), _data));
        return _root;
    }
    else
    {
        // Case 1: Leaf
        if (_root->getLeft() == nullptr && _root->getRight() == nullptr)
        {
            delete _root;
            return nullptr;
        }
        // Case 2: Right child only
        else if (_root->getLeft() == nullptr)
        {
            TreeNode<T> * tmp = _root;
            _root = _root->getRight();
            delete tmp;
        }
        // Case 3: Left child only
        else if (_root->getRight() == nullptr)
        {
            TreeNode<T> * tmp = _root;
            _root = _root->getLeft();
            delete tmp;
        }
        // Case 4: Two children
        else
        {
            TreeNode<T> * tmp = recursiveGetMin(_root->getRight());
            _root->setData(tmp->getData());
            _root->setRight(recursiveRemove(_root->getRight(), tmp->getData()));
        }
    }
    return balance(_root);
}

template <class T>
TreeNode<T> * AVLTree<T>::getMin()
{
    return recursiveGetMin(root);
}

template <class T>
TreeNode<T> * AVLTree<T>::recursiveGetMin(TreeNode<T> * _root)
{
    if (_root == nullptr)
        return nullptr;
    if (_root->getLeft() == nullptr)
        return _root;
    return recursiveGetMin(_root->getLeft());
}

template <class T>
int AVLTree<T>::countLeaves()
{
    return recursiveCountLeaves(root);
}

template <class T>
int AVLTree<T>::recursiveCountLeaves(TreeNode<T> * _root)
{
    if (_root == nullptr)
        return 0;
    if (_root->getLeft() == nullptr && _root->getRight() == nullptr)
        return 1;
    return recursiveCountLeaves(_root->getLeft()) + recursiveCountLeaves(_root->getRight());
}

template<class T>
void AVLTree<T>::updateHeights(TreeNode<T> * _root)
{
	int left_height = 0;
	int right_height = 0;
	int max = 0; //IMPLEMENT SEARCH MAX

	if (_root->getLeft())
		left_height = _root->getLeft()->getHeight();
	if (_root->getRight())
		right_height = _root->getRight()->getHeight();

	_root->setHeight(std::max(left_height, right_height) + 1);
}

template<class T>
int AVLTree<T>::getBalanceFactor(TreeNode<T> * _root)
{
	int left_height = 0;
	int right_height = 0;

	if (_root->getLeft())
		left_height = _root->getLeft()->getHeight();
	if (_root->getRight())
		right_height = _root->getRight()->getHeight();

	return left_height - right_height;
}

template<class T>
TreeNode<T> * AVLTree<T>::balance(TreeNode<T> * _root)
{
	if (_root == nullptr)
		return nullptr;

	updateHeights(_root);
	int balance_factor = getBalanceFactor(_root);

	// Left is heavy
	if (balance_factor > 1) 
	{
		// Right subtree is hevier
		if (getBalanceFactor(_root->getLeft()) == -1)
		{
			//LR case
			_root->setLeft(rotateLeft(_root->getLeft()));
		}
		//LL case
		_root = rotateRight(_root);
	}

	// Right is heavy
	else if (balance_factor < -1)
	{
		// Right subtree is hevier
		if (getBalanceFactor(_root->getRight()) == 1)
		{
			//RL case
			_root->setRight(rotateRight(_root->getRight()));
		}
		//RR case
		_root = rotateLeft(_root);
	}
	return _root;
}

template<class T>
TreeNode<T> * AVLTree<T>::rotateLeft(TreeNode<T> * _root)
{
    TreeNode<T> * tmp = _root->getRight();
    _root->setRight(tmp->getLeft());
    tmp->setLeft(_root);
    updateHeights(_root);
    updateHeights(tmp);
    return tmp;
}

template<class T>
TreeNode<T> * AVLTree<T>::rotateRight(TreeNode<T> * _root)
{
    TreeNode<T> * tmp = _root->getLeft();
    _root->setLeft(tmp->getRight());
    tmp->setRight(_root);
    updateHeights(_root);
    updateHeights(tmp);
    return tmp;
}

#endif
