#pragma once
#include "Node.h"
#include <deque>

class Graph {

public:

	Graph(unsigned ver);
	~Graph();
	void AddEdge(size_t& src, size_t& dest);
	void CreateGraph(std::deque<int>& degSeq);
	void DisplayGraph();

private:
	unsigned vertex;
	AdjList* array;
};
