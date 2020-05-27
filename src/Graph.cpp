#include "pch.h"
#include "Graph.h"
#include "Sequence.h"
#include "Exception.h"
#include <iostream>

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
		
		if(tmp != nullptr)
		{
			while (tmp)
			{
				std::cout << "-> " << tmp->data;
				tmp = tmp->next;
			}
		}

		else
		{
			std::cout <<"-> null" <<std::endl;
		}

		std::cout << std::endl;
	}
}
