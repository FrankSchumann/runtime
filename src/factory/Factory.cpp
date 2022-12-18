#include "Factory.h"

namespace Runtime
{
Factory::Factory( std::string const &_name ) : name( _name )
{
}

Factory::~Factory()
{
}

void Factory::create()
{
}

std::string Factory::getName()
{
    return name;
}

}
