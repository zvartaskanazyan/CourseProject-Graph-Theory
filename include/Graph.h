#pragma once
#include "Node.h"
#include <deque>

class Graph {

public:

	Graph(unsigned ver);
	~Graph();
	void DisplayGraph();
	void AddEdge(size_t& src, size_t& dest);
	void CreateGraph(std::deque<int>& degSeq);
	bool is_graphic_sequence(std::deque<int> degreeSequence);

private:
	unsigned vertex;
	AdjList* array;
};
