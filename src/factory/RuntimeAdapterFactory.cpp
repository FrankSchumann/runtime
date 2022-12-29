#include "RuntimeAdapterFactory.h"

#include <iostream>
#include <memory>

#include "../component/RuntimeAdapter.h"

RuntimeAdapterFactory::RuntimeAdapterFactory()
{
}

std::shared_ptr< COPA::ComponentIf > RuntimeAdapterFactory::create( std::string const &name ) const
{
    std::cout << "RuntimeFactory::create" << std::endl;

    return std::make_shared< RuntimeAdapter >( type, name );
}

std::string RuntimeAdapterFactory::getType() const
{
    return type;
}
