#pragma once
#include "LinkedList.h"

namespace vrt
{
	class VertexArray
	{
	 private:
		
		LinkedList* m_Array;
		int			m_PhsSize;

	 public:

		//c'tor
		VertexArray(int i_Len);

		//copy c'tor
		VertexArray(const VertexArray& arr);

		//d'tor 
		~VertexArray();

		//print LinkedList* m_Array
		void printArr() const;

		//---Getters---//
		//
		//int getLogSize() const { return m_LogSize; }
		int getPhsSize() const { return m_PhsSize; }
		LinkedList& getAdjList(int i_ID) const { return m_Array[i_ID]; }

		//--Operators--//
		LinkedList& operator[](int idx) { return m_Array[idx]; }
		const LinkedList& operator[](int idx) const { return m_Array[idx]; }
	};
}
