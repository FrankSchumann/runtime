#include "RuntimeAdapter.h"

#include <iostream>

RuntimeAdapter::RuntimeAdapter(std::string const &_type, std::string const &_name) : type(_type), name(_name)
{
}

RuntimeAdapter::~RuntimeAdapter()
{
}

std::string RuntimeAdapter::getType()
{
	return type;
}

std::string RuntimeAdapter::getName()
{
	return name;
}

std::string RuntimeAdapter::getVersion()
{
	return std::string("0.0.0.1");
}

void RuntimeAdapter::startApplications()
{
	std::cout << "RuntimeAdapter::startApplications" << std::endl;
}

void RuntimeAdapter::stopApplications()
{
}

void RuntimeAdapter::subscribe()
{
}
