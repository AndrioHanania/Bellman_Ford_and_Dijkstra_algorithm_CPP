#pragma once
#include "Graph.h"

#define INVALIDWEIGHT -1

namespace vrt
{
	class NeighborlyMatrix : public Graph
	{
	 private:
		int m_NumberOfVertex;
		float** m_NeighborlyMatrix;

	public:
		
		//c`tor
		NeighborlyMatrix(int n);
		NeighborlyMatrix(ifstream& inFile, int num);
		
		//copy c`tor
		NeighborlyMatrix(NeighborlyMatrix& other);
		
		//d`tor
		virtual ~NeighborlyMatrix();

		//fill the graph with information from the file
		void fillGraph(ifstream& inFile);
		
		//Initializing the graph
		virtual void MakeEmptyGraph(int n);
		
		//return true if there is a edge between u and v, otherwise false
		virtual bool IsAdjacent(int u, int v);
		
		//return linked list* with all the neighbors of u
		virtual LinkedList* GetAdjList(int u);

		//Add a edge to the graph from u to v with the weight
		virtual void AddEdge(int u, int v, float weight);
		
		//Remove edge from u to v
		virtual void RemoveEdge(int u, int v);

		//Display the Graph
		virtual void DisplayGraph();

		//--Getters--//
		
		//return number Of Vertex in graph
		virtual int getNumberOfVertex();

		virtual int getType();
		
		//--operators--//
		float* operator[](int index);
		const NeighborlyMatrix& operator=(const NeighborlyMatrix& other);
	};
}
