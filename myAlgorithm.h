#pragma once
#include "NeighborlyMatrix.h"
#include "GraphAdjacencyList.h"
#include "PQMinArray.h"
#include "Heap.h"
#include<chrono>
#include<iomanip>

namespace vrt
{
	class myAlgorithm
	{
	 private:

		 //--private methods--//
		
		//Initialized d[] and p[]
		 static void init(float* d, int* p, int numOfVertex, int srcVertex);

		//method for belmanFord
		 static bool relax(int u, int v, float weight, float* d, int* p);

		 //Create Vertex Array From Graph g and array d
		 static Vertex* CreateVertexArrayFromGraph(Graph* G, float* d);

	 public:

		//Algorithm Belman-Ford
		 static void belmanFord(Graph* G, int dst, int src, float& FinalWeight);

		 //Algorithm Dijkstra
		 static void dijkstra(Graph* G, PriorityQueue* pQ, int dst, int src, float& FinalWeight);

		//run belmanFord() and print to out file the measure the run time of the algorithm
		 static void MeasureBF(void (*fun)(Graph* G, int dst, int src,
			 float& FinalWeight), Graph* G, int dst, int src, float& FinalWeight,
			 ofstream& myfile);

		 //run dijkstra() and print to out file the measure the run time of the algorithm
		 static void MeasureDij(void (*fun)(Graph* G, PriorityQueue* pQ, int dst,
			 int src, float& FinalWeight), Graph* G, PriorityQueue* pQ, int dst,
			 int src, float& FinalWeight, ofstream& myfile);
	};	
}
