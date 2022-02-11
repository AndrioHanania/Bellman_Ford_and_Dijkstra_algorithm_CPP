#include "Vertex.h"

namespace vrt
{
	Vertex::Vertex(int data, float priority): m_Data(data), m_Priority(priority)
	{
	}
	
	Vertex::Vertex(): m_Data(0), m_Priority(0)
	{
	}
	
	Vertex::~Vertex()
	{
	}

	Vertex& Vertex::operator=(const Vertex& other)
	{
		m_Data = other.m_Data;
		m_Priority = other.m_Priority;
		return *this;
	}

	void Vertex::setPriority(float priority)
	{
		m_Priority = priority;
	}
	
	void Vertex::setData(int data)
	{
		m_Data = data;
	}

	bool Vertex::operator>(const Vertex& other)
	{
		return m_Priority > other.getPriority() ? true : false;
	}
}
