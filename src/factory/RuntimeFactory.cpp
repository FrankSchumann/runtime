#include "RuntimeFactory.h"

#include <iostream>
#include <memory>

#include "../component/RuntimeAdapter.h"

RuntimeFactory::RuntimeFactory() : type( "RuntimeAdapter" )
{
}

RuntimeFactory::~RuntimeFactory()
{
}

std::shared_ptr< COPA::ComponentIf > RuntimeFactory::create( std::string const &name )
{
    std::cout << "RuntimeFactory::create" << std::endl;

    return std::make_shared< RuntimeAdapter >( type, name );
}

std::string RuntimeFactory::getType()
{
    return type;
}
