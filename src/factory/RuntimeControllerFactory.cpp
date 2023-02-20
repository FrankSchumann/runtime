#include "RuntimeControllerFactory.h"

#include <iostream>
#include <memory>

#include "../component/RuntimeController.h"

RuntimeControllerFactory::RuntimeControllerFactory()
{
}

std::shared_ptr< core::ComponentIf > RuntimeControllerFactory::create( std::string const &name ) const
{
    std::cout << "RuntimeControllerFactory::create" << std::endl;

    return std::make_shared< RuntimeController >( type, name );
}

std::string RuntimeControllerFactory::getType() const
{
    return type;
}

std::vector< std::string > RuntimeControllerFactory::getDependencies() const
{
    std::vector< std::string > result;

    return result;
}
