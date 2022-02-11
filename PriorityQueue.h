#pragma once
#include "Vertex.h"

#define HEAP 0
#define PQMINARRAY 1

namespace vrt
{
	class PriorityQueue
	{
	public:

		//c'tor
		PriorityQueue() {}

		//d'tor
		virtual ~PriorityQueue() {}

		//build PQ from array of vertex
		virtual void Build(Vertex* arr, int size) = 0;

		//Initialzed PQ
		virtual void makeEmpty() = 0;

		//return true if PQ are empty, otherwise false
		virtual bool isEmpty() = 0;

		//insert new object to the PQ
		virtual void insert(float priority, int data) = 0;

		//delete Minimum and uptade
		virtual Vertex* deleteMin() = 0;

		//decrease the priority of the object in location place to newPriority
		virtual void DecreaseKey(int v, float newData) = 0;

		virtual int getType() = 0;
	};
}
