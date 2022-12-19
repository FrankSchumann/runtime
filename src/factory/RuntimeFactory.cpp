#include "RuntimeFactory.h"

#include <memory>

#include "../components/RuntimeAdapter.h"

RuntimeFactory::RuntimeFactory() : type( "RuntimeAdapter" )
{
}

RuntimeFactory::~RuntimeFactory()
{
}

std::shared_ptr< COPA::ComponentIf > RuntimeFactory::create( std::string const &name )
{
    return std::make_shared< RuntimeAdapter >(type, name);
}

std::string RuntimeFactory::getType()
{
    return type;
}
