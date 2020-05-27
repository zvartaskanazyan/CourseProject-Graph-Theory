#pragma once

class Exeption
{
public:
	virtual const char* what() const throw()
	{
		return "Exeption!";
	}
	virtual ~Exeption(){}
};

class Creation:public Exeption
{
public:
	const char* what() const throw()
	{
		return "Can't create graph.The sequence isn't graphic!";
	}
};
