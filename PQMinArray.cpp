#include "PQMinArray.h"

namespace vrt
{
	PQMinArray::PQMinArray() : m_Arr(nullptr), m_PhysicSize(0), m_LogicSize(0),
		m_IndexToFirstFreePlace(0), m_IdexOfMin(0), m_Min(0, -1)
	{
	}

	PQMinArray::PQMinArray(int physicSize): PQMinArray()
	{
		m_PhysicSize = physicSize;
		m_Arr = new Vertex[m_PhysicSize];
		makeEmpty();
	}


	int PQMinArray::getType()
	{
		return PQMINARRAY;
	}

	PQMinArray::~PQMinArray()
	{
		delete[] m_Arr;
	}

	void PQMinArray::makeEmpty()
	{
		m_LogicSize = 0;
		m_IndexToFirstFreePlace = 0;
		m_IdexOfMin = 0;
		m_Min.setData(0);
		m_Min.setPriority(-1);
		for (int i = 0; i < m_PhysicSize; i++)
		{
			m_Arr[i].setPriority(-1);
			m_Arr[i].setData(0);
		}
	}

	bool PQMinArray::isEmpty()
	{
		return m_LogicSize == 0 ? true : false;
	}

	void PQMinArray::insert(float priority, int data)
	{
		Vertex* newItem = new Vertex(priority, data);
		if (!isEmpty())
		{
			m_Arr[m_IndexToFirstFreePlace] = (*newItem);
			if ((m_Min.getPriority() > priority && priority != -1) || 
				(m_Min.getPriority() == -1 && priority != -1))
			{
				m_Min.setPriority(priority);
				m_Min.setData(data);
				m_IdexOfMin = m_IndexToFirstFreePlace;
			}
			m_IndexToFirstFreePlace++;
			m_LogicSize++;
		}
		else
		{
			throw "The array is full";
		}
	}

	Vertex* PQMinArray::deleteMin()
	{
		Vertex* min = new Vertex();
		(*min) = m_Min;	
		if (m_IdexOfMin != m_LogicSize - 1)
		{
			m_Arr[m_IdexOfMin] = m_Arr[m_IndexToFirstFreePlace - 1];
		}
		
		helperDeleteMin();
		return min;
	}

	void PQMinArray::helperDeleteMin()
	{
		m_LogicSize--;
		m_IndexToFirstFreePlace--;
		updateMin();
	}

	void PQMinArray::updateMin()
	{
		m_Min = m_Arr[0];
		m_IdexOfMin = 0;
		for (int i = 1; i < m_LogicSize; i++)
		{
			if ((m_Min > m_Arr[i] && m_Arr[i].getPriority() != -1) || (m_Min.getPriority() == -1 &&
				m_Arr[i].getPriority() != -1))
			{
				m_Min = m_Arr[i];
				m_IdexOfMin = i;
			}
		}
	}

	void PQMinArray::DecreaseKey(int place, float newPriority)
	{
		int iplace = 0;
		while(m_Arr[iplace].getData() != place && iplace < m_LogicSize)
		{
			iplace++;
		}
		
		m_Arr[iplace].setPriority(newPriority);
		if(place == m_IdexOfMin)
		{
			updateMin();
		}		
		else if ((m_Min.getPriority() > newPriority && newPriority != -1) || (m_Min.getPriority() ==
			-1 && newPriority != -1))
		{
			m_Min.setData(m_Arr[iplace].getData());
			m_Min.setPriority(m_Arr[iplace].getPriority());
			m_IdexOfMin = iplace;
		}
	}

	void PQMinArray::Build(Vertex* arr, int size)
	{
		if (m_PhysicSize <= 0)
		{
			m_Arr = new Vertex[size];
		}
		
		makeEmpty();
		for (int i = 0; i < size; i++)
		{
			m_Arr[i] = arr[i];
		}
		
		m_PhysicSize = m_LogicSize = size;
		m_IndexToFirstFreePlace = m_LogicSize;
		updateMin();
	}
}