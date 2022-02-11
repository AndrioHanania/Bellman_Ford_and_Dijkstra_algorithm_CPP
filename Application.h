#pragma once
#include "myAlgorithm.h"

#define MinusOne -1

namespace vrt
{
	class Application
	{
	 private:
		
		ifstream m_InFile;
		ofstream m_OutFile;
		Graph* m_GNeighborlyMatrix, *m_GAdjacencyList;
		const char* m_InFileName, *m_OutFileName;

		//if inFile doesn't opening we will close the files, print an error and exit program
		void checkInFile(ifstream& inFile);

		void printFinalWeight(float finalWeight);

		void printAllFinalWeight(float& wADH, float& wADA, float& wABF, float& wMDH, float& wMDA,
			float& wMBF);

		//check dst vertex and src vertex
		static void checkDstAndSrc(int dst, int src);

	 public:

		//c'tor
		 Application(const char* inFileName, const char* outFileName);

		 //d'tor
		 ~Application();

		//run the application
		 void run();

		 void  runAllAlgorithm(int desVertex, int srcVertex, float& wADH, float& wADA,
			 float& wABF, float& wMDH, float& wMDA, float& wMBF, PriorityQueue* pQHeap,
			 PriorityQueue* pQMinArray);
	};	
}
