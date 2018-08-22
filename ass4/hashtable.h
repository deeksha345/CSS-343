#ifndef HASHTABLE_H
#define HASHTABLE_H

#include<map>
#include<iostream>
#include<vector>
using namespace std;


template <class keyItemType, class valueItemType>
class Hashtable {
public:
	// default constructor 
	Hashtable() {
		numberOfKeys = 0;
	}

	// constructor than takes in arguments for the key and value 
	Hashtable(const keyItemType key, const valueItemType  value) {
		numberOfKeys++;
		keysMap[key] = value;
		allKeys.push_back(key);
	}

	// returns true if hashtable has no keys, and returns false otherwise.
	bool isEmpty() {
		if (numberOfKeys == 0) {
			return true;
		}
		else {
			return false;
		}
	}

	// returns number of keys available.
	int getNumberOfEntries() {
		return numberOfKeys;
	}

	// add checks if key is not part of the keys dynamic array, if so, it 
	// adds it adds value in second parameter in the valueType dynamic array, 
	// and then assigns the value to the key in first parameter returns true 
	// if process is successful, returns false if key is already in the keys 
	// dynamic array.
	bool add(const keyItemType& key, const valueItemType& value) {
		if (keysMap.count(key) == 0) {
			numberOfKeys++;
			keysMap[key] = value;
			allKeys.push_back(key);
			return true;
		}
		else {
			return false;
		}

	}

	// It removes the key from the keytype dynamic array.
	// returns true if process is successful, returns false if keytype couldn't 
	// be found in the 
	// keyType dynamic array by deleting both the key and value.
	bool remove(const keyItemType& key) {

		if (keysMap.count(key) == 1) {
			keysMap.erase(key);
			removeKeyFromVector(key);
			return true;
		}
		else {
			return false;
		}
	}

	// it sets number of keys in hashtable to zero, it clears the hashtable by 
	// looping through all elements and calling delete on every key 
	// and its value
	void clear() {
		keysMap.clear();
		allKeys.clear();
	}

	// it returns value from value dynamic array that corresponds to the input 
	// variable as a key.
	valueItemType getValue(const keyItemType& key) {
		return keysMap[key];
	}
	// it sets value from value dynamic array that corresponds to the input 
	// variable as a key.
	void setValue(const keyItemType& key, const valueItemType& value) {
		keysMap.erase(key);
		keysMap[key] = value;
	}
	// contain returns true if input is found in the keyType dynamic array, 
	// and returns false otherwise.
	bool contain(const keyItemType& key) {
		if (keysMap.count(key) == 1) {
			return true;
		}
		else {
			return false;
		}
	}
	
	// returns the vector that stores all the keys 
	std::vector<keyItemType> getAllKeys() {
		return allKeys;
	}
	// loops through the vector of keys and prints our all the key values 
	void printAllKeys() {
		for (int i = 0; (unsigned)i < allKeys.size(); i++) {
			cout << allKeys[i] << endl;
		}
	}
	// removes the key passed in for input from the vector that stores all keys
	void removeKeyFromVector(keyItemType input) {
		for (int i = 0; (unsigned)i < allKeys.size(); i++) {
			if (allKeys[i] == input) {
				allKeys.erase(allKeys.begin() + i);
			}
		}
	}
private:
	// map that stores all the key value pairs 
	std::map<keyItemType, valueItemType> keysMap;
	std::vector<keyItemType> allKeys; // stores all the keys 
	//int that represents length of Array
	int numberOfKeys;
};

#endif // HASHTABLE_H
