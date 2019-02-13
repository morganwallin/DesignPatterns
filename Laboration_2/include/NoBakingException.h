#pragma once
#include <exception>

class NoBakingException :
	public std::exception
{
private:
	std::string msg_;

public:
	NoBakingException(const std::string& msg) : msg_(msg) {}
	~NoBakingException(){}
	std::string getMessage() const { return(msg_); }
};

