#include <iostream>
#include <exception>

class myexception : public std::exception
{
public:
	virtual const char* what() const throw()
	{
		return "The file is not formatted correctly. Ships may not have loaded correctly";
	}
};