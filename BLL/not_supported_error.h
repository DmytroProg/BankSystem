#pragma once
#include <iostream>

class not_supported_error : public std::exception
{
public:
	not_supported_error(std::string message) : message(message)
	{
	}

	std::string getMessage() const { return message; }

private:
	std::string message;
};

