#include "myAlgorithm.h"
#define MinusOne -1

namespace vrt
{
	void myAlgorithm::belmanFord(Graph* G, int dst, int src, float& FinalWeight)
	{
		int numOfVertex = G->getNumberOfVertex();
		float* d = new float[numOfVertex];
		int* p = new int[numOfVertex];
		init(d, p, numOfVertex, src);
		for (int j = 1; j < numOfVertex; j++)
		{
			for (int i = 1; i <= numOfVertex; i++)
			{
				LinkedList* lst = G->GetAdjList(i - 1);
				LinkedList::Node* curr = &lst->getHead();
				while (curr != nullptr)
				{
					relax(i, curr->data, curr->weight, d, p);
					curr = curr->next;
				}
				if (G->getType() == MATRIX)
				{
					lst->makeListEmpty();
				}
			}
		}
		
		for (int i = 1; i <= numOfVertex; i++)
		{
			LinkedList* lst = G->GetAdjList(i - 1);
			LinkedList::Node* curr = &lst->getHead();
			while (curr != nullptr)
			{
				if (d[curr->data - 1] > d[i - 1] + curr->weight && d[i - 1] != -1 &&
					d[curr->data - 1] != -1)
				{
					throw "negative cycle";
				}

				curr = curr->next;
			}
			if (G->getType() == MATRIX)
			{
				lst->makeListEmpty();
			}
		}
		FinalWeight = d[dst - 1];
		delete[] d;
		delete[] p;
	}

	void myAlgorithm::init(float* d, int* p, int numOfVertex, int srcVertex)
	{
		d[srcVertex - 1] = 0;
		p[srcVertex - 1] = MinusOne;

		for (int i = 1; i <= numOfVertex; i++)
		{
			if (i != srcVertex)
			{
				d[i - 1] = MinusOne;
				p[i - 1] = MinusOne;
			}
		}
	}

	bool myAlgorithm::relax(int u, int v, float weight, float* d, int* p)
	{
		bool temp = false;
		--v; --u;
		if ((d[v] > d[u] + weight && d[u] != -1 && d[v] != -1) || (d[v] == -1 && 
			d[u] != -1))
		{
			d[v] = d[u] + weight;
			p[v] = u + 1;
			temp = true;
		}
		
		return temp;
	}

	void myAlgorithm::MeasureBF(void (*fun)(Graph* G, int dst, int src, 
		float& FinalWeight), Graph* G, int dst, int src, float& FinalWeight,
		ofstream& myfile)
	{
		auto start = chrono::high_resolution_clock::now();
		ios_base::sync_with_stdio(false);
		try
		{
			fun(G, dst, src, FinalWeight);
		}
		catch (const char exception)
		{
			throw exception;
		}
		
		auto end = chrono::high_resolution_clock::now();
		double time_taken = 
			chrono::duration_cast<chrono::nanoseconds>(end - start).count();
		time_taken *= 1e-9;		
		if (G->getType() == MATRIX)
		{
			myfile << "Matrix ";
		}
		else if (G->getType() == ADJCENCY)
		{
			myfile << "Adjacency ";
		}
		myfile << "Bellman Ford<" << fixed << time_taken << setprecision(9)
		<< ">" << endl;
	}

	void myAlgorithm::dijkstra(Graph* G, PriorityQueue* pQ, int dst, int src, float& FinalWeight)
	{
		int numOfVertex = G->getNumberOfVertex();
		float* d = new float[numOfVertex];
		int* p = new int[numOfVertex];
		init(d, p, numOfVertex, src);	
		Vertex* arr = CreateVertexArrayFromGraph(G, d);
		pQ->Build(arr, G->getNumberOfVertex());

		while (!pQ->isEmpty())
 		{
			Vertex* v = pQ->deleteMin();
			LinkedList* lst = G->GetAdjList(v->getData() - 1);
			LinkedList::Node* curr = &lst->getHead();
			while (curr != nullptr)
			{
				if (relax(v->getData(), curr->data, curr->weight, d, p))
				{
					pQ->DecreaseKey(curr->data, d[curr->data - 1]);
				}
				curr = curr->next;
			}
			delete v;
			if (G->getType() == MATRIX)
			{
				lst->makeListEmpty();
			}
		}
		FinalWeight = d[dst - 1];
		delete[] arr;
		delete[] d;
		delete[] p;
	}

	Vertex* myAlgorithm::CreateVertexArrayFromGraph(Graph* G, float* d)
	{
		int numberOfVertex = G->getNumberOfVertex();
		Vertex* arr = new Vertex[numberOfVertex];		
		for (int i = 0; i < numberOfVertex; i++)
		{
			arr[i].setData(i + 1);
			arr[i].setPriority(d[i]);
		}

		return arr;
	}

	void myAlgorithm::MeasureDij(void (*fun)(Graph* G, PriorityQueue* pQ, int dst,
		int src, float& FinalWeight), Graph* G, PriorityQueue* pQ, int dst,
		int src, float& FinalWeight, ofstream& myfile)
	{
		auto start = chrono::high_resolution_clock::now();
		ios_base::sync_with_stdio(false);
		fun(G, pQ, dst, src, FinalWeight);
		auto end = chrono::high_resolution_clock::now();
		double time_taken = 
			chrono::duration_cast<chrono::nanoseconds>(end - start).count();
		time_taken *= 1e-9;
		if (G->getType() == MATRIX)
		{
			myfile << "Matrix ";
		}
		else if (G->getType() == ADJCENCY)
		{
			myfile << "Adjacency ";
		}
		
		myfile << " Dijkstra ";
		if(pQ->getType() == PQMINARRAY)
		{
			myfile << "array <";
		}
		else if(pQ->getType() == HEAP)
		{
			myfile << "heap <";
		}
		
		myfile << fixed << time_taken << setprecision(9) << ">" << endl;
	}
}