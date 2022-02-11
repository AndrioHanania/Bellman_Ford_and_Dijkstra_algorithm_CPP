#include "Application.h"

namespace vrt
{
	Application::Application(const char* inFileName, const char* outFileName)
		:m_InFile(inFileName), m_OutFile(outFileName), m_GNeighborlyMatrix(nullptr),
	m_GAdjacencyList(nullptr), m_InFileName(inFileName), m_OutFileName(outFileName)
	{
	}

	Application::~Application()
	{
		delete m_GAdjacencyList;
		delete m_GNeighborlyMatrix;
		m_InFile.close();
		m_OutFile.close();
	}

	void Application::run()
	{
		int desVertex=0, srcVertex=0, amountVertex, fPosition;
		//final weights of all algorithms
		float wADH = 0, wADA = 0, wABF = 0, wMDH = 0, wMDA = 0, wMBF = 0;
		
		try
		{
			checkInFile(m_InFile);
		}
		catch (const char* exception)
		{
			cout << exception << endl;
			exit(1);
		}
		
		m_InFile >> amountVertex;
		m_InFile >> srcVertex;
		m_InFile >> desVertex;
		fPosition = m_InFile.tellg();
		
		if(srcVertex < 1 || srcVertex > amountVertex)
		{
			cout << "ERROR: with id of source vertex" << endl;
			exit(1);
		}

		if (desVertex < 1 || desVertex > amountVertex)
		{
			cout << "ERROR: with id of destination vertex" << endl;
			exit(1);
		}
		
		try
		{
			m_GAdjacencyList = new GraphAdjacencyList(m_InFile, amountVertex);
		}
		catch (const char* exception)
		{
			cout << "G1:\n" << exception << endl;
			exit(1);
		}

		if (fPosition != MinusOne)
		{
			m_InFile.seekg(fPosition, m_InFile.beg);
		}
		
		try
		{
			m_GNeighborlyMatrix = new NeighborlyMatrix(m_InFile, amountVertex);
		}
		catch (const char* exception)
		{
			cout << "G2:\n" << exception << endl;
			exit(1);
		}
		
		int numberOfVertex = m_GAdjacencyList->getNumberOfVertex();
		PriorityQueue* pQHeap = new Heap(numberOfVertex);
		PriorityQueue* pQMinArray = new PQMinArray(numberOfVertex);
		try
		{
			runAllAlgorithm(desVertex, srcVertex, wADH, wADA, wABF, wMDH, wMDA, wMBF,
				pQHeap, pQMinArray);
		}
		catch (const char* exception)
		{
			cout << exception << endl;
			exit(1);
		}
				
		printAllFinalWeight(wADH, wADA, wABF, wMDH, wMDA, wMBF);
		delete pQHeap;
		delete pQMinArray;
	}

	void Application::checkInFile(ifstream& inFile)
	{
		if (!inFile.is_open())
		{
			throw "Error with Opening the input file";
		}
		
		int tempAmountVertex = MinusOne;
		inFile >> tempAmountVertex;
		if(tempAmountVertex == MinusOne)
		{
			throw "The input file is empty";
		}
		if(tempAmountVertex <= 0)
		{
			throw "ERROR: with the number of vertex";
		}
		
		inFile.seekg(0, inFile.beg);
	}

	void Application::printFinalWeight(float finalWeight)
	{
		if (finalWeight != MinusOne)
		{
			cout << finalWeight << endl;
		}
		else
		{
			cout << "no route" << endl;
		}
	}

	void Application::printAllFinalWeight(float& wADH, float& wADA, float& wABF, float& wMDH,
		float& wMDA, float& wMBF)
	{
		cout << "Adjacency Dijkstra heap ";
		printFinalWeight(wADH);
		cout << "Adjacency Dijkstra array ";
		printFinalWeight(wADA);
		cout << "Adjacency Bellman Ford ";
		printFinalWeight(wABF);
		cout << "Matrix Dijkstra heap ";
		printFinalWeight(wMDH);
		cout << "Matrix Dijkstra array ";
		printFinalWeight(wMDA);
		cout << "Matrix Bellman Ford ";
		printFinalWeight(wMBF);
	}

	void  Application::runAllAlgorithm(int desVertex, int srcVertex, float& wADH,
		float& wADA, float& wABF, float& wMDH, float& wMDA, float& wMBF,
		PriorityQueue* pQHeap, PriorityQueue* pQMinArray)
	{
		try
		{
			checkDstAndSrc(desVertex, srcVertex);
		}
		catch (const char* exception)
		{
			throw exception;
		}
	
		//Adjacency Dijkstra heap
		myAlgorithm::MeasureDij(myAlgorithm::dijkstra, m_GAdjacencyList, pQHeap,
			desVertex, srcVertex, wADH, m_OutFile);


		//Adjacency Dijkstra array
		myAlgorithm::MeasureDij(myAlgorithm::dijkstra, m_GAdjacencyList, pQMinArray,
			desVertex, srcVertex, wADA, m_OutFile);


		//Adjacency Bellman Ford
		try
		{
			myAlgorithm::MeasureBF(myAlgorithm::belmanFord, m_GAdjacencyList,
				desVertex, srcVertex, wABF, m_OutFile);
		}
		catch (const char* exception)
		{
			cout << endl << "Graph AdjacencyList:" << endl;
			throw exception;
		}
		
		//Matrix Dijkstra heap
		myAlgorithm::MeasureDij(myAlgorithm::dijkstra, m_GNeighborlyMatrix, pQHeap,
			desVertex, srcVertex, wMDH, m_OutFile);

		
		//Matrix Dijkstra array
		myAlgorithm::MeasureDij(myAlgorithm::dijkstra, m_GNeighborlyMatrix, pQMinArray,
			desVertex, srcVertex, wMDA, m_OutFile);

		//Matrix Bellman Ford
		try
		{
			myAlgorithm::MeasureBF(myAlgorithm::belmanFord, m_GNeighborlyMatrix,
				desVertex, srcVertex, wMBF, m_OutFile);
		}
		catch (const char* exception)
		{
			cout << endl << "Graph Neighborly Matrix:" << endl;
			throw exception;
		}
	}

	void Application::checkDstAndSrc(int dst, int src)
	{
		if (dst == 0 && src != 0)
		{
			throw "Error with destination vertex";
		}

		if (dst != 0 && src == 0)
		{
			throw "Error with source vertex";
		}
	}
}
