#pragma once
#include <fstream>
#include <iostream>
using namespace std;

namespace vrt
{
	class LinkedList
	{
	 public:
		
		struct Node
		{			
			int		data;
			float	weight;
			Node*	next;
		};
		//ctor
		LinkedList();
		
		//CopyCtor
		LinkedList(const LinkedList& other);
		
		//d`tor		
		~LinkedList();
		
		//make the list empty
		void makeListEmpty();
		
		//insert new Node To Tail of linked list
		void addTail(int i_Data, float i_Weight);
		
		//insert new Node to Head of linked list
		void addHead(int i_Data, float i_Weight);
		
		//print the linked List
		void printList();
		
		//delete the node from linked list
		void removeNode(int i_Data);
		
		//--Getters--//
		Node&	getHead	(void) const { return *m_Head; }
		Node&	getTail	(void) const { return *m_Tail; }
		int		getLen	(void) const { return m_Len;  }
		Node*   getNodeById(int data) const;

		//--operators--//

		//operator[]
		const LinkedList& operator=(const LinkedList& other);
	
	 private:
		int		m_Len;
		Node*	m_Head;
		Node*	m_Tail;
	};
}

