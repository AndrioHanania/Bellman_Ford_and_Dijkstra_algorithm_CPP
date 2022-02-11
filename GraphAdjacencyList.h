#pragma once
#include "Graph.h"

namespace vrt
{
	class GraphAdjacencyList : public Graph
	{
	 private:
		
		VertexArray		arr;

	 public:
		
		 //c`tor
		GraphAdjacencyList(int n);
		GraphAdjacencyList(ifstream& inFile, int num);
		
		//copy c`tor
		GraphAdjacencyList(const GraphAdjacencyList& G);

		//d`tor
		virtual ~GraphAdjacencyList() {}

		//Initializing the graph
		virtual void MakeEmptyGraph(int n);

		//return true if there is a edge between u and v, otherwise false
		virtual bool IsAdjacent(int u, int v);

		//return linked list* with all the neighbors of u
		virtual LinkedList* GetAdjList(int u) { return &arr[u]; }

		//Add a edge to the Graph from u to v with the weight
		virtual void AddEdge(int u, int v, float weight);

		//Remove edge from u to v
		virtual void RemoveEdge(int u, int v);

		//Display the Graph
		virtual void DisplayGraph() { arr.printArr(); }

		//return number Of Vertex in graph
		virtual int getNumberOfVertex() { return arr.getPhsSize(); }

		virtual int getType();

		//fill the graph with information from the file
		void fillGraph(ifstream& inFile);

		//--operators--//
		const GraphAdjacencyList& operator=(const GraphAdjacencyList& other);
	};
}

