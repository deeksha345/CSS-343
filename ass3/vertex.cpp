#include <climits>

#include "vertex.h"

#include<iostream>
#include <functional>
#include <map>
#include <string>

#include "edge.h"

using  namespace std;

////////////////////////////////////////////////////////////////////////////////
// This is 80 characters - Keep all lines under 80 characters                 //
////////////////////////////////////////////////////////////////////////////////


/** Creates an unvisited vertex, gives it a label, and clears its
adjacency list.
NOTE: A vertex must have a unique label that cannot be changed. */
Vertex::Vertex(std::string label) 
{
	visited = false; 
	if (adjacencyList.find(label) == adjacencyList.end())
	{
		vertexLabel = label;
	}
}

/** @return  The label of this vertex. */
std::string Vertex::getLabel() const 
{
	return vertexLabel;
}

/** Marks this vertex as visited. */
void Vertex::visit() 
{
	visited = true;
}

/** Marks this vertex as not visited. */
void Vertex::unvisit() 
{
	visited = false;
}

/** Returns the visited status of this vertex.
@return  True if the vertex has been visited, otherwise
returns false/ */
bool Vertex::isVisited() const 
{ 
	return visited; 
}

/** Adds an edge between this vertex and the given vertex.
Cannot have multiple connections to the same endVertex
Cannot connect back to itself
@return  True if the connection is successful. */
bool Vertex::connect(const std::string& endVertex, const int edgeWeight) 
{ 
	// if vretex is trying to connect to itself 
	if (vertexLabel == endVertex) return false; 
	// if vertex is already connected to endVertex 
	if (findNeighbor(endVertex) == true) return false;

	Edge tempEdge(endVertex, edgeWeight);
	adjacencyList[endVertex] = tempEdge;
	return true; 
}

/** Removes the edge between this vertex and the given one.
@return  True if the removal is successful. */
bool Vertex::disconnect(const std::string& endVertex) 
{ 
	adjacencyList.erase(endVertex);
	return true; 
}

/** Gets the weight of the edge between this vertex and the given vertex.
@return  The edge weight. This value is zero for an unweighted graph and
is negative if the .edge does not exist */
int Vertex::getEdgeWeight(const std::string& endVertex) const 
{ 
	if(findNeighbor(endVertex) == false) return -1;
	return adjacencyList.at(endVertex).getWeight();
}

/** Calculates how many neighbors this vertex has.
@return  The number of the vertex's neighbors. */
int Vertex::getNumberOfNeighbors() const 
{ 
	auto it = adjacencyList.begin();
	int count = 0;

	while (it != adjacencyList.end())
	{
		count++;
		it++;
	}
	return count; 
}

/** Sets current neighbor to first in adjacency list. */
void Vertex::resetNeighbor() 
{
	currentNeighbor = adjacencyList.begin();
}

/** Gets this vertex's next neighbor in the adjacency list.
Neighbors are automatically sorted alphabetically via map
Returns the vertex label if there are no more neighbors
@return  The label of the vertex's next neighbor. */
std::string Vertex::getNextNeighbor() 
{ 
	if (currentNeighbor != adjacencyList.end())
	{
		string current = currentNeighbor->first;
		++currentNeighbor;
		return current;
	}
	else return getLabel();
}

/** This method checks to see if the vertex mapped to the srting argument
has a neighbor. Returns true if yes and false otherwise. */
bool Vertex::findNeighbor(const string &endVertex) const
{
	auto it = adjacencyList.begin();
	while (it != adjacencyList.end())
	{
		if (it->first == endVertex) return true;
		it++;
	}
	return false;
}

/** Sees whether this vertex is equal to another one.
Two vertices are equal if they have the same label. */
bool Vertex::operator==(const Vertex& rightHandItem) const 
{ 
	if (vertexLabel == rightHandItem.vertexLabel) return true; 
	else return false;
}

/** Sees whether this vertex is < another one.
Compares vertexLabel. */
bool Vertex::operator<(const Vertex& rightHandItem) const 
{
	if (vertexLabel < rightHandItem.vertexLabel) return true; 
	else return false; 
}

