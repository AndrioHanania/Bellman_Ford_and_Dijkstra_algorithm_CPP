#pragma once
#include "PriorityQueue.h"

namespace vrt
{
	class Heap : public PriorityQueue
	{
	 private:
		
		Vertex* m_Arr;
		int*	m_LocationsArray;
		int		m_maxSize;
		int		m_heapSize;
		int		m_allocated;

		//--private static methods--//

		//get left child of vertex
		static int Left(int vertex);

		//get right child of vertex
		static int Right(int vertex);

		//get parent of vertex
		static int Parent(int vertex);

		//--private static methods--//
		void	FixHeap(int vertex);
		void	FixHeapUp(int vertex);

	 public:

		//c'tor
		Heap(int size);
		Heap(Vertex* arr, int length);

		//d'tor
		virtual ~Heap();

		//--Mandatory Implemntion--//

		//build Heap from array of vertex(Floyd algorithm)
		void Build(Vertex* arr, int size);

		//decrease the priority of the object in location place to newPriority
		void DecreaseKey(int v, float newPriority);

		//delete Minimum and uptade
		Vertex* deleteMin();

		//insert new object to the Heap
		void insert(float priority, int data);

		//return true if Heap are empty, otherwise false
		bool isEmpty();

		int getType();

		//Initialzed Heap
		void makeEmpty();
		//=============================================
		Vertex* getNode() { return m_Arr; }
		int getMaxSize() const { return m_maxSize; }
		int getAllocated() const { return m_allocated; }
		
		//--Helpers--//
		void Swap(int vertex, int min);
		void printHeap(void);

		//--Operators--//

		//operator[]
		Vertex& operator[](int idx) { return m_Arr[idx]; }

		//const operator[]
		const Vertex& operator[](int idx) const { return m_Arr[idx]; }
	};
}

