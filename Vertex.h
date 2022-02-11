#pragma once
#include <iostream>
#include <stdbool.h>

using namespace std;

namespace vrt
{
	class Vertex
	{
	 private:
		
		 float m_Priority;
		int m_Data;
	
	 public:

		 //c'tor
		Vertex(int data, float priority);
		Vertex();

		//d'tor
		~Vertex();
		
		//--Operators--//

		//operator=
		Vertex& operator=(const Vertex& other);

		//operator>
		bool operator>(const Vertex& other);
		

		//--Setters--/
		void setPriority(float priority);
		void setData(int data);

		//--Getters--//
		const float getPriority() const { return m_Priority; }
		const char getData() const { return m_Data; }	
	};
}

