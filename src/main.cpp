#include "Exception.h"
#include "Graph.h"
#include <iostream> 
#include <deque>
using std::cout;
using std::endl;
using std::cin;

int main()
{
	std::deque<int> v = { 5,3,3,3,2,2 };
	Graph r(v.size());
	try
	{
		r.CreateGraph(v);
		r.DisplayGraph();
	}
	catch (const Creation& exp)
	{
		cout << exp.what() << endl;
	}
	cout << endl << "~~~~~~~~~~~~~~~~~~~~~~~~" << endl << endl;

	std::deque<int> v1 = {4, 4, 4, 4, 4, 0 };
	Graph res(v1.size());

	try {
		res.CreateGraph(v1);
		res.DisplayGraph();
	}
	catch (const Creation& exp)
	{
		cout << exp.what() << endl;
	}
	return 0;
}