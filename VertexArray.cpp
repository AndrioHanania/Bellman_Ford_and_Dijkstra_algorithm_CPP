#include "VertexArray.h"


namespace vrt
{
	VertexArray::VertexArray(int i_Len) 
		: m_Array(new LinkedList[i_Len]), m_PhsSize(i_Len)
	{
	}
	
	VertexArray::VertexArray(const VertexArray& arr) :
		VertexArray(arr.getPhsSize())
	{
		for(int i=0;i<arr.m_PhsSize;i++)
		{
			m_Array[i] = arr.m_Array[i];
		}
	}
	
	VertexArray::~VertexArray()
	{
		delete[] m_Array;
	}
	
	void VertexArray::printArr() const
	{
		for (int i = 0; i < m_PhsSize; i++)
		{
			cout << "==============================" << endl;
			cout << "Vertex: " << i + 1 << " Adjancecy List:" << endl;
			m_Array[i].printList();
		}
	}
}