#include "RuntimeFactory.h"

RuntimeFactory::RuntimeFactory() : type( "Runtime" )
{
}

RuntimeFactory::~RuntimeFactory()
{
}

void RuntimeFactory::create()
{
}

std::string RuntimeFactory::getType()
{
    return type;
}
