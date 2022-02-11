#include "NeighborlyMatrix.h"


namespace vrt
{
	NeighborlyMatrix::NeighborlyMatrix(int n)
	{
		MakeEmptyGraph(n);
	}
		
	NeighborlyMatrix::NeighborlyMatrix(ifstream& inFile, int num)
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

	int NeighborlyMatrix::getType()
	{
		return MATRIX;
	}

	void NeighborlyMatrix::MakeEmptyGraph(int n)
	{
		m_NumberOfVertex = n;
		m_NeighborlyMatrix = new float*[m_NumberOfVertex];
		for (int i = 0; i < m_NumberOfVertex; i++)
		{
			m_NeighborlyMatrix[i] = new float[m_NumberOfVertex];
			for (int j = 0; j < m_NumberOfVertex; j++)
			{
				m_NeighborlyMatrix[i][j] = INVALIDWEIGHT;
			}
		}
	}

	bool NeighborlyMatrix::IsAdjacent(int u, int v)
	{
		return  m_NeighborlyMatrix[u - 1][v - 1] >= 0 ? true : false;
	}

	LinkedList* NeighborlyMatrix::GetAdjList(int u)
	{
		LinkedList* adjList = new LinkedList();
		for (int i = 1; i <= m_NumberOfVertex;i++)
		{
			if (m_NeighborlyMatrix[u][i - 1] >= 0)
			{
				adjList->addTail(i, m_NeighborlyMatrix[u][i - 1]);
			}
		}
		return adjList;
	}

	void NeighborlyMatrix::AddEdge(int u, int v, float weight)
	{
		if (IsAdjacent(u, v))
		{			
			throw "ERROR: an edge already exists";
		}

		if (u > m_NumberOfVertex || u < 1 ||
			v > m_NumberOfVertex || v < 1)
		{
			throw "ERROR: there is an exception with id of the vertex";
		}

		if (weight < 0)
		{
			throw "ERROR: there is an exception with weight of the edge";
		}

		m_NeighborlyMatrix[u - 1][v - 1] = weight;
	}

	void NeighborlyMatrix::fillGraph(ifstream& inFile)
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
				AddEdge(u, v, weight);
			}
			catch (const char* exception)
			{
				throw exception;
			}
		}
	}

	NeighborlyMatrix::~NeighborlyMatrix()
	{
		for (int i = 0; i < m_NumberOfVertex; i++)
		{
			delete m_NeighborlyMatrix[i];
		}
		delete m_NeighborlyMatrix;
	}

	void NeighborlyMatrix::RemoveEdge(int u, int v)
	{
		m_NeighborlyMatrix[u - 1][v - 1] = INVALIDWEIGHT;
	}

	float* NeighborlyMatrix::operator[](int index)
	{
		return m_NeighborlyMatrix[index];
	}

	int NeighborlyMatrix::getNumberOfVertex()
	{
		return m_NumberOfVertex;
	}

	NeighborlyMatrix::NeighborlyMatrix(NeighborlyMatrix& other)
	{
		*this = other;
	}

	const NeighborlyMatrix& NeighborlyMatrix::operator=(const NeighborlyMatrix& other)
	{
		m_NumberOfVertex = other.m_NumberOfVertex;
		for (int i = 0; i < m_NumberOfVertex; i++)
		{
			for (int j = 0; j < m_NumberOfVertex; j++)
			{
				m_NeighborlyMatrix[i][j] = other.m_NeighborlyMatrix[i][j];
			}
		}
		return *this;
	}

	void NeighborlyMatrix::DisplayGraph()
	{
		for (int i = 0; i < m_NumberOfVertex; i++)
		{
			cout << "==============================" << endl;
			cout << "Vertex: " << i+1 << " Adjancecy List:" << endl;
			LinkedList* list = GetAdjList(i);
			list->printList();
		}
	}
}