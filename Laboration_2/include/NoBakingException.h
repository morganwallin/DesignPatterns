#pragma once
#include <exception>

//Exception class to use for when there was an error retrieving a recepy
class NoBakingException :
	public std::exception
{
private:
	std::string msg_;

public:
	explicit NoBakingException(const std::string& msg) : msg_(msg) {}
	~NoBakingException() = default;
	std::string getMessage() const { return(msg_); }
};

