
#include <iostream>
#include <fstream>
#include "graphType.h"
#include "topologicalOrder.h"

using namespace std;
 
int main()
{
	topologicalOrderType myGraph(50);

	myGraph.createGraph();
	cout << endl;
	
	cout << "Depth First Topological order: ";
	myGraph.dfTopOrder();
	cout << endl;

	return 0;
}