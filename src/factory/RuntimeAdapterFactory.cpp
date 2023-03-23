#include "RuntimeAdapterFactory.h"

#include <iostream>
#include <memory>

#include "../component/RuntimeAdapter.h"

RuntimeAdapterFactory::RuntimeAdapterFactory()
{
}

std::shared_ptr< core::ComponentIf > RuntimeAdapterFactory::create( std::string const &name ) const
{
    std::cout << "RuntimeAdapterFactory::create" << std::endl;

    return std::make_shared< RuntimeAdapter >( name );
}

std::string RuntimeAdapterFactory::getType() const
{
    return RuntimeAdapter::type;
}

std::vector< std::string > RuntimeAdapterFactory::getDependencies() const
{
    std::vector< std::string > result;

    return result;
}
