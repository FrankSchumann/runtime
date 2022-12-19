#include "Factory.h"

namespace Runtime
{
Factory::Factory() : type( "Runtime" )
{
}

Factory::~Factory()
{
}

void Factory::create()
{
}

std::string Factory::getType()
{
    return type;
}

}
