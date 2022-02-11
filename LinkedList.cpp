#include "LinkedList.h"

namespace vrt
{
	LinkedList::LinkedList() : m_Head(nullptr), m_Tail(nullptr), m_Len(0)
	{
	}
	
	LinkedList::LinkedList(const LinkedList& other)
	{
		Node* item = &(other.getHead());
		while (item != nullptr)
		{
			addTail(item->data, item->weight);
			item = item->next;
		}
	}

	LinkedList::~LinkedList()
	{
		makeListEmpty();
	}
	
	void LinkedList::makeListEmpty()
	{
		while (m_Head != nullptr)
		{
			Node* item = m_Head;
			m_Head = m_Head->next;
			delete item;
			--m_Len;
		}
	}
	
	void LinkedList::addTail(int i_Data, float i_Weight)
	{
		Node* item = new Node();
		item->data = i_Data;
		item->weight = i_Weight;
		item->next = nullptr;
		if (m_Head == nullptr)
		{
			m_Head = item;
		}
		else 
		{
			m_Tail->next = item;
		}

		m_Tail = item;
		m_Len++;
	}
	
	void LinkedList::addHead(int i_Data, float i_Weight)
	{
		Node* item = new Node();
		item->data = i_Data;
		item->weight = i_Weight;		
		if (m_Head == nullptr)
		{
			m_Head = item;
			m_Tail = item;
			item->next = nullptr;
		}
		else
		{
			item->next = m_Head;
			m_Head = item;
		}
		
		m_Len++;
	}
	
	void LinkedList::printList()
	{
		Node* item = m_Head;

		while (item != nullptr)
		{
			cout << "Vertex ID: " << item->data << " Vertex Weight: " << item->weight << endl;
			item = item->next;
		}
	}
	
	void LinkedList::removeNode(int i_Data)
	{
		Node* item = m_Head;
		Node* prev = nullptr;

		while (item->data != i_Data)
		{
			prev = item;
			item = prev->next;
		}
		if (prev == nullptr)
		{
			m_Head = item->next;
		}
		else if (item->next == nullptr)
		{
			m_Tail = prev;
			prev->next = nullptr;
		}
		else 
		{
			prev->next = item->next;
		}
		
		delete item;
		--m_Len;
	}

	LinkedList::Node* LinkedList::getNodeById(int i_Data) const
	{
		Node* item = m_Head;
		while(item!=nullptr)
		{
			if(item->data==i_Data)
			{
				break;
			}
						
			item = item->next;			
		}
		
		return item;
	}

	const LinkedList& LinkedList::operator=(const LinkedList& other)
	{
		Node* item = other.m_Head;
		Node* currOther = other.m_Head;
		makeListEmpty();
		while (currOther != nullptr)
		{
			addTail(currOther->data, currOther->weight);
			currOther = currOther->next;
			item = item->next;
		}
		return *this;
	}
}