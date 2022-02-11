#pragma once
#include "PriorityQueue.h"

namespace  vrt
{
	class PQMinArray :public PriorityQueue
	{
	 private:
		Vertex m_Min;
		Vertex* m_Arr;
		int m_LogicSize;
		int m_PhysicSize;
		int m_IndexToFirstFreePlace;
		int m_IdexOfMin;

		//--private static methods--//
		
		//help DeleteMin() to update members of the class
		void helperDeleteMin();
		
		//update Minimum 
		void updateMin();

	 public:

		//c'tor
		PQMinArray();
		PQMinArray(int physicSize);
		
		//d'tor
		virtual ~PQMinArray();

		//Initialzed PQMinArray
		virtual void makeEmpty();
		
		//return true if PQMinArray are empty, otherwise false
		virtual bool isEmpty();
		
		//insert new object to the PQMinArray
		void insert(float priority, int data);
		
		//delete Minimum and uptade
		virtual Vertex* deleteMin();
		
		//decrease the priority of the object in location place to newPriority
		virtual void DecreaseKey(int v, float newData);
		
		//build PQMinArray from array of vertex
		virtual void Build(Vertex* arr, int size);

		virtual int getType();
		
		//--Operators--//

		//operator[]
		Vertex& operator[](int idx) { return m_Arr[idx]; }

		//const operator[]
		const Vertex& operator[](int idx) const { return m_Arr[idx]; }
	};
}
