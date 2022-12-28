#include "RuntimeControllerFactory.h"

#include <iostream>
#include <memory>

#include "../component/RuntimeController.h"

RuntimeControllerFactory::RuntimeControllerFactory()
{
}

RuntimeControllerFactory::~RuntimeControllerFactory()
{
}

std::shared_ptr< COPA::ComponentIf > RuntimeControllerFactory::create( std::string const &name ) const
{
    std::cout << "RuntimeControllerFactory::create" << std::endl;

    return std::make_shared< RuntimeController >( type, name );
}

std::string RuntimeControllerFactory::getType() const
{
    return type;
}
