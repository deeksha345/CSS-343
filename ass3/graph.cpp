#include <queue>
#include <stack>
#include <climits>
#include <set>
#include <iostream>
#include <fstream>
#include <map>
#include <algorithm>

#include "graph.h"

using namespace std;

/**
* A graph is made up of vertices and edges
* A vertex can be connected to other vertices via weighted, directed edge
*/


////////////////////////////////////////////////////////////////////////////////
// This is 80 characters - Keep all lines under 80 characters                 //
////////////////////////////////////////////////////////////////////////////////


/** constructor, empty graph */
Graph::Graph() 
{
	numberOfEdges = 0;
	numberOfVertices = 0;
}

/** destructor, delete all vertices and edges
only vertices stored in map
no pointers to edges created by graph */
Graph::~Graph() 
{ 
	numberOfEdges = 0;
	numberOfVertices = 0;
	auto it = vertices.begin();
	while (it != vertices.end())
	{
		delete vertices.at(it->first);
		it++;
	}
}

/** return number of vertices */
int Graph::getNumVertices() const 
{ 
	return numberOfVertices; 
}

/** return number of vertices */
int Graph::getNumEdges() const 
{ 
	return numberOfEdges; 
}

/** add a new edge between start and end vertex
if the vertices do not exist, create them
calls Vertex::connect
a vertex cannot connect to itself
or have multiple edges to another vertex */
bool Graph::add(std::string start, std::string end, int edgeWeight) 
{ 
	//insert start into vertices if not already there 
	if (findVertex(start) == nullptr)
	{
		vertices.insert(pair<string, Vertex*>(start, new Vertex(start)));
		numberOfVertices++;
	}

	//insert end into vertices if not already there 
	if (findVertex(end) == nullptr)
	{
		vertices.insert(pair<string, Vertex*>(end, new Vertex(end)));
		numberOfVertices++;
	}

	if (vertices[start]->connect(vertices[end]->getLabel(), edgeWeight) == true)
		return true;
	else return false;
}

/** return weight of the edge between start and end
returns INT_MAX if not connected or vertices don't exist */
int Graph::getEdgeWeight(std::string start, std::string end) const 
{ 
	if (vertices.find(start) != vertices.end() ||
		vertices.find(end) != vertices.end() ||
		vertices.at(start)->findNeighbor(vertices.at(end)->getLabel()) == false) 
		return vertices.at(start)->getEdgeWeight(vertices.at(end)->getLabel());
	return INT_MAX; 
}

/** read edges from file
the first line of the file is an integer, indicating number of edges
each edge line is in the form of "string string int"
fromVertex  toVertex    edgeWeight */
void Graph::readFile(std::string filename) 
{ 
	ifstream myFile;
	myFile.open(filename);

	if (myFile.is_open())
	{
		myFile >> numberOfEdges;
		for (int i = 0; i < numberOfEdges; i++)
		{
			string fromVertex;
			string toVertex;
			int edgeWeight;
			myFile >> fromVertex >> toVertex >> edgeWeight;
			add(fromVertex, toVertex, edgeWeight);
		}
	}
	else return;

	myFile.close();
}

/** helper for depthFirstTraversal */
void Graph::depthFirstTraversalHelper(Vertex* startVertex,
	void visit(const std::string&))
{
	auto it = vertices.begin();
	while (it != vertices.end())
	{
		it->second->resetNeighbor();
		it++;
	}

	stack<string> s;
	s.push(startVertex->getLabel()); // add startVertex to stack 
	visit(startVertex->getLabel()); // visit it 
	vertices.at(startVertex->getLabel())->visit(); // mark it as visited 

	while (!s.empty())
	{
		// set neighbor to the next neighbor of the vertex at top of stack
		string neighbor = vertices.at(s.top())->getNextNeighbor();

		//if neighbor has not been visited 
		if (neighbor != s.top() && vertices.at(neighbor)->isVisited() == false)
		{
			s.push(neighbor); // push it
			visit(neighbor); // visit it 
			vertices.at(neighbor)->visit(); // and mark it as visited 
		}
		else
			s.pop();
	}
}

/** depth-first traversal starting from startLabel
call the function visit on each vertex label */
void Graph::depthFirstTraversal(std::string startLabel,
	void visit(const std::string&)) 
{
	unvisitVertices();
	depthFirstTraversalHelper(vertices.at(startLabel), visit);
}

