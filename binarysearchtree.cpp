#include<iostream>
#include<string>

using namespace std;

// dynamic array used for addToArray
template<class ItemType>
static ItemType* currentArray;

// private data member used for addToArray
static int currentIndex;

// helper function for rebalance
template<class ItemType>
static void addToArray(ItemType& item)
{
	currentArray<ItemType>[currentIndex++] = item;
}

// default constructor 
template<class ItemType>
BinarySearchTree<ItemType>::BinarySearchTree()
{
	rootPtr = nullptr;
	numNodes = 0;
	currentIndex = 0;
}

// constructor creates a new binary search tree with root item 
// equal to rootItem and sets left and right child poitners to nullptr
template<class ItemType>
BinarySearchTree<ItemType>::BinarySearchTree(const ItemType& rootItem)
{
	rootPtr = new BinaryNode<ItemType>;
	rootPtr->setItem(rootItem);
	rootPtr->setLeftChildPtr(nullptr);
	rootPtr->setRightChildPtr(nullptr);
	numNodes = 1;
	currentIndex = 0;
}

// copy constructor 
template<class ItemType>
BinarySearchTree<ItemType>::BinarySearchTree(const BinarySearchTree<ItemType>& bst)
{
	rootPtr = copyHelper(rootPtr, bst.rootPtr);
	currentIndex = 0;
}

// overloaded operator=  
template<class ItemType>
BinarySearchTree<ItemType> BinarySearchTree<ItemType>::operator=(const 
	BinarySearchTree<ItemType> &bst)
{
	if (this == &bst)
		return *this;
	clear();
	rootPtr = copyHelper(rootPtr, bst.rootPtr);
	currentIndex = 0;
	return *this;
}

// recursive helper function for copy constructor and operator=
template<class ItemType>
BinaryNode<ItemType>* BinarySearchTree<ItemType>::copyHelper(
	BinaryNode<ItemType> *node, const BinaryNode<ItemType> *toCopy)
{
	// base case 
	if (toCopy == nullptr) //node = nullptr;
		return nullptr;
	else
	{
		//allocating memory for new BinaryNode
		node = new BinaryNode<ItemType>();
		node->setItem(toCopy->getItem());
		numNodes++;
		// copies left subtree 
		node->setLeftChildPtr(copyHelper(node->getLeftChildPtr(), toCopy->getLeftChildPtr()));
		// copies rigth subtree
		node->setRightChildPtr(copyHelper(node->getRightChildPtr(), toCopy->getRightChildPtr()));
		return node;
	}
}

// destructor 
template<class ItemType>
BinarySearchTree<ItemType>::~BinarySearchTree()
{
	deleteRecursive(rootPtr);
	rootPtr = nullptr;
}

// method clears all values in the tree and sets root to null
template<class ItemType>
void BinarySearchTree<ItemType>::clear()
{
	if (rootPtr != nullptr)
	{
		deleteRecursive(rootPtr);
	}
	rootPtr = nullptr;
}

// recursive helper function for clear and the destructor 
template<class ItemType>
void BinarySearchTree<ItemType>::deleteRecursive(BinaryNode<ItemType> *node)
{
	if (node != nullptr)
	{
		// deletes left subtree
		if (node->getLeftChildPtr() != nullptr)
		{
			deleteRecursive(node->getLeftChildPtr());
			node->setLeftChildPtr(nullptr);
		}
		// deletes right subtree 
		if (node->getRightChildPtr() != nullptr)
		{
			deleteRecursive(node->getRightChildPtr());
			node->setRightChildPtr(nullptr);
		}
		// deletes current node 
		delete node;
		numNodes--;
	}
	else
	{
		numNodes = 0;
	}
}

// returns true if tree is empty and false otherwise 
template<class ItemType>
bool BinarySearchTree<ItemType>::isEmpty() const
{
	return rootPtr == nullptr;
}

// returns height of the tree
template<class ItemType>
int BinarySearchTree<ItemType>::getHeight() const
{
	if (rootPtr == nullptr) return 0;
	return getHeightHelper(rootPtr);
}

