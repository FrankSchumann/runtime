#include "RuntimeFactory.h"

RuntimeFactory::RuntimeFactory() : type( "Runtime" )
{
}

RuntimeFactory::~RuntimeFactory()
{
}

std::shared_ptr< COPA::ComponentIf > RuntimeFactory::create( std::string const &name )
{
    return nullptr;
}

std::string RuntimeFactory::getType()
{
    return type;
}
