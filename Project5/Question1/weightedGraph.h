
#ifndef H_weightedGraph
#define H_weightedGraph

//***************************************************************
// Author: D.S. Malik
//
// class weightedGraphType
// This class specifies the operations to find the weight of the
// shortest path from a given vertex to every other vertex in a
// graph.
//****************************************************************

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cfloat>
#include "graphType.h"

using namespace std;

class weightedGraphType: public graphType
{
public:
    void createWeightedGraph();
      //Function to create the graph and the weight matrix.
      //Postcondition: The graph using adjacency lists and 
      //    its weight matrix is created.

    void shortestPath(int vertex);
      //Function to determine the weight of a shortest path 
      //from vertex, that is, source, to every other vertex 
      //in the graph.
      //Postcondition: The weight of the shortest path from vertex
      //    to every other vertex in the graph is determined.

    void printShortestDistance_Paths(int vertex);
      //Function to print the shortest weight from the vertex 
      //specified by the parameter vertex to every other vertex in 
      //the graph.
      //Postcondition: The weight of the shortest path from vertex
      //    to every other vertex in the graph is printed.

    weightedGraphType(int size = 0); 
      //Constructor
      //Postcondition: gSize = 0; maxSize = size;
      //    graph is an array of pointers to linked lists.
      //    weights is a two-dimensional array to store the weights
      //       of the edges.
      //    smallestWeight is an array to store the smallest weight
      //       from source to vertices.

    ~weightedGraphType();
      //Destructor
      //The storage occupied by the vertices and the arrays
      //weights and smallestWeight is deallocated.

protected:
    double **weights;   //pointer to create weight matrix
    double *smallestWeight; //pointer to create the array to store
                     //the smallest weight from source to vertices
	int *pred;
};

void weightedGraphType::createWeightedGraph()
{
    ifstream infile;
    char fileName[50];

    int vertex;
    int adjacentVertex;

    cout << "Enter input file name: ";
    cin >> fileName;
    cout << endl;

    infile.open(fileName);

    if (!infile)
    {
        cout << "Cannot open input file." << endl;
        return;
    }

    infile >> gSize;

    for (int index = 0; index < gSize; index++)
    {
        infile >> vertex;
        infile >> adjacentVertex;

        while (adjacentVertex != -999)
        {
            graph[vertex].insertLast(adjacentVertex);
            infile >> adjacentVertex;
        } //end while
    } // end for

    for (int i = 0; i < gSize; i++)
        for (int j = 0; j < gSize; j++)
            weights[i][j] = DBL_MAX;

    double weight;

    infile >> vertex;
    while (infile)
    {
        infile >> adjacentVertex;
        while (adjacentVertex != -999)
        {
            infile >> weight;
            weights[vertex][adjacentVertex] = weight;
            infile >> adjacentVertex;
        }
        infile >> vertex;
    }

    infile.close();
} //createWeightedGraph

void weightedGraphType::shortestPath(int vertex)
{
	bool *weightFound; //moved from below for loop
	
	for (int j = 0; j < gSize; j++)
	{
		smallestWeight[j] = weights[vertex][j];
		pred[j] = vertex;
		weightFound[j] = false;
	}
	
	//weightFound = new bool[gSize];
	pred[vertex] = vertex;
		
	//for (int j = 0; j < gSize; j++)
		//weightFound[j] = false;
		
	weightFound[vertex] = true;
	smallestWeight[vertex] = 0;
	
	for (int i = 0; i < gSize - 1; i++)
	{
		double minWeight = DBL_MAX;
		int v;
		
		for (int j = 0; j < gSize; j++)
			if (smallestWeight[j] < minWeight)
			{
				v = j;
				minWeight = smallestWeight[v];
			}
		weightFound[v] = true;
		
		for (int j = 0; j < gSize; j++)
			if (!weightFound[j])
				if (minWeight + weights[v][j] < smallestWeight[j])
				{
					smallestWeight[j] = minWeight + weights[v][j];
					pred[j] = v;
				}
	}

} //end shortestPath

void weightedGraphType::printShortestDistance_Paths(int vertex)
{
	cout << "Source Vertex: " << vertex << endl;
	cout << "Shortest distance from source to each vertex." << endl;
	cout << "Vertex Shortest_Distance" << endl;
	for (int j = 0; j < gSize; j++)
		cout << setw(4) << j << setw(12) << smallestWeight[j] << endl;
	cout << endl;
  /*cout << "The code to output the shortest distances is available on pages 705-706." << endl;
  cout << "You need to update it to output the shortest path for each vertex. " << endl;
  cout << endl;
	*/
} //end printShortestDistance

    //Constructor
weightedGraphType::weightedGraphType(int size)
                  :graphType(size)
{
    weights = new double*[size];

    for (int i = 0; i < size; i++)
        weights[i] = new double[size];

    smallestWeight = new double[size];
}

    //Destructor
weightedGraphType::~weightedGraphType()
{
    for (int i = 0; i < gSize; i++)
       delete [] weights[i];

    delete [] weights;
    delete smallestWeight;
}

#endif