// recursive helper function that calculates height of the tree
template<class ItemType>
int BinarySearchTree<ItemType>::getHeightHelper(const BinaryNode<ItemType> *node) const
{
	int leftHeight = 0;
	int rightHeight = 0;
	
	// base case
	if (node != nullptr && node->getLeftChildPtr() == nullptr && 
		node->getRightChildPtr() == nullptr)
	{
		return 1;
	}
	else if (node == nullptr) return 0;
	else
	{
		// calculate height of left subtree
		leftHeight = getHeightHelper(node->getLeftChildPtr()) + 1;
		// calculate height of right subtree
		rightHeight = getHeightHelper(node->getRightChildPtr()) + 1;
	}

	// return max height 
	if (leftHeight > rightHeight) return leftHeight;
	return rightHeight;
}

// returns number of nodes in this tree
template<class ItemType>
int BinarySearchTree<ItemType>::getNumberOfNodes() const
{
	return numNodes;
}

// recursive helper function for operator== returns true if trees 
// are matching and false otherwise 
template<class ItemType>
bool BinarySearchTree<ItemType>::isMatching(const BinaryNode<ItemType> *node, 
	BinaryNode<ItemType> *otherNode) const
{
	bool leftTreeEqual = false;
	bool rightTreeEqual = false;

	if (node->getLeftChildPtr() != nullptr && otherNode->getLeftChildPtr() != nullptr)
	{
		// traverse left subtree
		leftTreeEqual = isMatching(node->getLeftChildPtr(), otherNode->getLeftChildPtr());
		if (node->getItem() != otherNode->getItem())
			return false;
	}
	else if (node->getLeftChildPtr() != otherNode->getLeftChildPtr()) // only one is null
		return false;
	else leftTreeEqual = true;

	if (node->getRightChildPtr() != nullptr && otherNode->getRightChildPtr() != nullptr)
	{
		// traverse right subtree
		rightTreeEqual = isMatching(node->getRightChildPtr(), otherNode->getRightChildPtr());
		if (node->getItem() != otherNode->getItem())
			return false;
	}
	else if (node->getRightChildPtr() != otherNode->getRightChildPtr()) // only one is null
		return false;
	else rightTreeEqual = true; 

	return (leftTreeEqual && rightTreeEqual);
}

// overloaded operator== returns true if trees are equal and false otherwise 
template<class ItemType>
bool BinarySearchTree<ItemType>::operator==(const BinarySearchTree<ItemType> &bst) const
{
	if (getNumberOfNodes() != bst.getNumberOfNodes()) 
		return false;
	else if (rootPtr == nullptr && bst.rootPtr != nullptr) return false;
	else if (rootPtr != nullptr && bst.rootPtr == nullptr) return false;

	return isMatching(rootPtr, bst.rootPtr);
}

// returns true if trees arent equal and false otherwise 
template<class ItemType>
bool BinarySearchTree<ItemType>::operator!=(const BinarySearchTree<ItemType> &bst) const
{
	return !(*this == bst);
}


// recursive helper function for add 
template<class ItemType>
BinaryNode<ItemType>* BinarySearchTree<ItemType>::placeNode(
	BinaryNode<ItemType> *subTreePtr, BinaryNode<ItemType> *newNodePtr)
{
	if (subTreePtr == nullptr)
		return newNodePtr;

	// first base case 
	if (newNodePtr->getItem() > subTreePtr->getItem() && 
		subTreePtr->getRightChildPtr() == nullptr)
	{
		subTreePtr->setRightChildPtr(newNodePtr);
		numNodes++;
		return newNodePtr;
	}
	// second base case 
	else if (newNodePtr->getItem() < subTreePtr->getItem() && 
		subTreePtr->getLeftChildPtr() == nullptr)
	{
		subTreePtr->setLeftChildPtr(newNodePtr);
		numNodes++;
		return newNodePtr;
	}

	if (newNodePtr->getItem() > subTreePtr->getItem()) // traverse right subtree
		return placeNode(subTreePtr->getRightChildPtr(), newNodePtr);
	else // traverse left subtree
		return placeNode(subTreePtr->getLeftChildPtr(), newNodePtr);
}

// method used to add item to this tree 
template<class ItemType>
bool BinarySearchTree<ItemType>::add(const ItemType& item) 
{
	if (contains(item))
		return false;

	// if tree is empty 
	if (rootPtr == nullptr)
	{
		rootPtr = new BinaryNode<ItemType>;
		rootPtr->setItem(item);
		rootPtr->setLeftChildPtr(nullptr);
		rootPtr->setRightChildPtr(nullptr);
		numNodes = 1;
		return true;
	}

	BinaryNode<ItemType> *newNode = new BinaryNode<ItemType>(item);
	if (item == placeNode(rootPtr, newNode)->getItem())
	{
		newNode->setLeftChildPtr(nullptr);
		newNode->setRightChildPtr(nullptr);
		return true;
	}

	// if item not found and not added to tree 
	delete newNode;
	return false; 
}