/** helper for breadthFirstTraversal */
void Graph::breadthFirstTraversalHelper(Vertex*startVertex, 
	void visit(const std::string&))
{
	auto it = vertices.begin();
	while (it != vertices.end()) 
	{
		it->second->resetNeighbor();
		it++;
	}

	queue<string> q;
	// set current to string of startVertex
	string current = startVertex->getLabel(); 

	// if current hasnt been visited 
	if (vertices.at(current)->isVisited() == false)
	{
		q.push(current); // push it into queue 
		visit(startVertex->getLabel()); // visit it 
		startVertex->visit(); // mark it as visited
	}

	while (!q.empty())
	{
		q.pop();
		// execute for the number of neighbors of current vertex 
		for (int i = 0; i < vertices.at(current)->getNumberOfNeighbors(); i++)
		{
			// set current vertex to its neighbor 
			current = vertices.at(current)->getNextNeighbor(); 
			// if current hasnt been visited 
			if (vertices.at(current)->isVisited() == false)
			{
				visit(current); //visit it 
				vertices.at(current)->visit(); // mark it as visited 
				q.push(current); // push it 
			}
		}
	}
}

/** breadth-first traversal starting from startLabel
call the function visit on each vertex label */
void Graph::breadthFirstTraversal(std::string startLabel,
	void visit(const std::string&)) 
{
	unvisitVertices();
	breadthFirstTraversalHelper(vertices.at(startLabel), visit);
}

/** find the lowest cost from startLabel to all vertices that can be reached
using Djikstra's shortest-path algorithm
record costs in the given map weight
weight["F"] = 10 indicates the cost to get to "F" is 10
record the shortest path to each vertex using given map previous
previous["F"] = "C" indicates get to "F" via "C"

cpplint gives warning to use pointer instead of a non-const map
which I am ignoring for readability */
void Graph::djikstraCostToAllVertices(
	std::string startLabel,
	std::map<std::string, int>& weight,
	std::map<std::string, std::string>& previous)
{
	priority_queue<pair<int, string>, vector<pair<int, string>>, 
		greater<pair<int, string>>> pq;
	vector<string> vertexSet;

	for (int i = vertices.at(startLabel)->getNumberOfNeighbors(); i > 0; i--)
	{
		string neighbor = vertices.at(startLabel)->getNextNeighbor();
		weight[neighbor] = vertices.at(startLabel)->getEdgeWeight(neighbor);
		previous[neighbor] = startLabel;
		pq.push(pair<int, string>(weight[neighbor], neighbor));
	}
	vertexSet.push_back(startLabel);

	while (!pq.empty())
	{
		string minVertex = pq.top().second;
		vertexSet.push_back(minVertex);
		cout << "minVertex: " << minVertex << endl;
		pq.pop();

		// if minVertex isn't in vertexSet already 
		if (find(vertexSet.begin(), vertexSet.end(), minVertex) == 
			vertexSet.end())
		{
			cout << "fc" << endl;
			for (int i = vertices.at(minVertex)->getNumberOfNeighbors(); i > 0;
				i--)
			{
				cout << "i: " << i << endl;
				string neighbor = vertices.at(startLabel)->getNextNeighbor();
				int v2ucost = vertices.at(minVertex)->getEdgeWeight(neighbor);
				if (weight.find(neighbor) != weight.end())
				{
					// we could not get to u before, this is the only path
					weight[neighbor] = weight[minVertex] + v2ucost;
					previous[neighbor] = minVertex;
					pq.push(pair<int, string>(weight[neighbor], neighbor));
				}
				else
				{
					// we could not get to u before, is going via v better?
					if (weight[neighbor] > weight[minVertex] + v2ucost)
					{
						// yes it is better
						weight[neighbor] = weight[minVertex] + v2ucost;
						previous[neighbor] = minVertex;
						pq.push(pair<int, string>(weight[neighbor], neighbor));
					}
					// else no previous route was better, do nothing
				}
			}
		}
	}
}

/** mark all verticies as unvisited */
void Graph::unvisitVertices() 
{
	auto it = vertices.begin();
	while (it != vertices.end())
	{
		it->second->unvisit();
		it++;
	}
}

/** find a vertex, if it does not exist return nullptr */
Vertex* Graph::findVertex(const std::string& vertexLabel) const 
{ 
	if (vertices.find(vertexLabel) != vertices.end()) 
		return vertices.at(vertexLabel); 
	return nullptr; 
}

/** find a vertex, if it does not exist create it and return it */
Vertex* Graph::findOrCreateVertex(const std::string& vertexLabel) 
{ 
	if (vertices.find(vertexLabel) != vertices.end())
		return vertices[vertexLabel];
	else
	{
		Vertex *temp = new Vertex(vertexLabel);
		numberOfVertices++;
		return temp;
	}
		
}