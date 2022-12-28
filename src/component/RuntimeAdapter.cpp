#include "../component/RuntimeAdapter.h"

#include <iostream>

#include "copa-pdk/component/ComponentController.h"

RuntimeAdapter::RuntimeAdapter( std::string const &_type, std::string const &_name )
    : RuntimeAdapter( _type, _name, std::make_shared< COPA::ComponentController >() )
{
}

RuntimeAdapter::RuntimeAdapter( std::string const &_type, std::string const &_name,
                                std::shared_ptr< COPA::ComponentControllerIf > componentController )
    : type( _type ), name( _name )
{
    auto const runtimeControllerTmp = componentController->get( "RuntimeController", "Mickey Mouse" );
    runtimeController = std::reinterpret_pointer_cast< RuntimeControllerIf >( runtimeControllerTmp );
}

RuntimeAdapter::~RuntimeAdapter()
{
}

void RuntimeAdapter::startApplications() const
{
    std::cout << "RuntimeAdapter::startApplications" << std::endl;

    auto const runtimes = runtimeController->getAll();

    for ( auto const &[ name, runtime ] : runtimes )
    {
        std::cout << "name: " << name << std::endl;

        runtime->startApplications();
    }
}

void RuntimeAdapter::stopApplications() const
{
    std::cout << "RuntimeAdapter::stopApplications" << std::endl;

    auto const runtimes = runtimeController->getAll();

    for ( auto const &[ name, runtime ] : runtimes )
    {
        std::cout << "name: " << name << std::endl;

        runtime->stopApplications();
    }
}

std::string RuntimeAdapter::getType() const
{
    return type;
}

std::string RuntimeAdapter::getName() const
{
    return name;
}

std::string RuntimeAdapter::getVersion() const
{
    return std::string( "0.0.0.2" );
}
