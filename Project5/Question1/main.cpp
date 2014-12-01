
#include <iostream>
#include <fstream>

#include "weightedGraph.h"
  
using namespace std;

int main()
{
	weightedGraphType shortestPathGraph(50);  // code available 
	cout << "Line 12" << endl;
	shortestPathGraph.createWeightedGraph();  // code available 
	cout << "Line 14" << endl;
	shortestPathGraph.shortestPath(0);        // major part available on pages 704-705; you need to update it.    
	cout << "Line 16" << endl;
	shortestPathGraph.printShortestDistance_Paths(0);  // major part available on page 705; you need to update it.
	cout << "Line 18" << endl;
	cout << endl;

	return 0;
}