// recursive helper function for contains 
template<class ItemType>
BinaryNode<ItemType>* BinarySearchTree<ItemType>::findNode(
	BinaryNode<ItemType> *subTreePtr, const ItemType &target) const
{
	if (subTreePtr == nullptr)
		return nullptr;

	// base case
	if (subTreePtr->getItem() == target)
		return subTreePtr;
	else if (target > subTreePtr->getItem() &&
		subTreePtr->getRightChildPtr() != nullptr) // traverse right subtree
	{
		return findNode(subTreePtr->getRightChildPtr(), target);
	}
	else if (subTreePtr->getLeftChildPtr() != nullptr) // traverse left subtree 
		return findNode(subTreePtr->getLeftChildPtr(), target);
	return nullptr; // if not found 
}

// checks if this tree contains item 
template<class ItemType>
bool BinarySearchTree<ItemType>::contains(const ItemType& item) const 
{
	BinaryNode<ItemType> *newNode = findNode(rootPtr, item);
	if (newNode == nullptr)
		return false;

	ItemType otherItem = newNode->getItem();
	return item == otherItem;
}

// recursive helper function for readTree 
template<class ItemType> 
void BinarySearchTree<ItemType>::makeBalancedTree(ItemType arr[], 
	int startIndex, int endIndex)
{
	// base case 
	if (startIndex >= endIndex)
		add(arr[startIndex]);
	else
	{
		add(arr[(startIndex + endIndex) / 2]);
		makeBalancedTree(arr, startIndex, endIndex / 2 - 1);
		makeBalancedTree(arr, ((startIndex + endIndex) / 2) + 1, endIndex);
	}
}

// recursive helper function for rebalance 
template<class ItemType>
bool BinarySearchTree<ItemType>::readTree(ItemType arr[], int n)
{
	if (arr == nullptr) return false;

	clear();
	makeBalancedTree(arr, 0, n - 1);
	return true;
}

// rebalance this tree
template<class ItemType>
void BinarySearchTree<ItemType>::rebalance() 
{
	int lengthOfArray = getNumberOfNodes();

	// traverse this tree inorder and add to current array the items in sorted order
	currentArray<ItemType> = new ItemType[lengthOfArray];
	inorderTraverse(addToArray);

	//readTree(anArray, lengthOfArray);
	readTree(currentArray<ItemType>, lengthOfArray);
	delete[] currentArray<ItemType>;
	currentIndex = 0;
}

// traverse the items of this tree inorder: left-root-right 
template<class ItemType>
void BinarySearchTree<ItemType>::inorderTraverse(void visit(ItemType &)) const
{
	inorderTraverseHelper(visit, rootPtr);
}

// recursive helper function for inorderTraverse 
template<class ItemType>
void BinarySearchTree<ItemType>::inorderTraverseHelper(void visit(ItemType &), 
	BinaryNode<ItemType> *subTreePtr) const
{
	if (!isEmpty())
	{
		// traverse left subtree
		if (subTreePtr->getLeftChildPtr() != nullptr)
			inorderTraverseHelper(visit, subTreePtr->getLeftChildPtr());

		// make temp variable of type ItemType and visit node with that item 
		ItemType temp = subTreePtr->getItem();
		visit(temp);

		// traverse right subtree
		if (subTreePtr->getRightChildPtr() != nullptr)
			inorderTraverseHelper(visit, subTreePtr->getRightChildPtr());
	}
}


// based on code from Zander
// display ascii version of tree sideways
template<class ItemType>
void BinarySearchTree<ItemType>::displaySideways() const 
{
	sideways(rootPtr, 0);
}

// display ascii version of tree sideways recursively
template<class ItemType>
void BinarySearchTree<ItemType>::sideways(BinaryNode<ItemType>* current, int level) const
{
	if (current != NULL)
	{
		level++;
		sideways(current->getRightChildPtr(), level);

		// indent for readability, 4 spaces per depth level
		for (int i = level; i >= 0; i--)
		{
			cout << "    ";
		}

		cout << current->getItem() << endl;        // display information of object
		sideways(current->getLeftChildPtr(), level);
	}
}