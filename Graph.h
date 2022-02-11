#pragma once
#include "VertexArray.h"

#define MATRIX 0
#define ADJCENCY 1

namespace vrt
{
	class Graph
	{
	 public:

		//c'tor
		Graph() {}
		
		//d'tor
		virtual ~Graph() {}
		
		//Initializing the graph
		virtual void MakeEmptyGraph(int n) = 0;

		//Add a edge to the graph from u to v with the weight
		virtual void AddEdge(int u, int v, float weight) = 0;

		//return true if there is a edge between u and v, otherwise false
		virtual bool IsAdjacent(int u, int v) = 0;

		//Remove edge from u to v
		virtual void RemoveEdge(int u, int v) = 0;

		//return linked list* with all the neighbors of u
		virtual LinkedList* GetAdjList(int u) = 0;

		//Display the Graph
		virtual void DisplayGraph() = 0;

		//return number Of Vertex in graph
		virtual int getNumberOfVertex() = 0;

		virtual int getType() = 0;
	};
}

