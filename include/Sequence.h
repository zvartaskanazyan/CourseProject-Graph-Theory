#pragma once
#include <algorithm> 
#include <iostream> 
#include <deque>


inline bool is_graphic_sequence(std::deque<int> degreeSequence) {

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
