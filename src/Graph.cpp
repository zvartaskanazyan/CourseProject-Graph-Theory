#include "Graph.h"

#include "Exception.h"
#include <algorithm> 
#include <iostream> 
#include <deque>

Graph::Graph(unsigned ver):vertex(ver)
{
	array = new AdjList[ver];		
	for (size_t i = 0; i < ver; ++i)
		array[i].head = nullptr;
}

Graph::~Graph()
{
	delete array;
}

void Graph::AddEdge(size_t& src, size_t& dest)
{
	AdjListNode* newNode = new AdjListNode;  
	newNode->data = dest;					
	newNode->next = nullptr;		
												
	newNode->next = array[src].head;		
	array[src].head = newNode;				
			
	newNode = new AdjListNode; 				 
	newNode->data = src;
	newNode->next = nullptr;				

	newNode->next = array[dest].head;	
	array[dest].head = newNode;			
}

bool Graph::is_graphic_sequence(std::deque<int> degreeSequence) {

	sort(degreeSequence.begin(), degreeSequence.end(), std::greater<int>());
	
	if (degreeSequence.front() > degreeSequence.size() && degreeSequence.back() < 0)
		return false;
	if (!degreeSequence.front())
		return true;

	int front = degreeSequence.front();
	degreeSequence.pop_front();
	for (int i = 0; i < front; ++i)
	{
		--degreeSequence[i];
	}
	return is_graphic_sequence(degreeSequence);
}

void Graph::CreateGraph(std::deque<int>& degSeq)
{
	if (is_graphic_sequence(degSeq))
	{
		for (size_t index = 0; index < degSeq.size(); ++index)
		{
			for (size_t index_ = index + 1; index_ < degSeq.size(); ++index_)
			{
				if (degSeq[index] > 0 && degSeq[index_] > 0)
				{					
					AddEdge(index, index_);
					--degSeq[index];
					--degSeq[index_];
				}
			}
		}
	}
	
	else
		throw  Creation();
}

void Graph::DisplayGraph()
{
	for (size_t index = 0; index < vertex; ++index)
	{
		AdjListNode* tmp = array[index].head;		
		std::cout << "\n Adjacency list of vertex " << index << "\n head " << index;
		
		if(tmp != nullptr){
			while (tmp)
			{
				std::cout << "-> " << tmp->data;
				tmp = tmp->next;
			}
		} else {
			std::cout <<"-> null" <<std::endl;
		}
		std::cout << std::endl;
	}
}
