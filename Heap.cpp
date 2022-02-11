#include "Heap.h"

namespace vrt
{
	Heap::Heap(int size) : m_Arr(new Vertex[size]), m_LocationsArray(new int[size]), m_maxSize(size), m_heapSize(0), m_allocated(1)
	{
	}
	
	Heap::Heap(Vertex* arr, int length)
	{
		Build(arr, length);
	}

	int Heap::getType()
	{
		return HEAP;
	}
	
	void Heap::Build(Vertex* arr, int length)
	{
		m_heapSize = m_maxSize = length;
		for (int j = 0; j < length; j++)
		{
			m_Arr[j] = arr[j];
		}
		
		m_LocationsArray = new int[length];
		m_allocated = 1;
		for (int j = 0; j < length; j++)
		{
			m_LocationsArray[j] = j;
		}

		for (int i = length / 2 - 1; i >= 0; i--)
		{
			FixHeap(i);
		}
	}
	
	void Heap::DecreaseKey(int v, float newPriority)
	{
		int iTemp = m_LocationsArray[v - 1];
		if (iTemp != -1)
		{
			m_Arr[iTemp].setPriority(newPriority);
			FixHeapUp(iTemp);
		}
	}
	
	Heap::~Heap()
	{
		if (m_allocated)
		{
			delete[] m_Arr;
		}
		delete[] m_LocationsArray;
	}
	
	int Heap::Parent(int node)
	{
		return (node - 1) / 2;
	}
	
	int Heap::Left(int node)
	{
		return (2 * node + 1);
	}
	
	int Heap::Right(int node)
	{
		return (2 * node + 2);
	}
	
	void Heap::FixHeap(int vertex)
	{
		int min;
		int left = Left(vertex);
		int right = Right(vertex);

		if (m_Arr[vertex].getPriority() == -1)
		{
			if (m_Arr[left].getPriority() > -1 && m_Arr[right].getPriority() > -1)
			{
				if (m_Arr[left].getPriority() < m_Arr[right].getPriority())
				{
					min = left;
				}
				else {
					min = right;
				}
			}
			else if(m_Arr[left].getPriority() > -1)
			{
				min = left;
			}
			else if (m_Arr[right].getPriority() > -1)
			{
				min = right;
			}
			else
			{
				min = vertex;
			}
		}
		else 
		{
			if ((left < m_heapSize) && (m_Arr[left].getPriority() != -1) && 
				(m_Arr[left].getPriority() < m_Arr[vertex].getPriority()))
			{
				min = left;
			}
			else
			{
				min = vertex;
			}

			if ((right < m_heapSize) && (m_Arr[right].getPriority() != -1) && 
				(m_Arr[right].getPriority() < m_Arr[min].getPriority()))
			{
				min = right;
			}
		}
		
		if (min != vertex) 
		{
			Swap(vertex, min);
			FixHeap(min);
		}
	}
	
	void Heap::FixHeapUp(int vertex)
	{
		int min;
		int parent = Parent(vertex);

		if ((parent >= 0) && m_Arr[parent].getPriority() == -1)
		{
			min = parent;
		}
		else 
		{
			if ((m_Arr[parent].getPriority() > m_Arr[vertex].getPriority()))
			{
				min = parent;
			}
			else
			{
				min = vertex;
			}
		}

		if (min != vertex)
		{
			Swap(vertex, min);
			FixHeapUp(min);
		}
	}

	Vertex* Heap::deleteMin()
	{
		if (m_heapSize < 1)
			return nullptr;

		Vertex* min;
		try 
		{
			min = new Vertex(m_Arr[0]);
		}
		catch (bad_alloc& c) 
		{
			cout << "Bad allocation";
			exit(-1);
		}
		
		m_heapSize--;
		m_LocationsArray[m_Arr[0].getData() - 1] = -1;
		m_Arr[0].setData(m_Arr[m_heapSize].getData());
		m_Arr[0].setPriority(m_Arr[m_heapSize].getPriority());
		m_LocationsArray[m_Arr[m_heapSize].getData() - 1] = 0;
		FixHeap(0);
		return min;
	}
	
	void Heap::insert(float priority, int data)
	{
		if (m_heapSize == m_maxSize)
		{
			throw "The array is full";
		}
		
		int i = m_heapSize;
		m_heapSize++;
		while ((i > 0) && m_Arr[Parent(i)].getPriority() > priority) 
		{
			int tmpLocation = m_LocationsArray[m_Arr[Parent(i)].getData()];
			m_LocationsArray[m_Arr[Parent(i)].getData()] = m_LocationsArray[m_Arr[i].getData()];
			m_LocationsArray[m_Arr[i].getData()] = tmpLocation;
			m_Arr[i].setData(m_Arr[Parent(i)].getData());
			m_Arr[i].setPriority(m_Arr[Parent(i)].getPriority());
			i = Parent(i);
		}
		m_Arr[i].setData(data);
		m_Arr[i].setPriority(priority);
	}
	
	bool Heap::isEmpty()
	{
		return m_heapSize == 0 ? true : false;
	}
	
	void Heap::makeEmpty()
	{
		delete[] m_Arr;
		delete[] m_LocationsArray;
		m_maxSize = 0;
		m_heapSize = 0;
		m_allocated = 0;
	}
	
	void Heap::printHeap()
	{
		for (int i = 0; i < m_heapSize; i++) 
		{
			cout << "Letter: " << m_Arr[i].getData() << " Freq: " 
				<< m_Arr[i].getPriority() << endl;
		}
	}
	
	void Heap::Swap(int node, int min)
	{
		if (min < m_heapSize - 1)
		{
			int tmpLocation = m_LocationsArray[m_Arr[node].getData() - 1];
			m_LocationsArray[m_Arr[node].getData() - 1] = m_LocationsArray[m_Arr[min].getData() - 1];
			m_LocationsArray[m_Arr[min].getData() - 1] = tmpLocation;

			Vertex temp = m_Arr[node];
			m_Arr[node] = m_Arr[min];
			m_Arr[min] = temp;	
		}
	}
}
