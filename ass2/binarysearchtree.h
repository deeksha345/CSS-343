// Yusuf Pisan pisan@uw.edu
// 15 Jan 2018

// BinarySearchTree class
// Creates a BST to store values
// Uses BinaryNode which holds the data
// Uses templates to store any type of data
// binarysearchtreee.cpp file is included at the bottom of the .h file
// binarysearchtreee.cpp is part of the template, cannot be compiled separately
//
//Assumptions
//1. the array passed into readTree function is already sorted in ascending order 
//2. rebalance isnt called on an empty tree
//3. an empty tree has rootPtr == nullptr 
//4. add functions adds the new item in the tree so that the binary search tree property
//is upheld 
//5. 

#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include "binarynode.h"

using namespace std;

template<class ItemType>
class BinarySearchTree {
public:
	// constructor, empty tree
	BinarySearchTree();
	// constructor, tree with root
	explicit BinarySearchTree(const ItemType&);
	// copy constructor
	BinarySearchTree(const BinarySearchTree<ItemType>&);
	// destructor
	virtual ~BinarySearchTree();
	// true if no nodes
	bool isEmpty() const;
	// 0 if empty, 1 if only root, otherwise
	// max height of subtrees + 1
	int getHeight() const;
	// number of nodes and data in tree
	int getNumberOfNodes() const;
	//overloaded operator= method
	BinarySearchTree<ItemType> operator=(const BinarySearchTree<ItemType>&);
	// add a new item
	// return true if succesasfull
	// false if item already in tree or some other reason to fail
	bool add(const ItemType&);
	// true if item is in tree
	bool contains(const ItemType&) const;
	// dispaly a sideways ascii representation of tree
	void displaySideways() const;
	// inorder traversal: left-root-right
	// takes a function that takes a single parameter of ItemType
	// the function can modify the data in tree, but the
	// tree structure is not changed
	void inorderTraverse(void visit(ItemType &)) const;
	// create dynamic array, copy all the items to the array
	// and then read the array to re-create this tree
	void rebalance();
	// delete all nodes in tree and set root to nullptr
	void clear();
	// given an array of length n
	// create this tree to have all items in that array
	// with the minimum height
	// helper function for rebalance 
	bool readTree(ItemType[], int); 
	// trees are equal if they have the same structure
	// AND the same item values at all the nodes
	bool operator==(const BinarySearchTree<ItemType> &) const;
	// not == to each other
	bool operator!=(const BinarySearchTree<ItemType> &) const;
private:
	// root of the tree
	BinaryNode<ItemType>* rootPtr{ nullptr };
	//keeps track of number of nodes in tree
	int numNodes; 
	//add a new node, helper function for add
	BinaryNode<ItemType>* placeNode(BinaryNode<ItemType>*, BinaryNode<ItemType>*);
	// find the node with given vale, helper function for contains
	BinaryNode<ItemType>* findNode(BinaryNode<ItemType>*, const ItemType&) const;
	// helper function for displaySideways to work recursively
	void sideways(BinaryNode<ItemType>*, int) const;
	//recursive helper function for copying tree
	BinaryNode<ItemType>* copyHelper(BinaryNode<ItemType>*, const BinaryNode<ItemType>*);
	//recursive helper function for operator==
	bool isMatching(const BinaryNode<ItemType>*, BinaryNode<ItemType>*) const;
	//recursive helper function for deleting tree
	void deleteRecursive(BinaryNode<ItemType>*); 
	//recursive helper function for getting height of tree 
	int getHeightHelper(const BinaryNode<ItemType>*) const;
	//recursive helper function for readTree 
	void makeBalancedTree(ItemType[], int, int); 
	//recursive helper function for inorderTraverse
	void inorderTraverseHelper(void visit(ItemType &), BinaryNode<ItemType>*) const;
};

#include "binarysearchtree.cpp" 
#endif 
