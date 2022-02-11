#include "GraphAdjacencyList.h"

namespace vrt
{
	GraphAdjacencyList::GraphAdjacencyList(int n) : arr(n)
	{
	}

	GraphAdjacencyList::GraphAdjacencyList(const GraphAdjacencyList& G) :
		arr(G.arr.getPhsSize())
	{
		for (int i = 0; i < G.arr.getPhsSize(); i++)
		{
			arr[i] = G.arr[i];
		}
	}
	GraphAdjacencyList::GraphAdjacencyList(ifstream& inFile, int num) : arr(num)
	{
		MakeEmptyGraph(num);
		try
		{
			fillGraph(inFile);
		}
		catch (const char* exception)
		{
			throw exception;
		}
	}

	int GraphAdjacencyList::getType()
	{
		return ADJCENCY;
	}

	void GraphAdjacencyList::fillGraph(ifstream& inFile)
	{
		int u, v;
		float weight;
		while (!inFile.eof())
		{
			if (inFile.eof()) break;			
			inFile >> u;
			inFile >> v;
			inFile >> weight;			
			try
			{
				AddEdge(u - 1, v, weight);
			}
			catch (const char* exception)
			{
				throw exception;
			}
		}
	}

	void GraphAdjacencyList::MakeEmptyGraph(int n)
	{
		for (int i = 0; i < n; i++)
		{
			arr[i].makeListEmpty();
		}
	}
	
	bool GraphAdjacencyList::IsAdjacent(int u, int v)
	{
		return arr[u].getNodeById(v) != nullptr ? true : false;
	}
	
	void GraphAdjacencyList::AddEdge(int u, int v, float weight)
	{
		if (IsAdjacent(u, v))
		{
			throw "ERROR: an edge already exists";
		}

		if (u > arr.getPhsSize()-1 || u < 0 ||
			v > arr.getPhsSize() || v < 1)
		{
			throw "ERROR: there is an exception with id of the vertex";
		}

		if (weight < 0)
		{
			throw "ERROR: there is an exception with weight of the edge";
		}
		
		arr[u].addTail(v, weight);
	}
	
	void GraphAdjacencyList::RemoveEdge(int u, int v)
	{
		arr[u].removeNode(v);
	}

	const GraphAdjacencyList& GraphAdjacencyList::operator=(const GraphAdjacencyList& other)
	{
		if (this != &other)
		{
			arr = other.arr;
		}
		
		return *this;
	}
}
