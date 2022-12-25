#include "../component/RuntimeAdapter.h"

#include <iostream>

RuntimeAdapter::RuntimeAdapter( std::string const &_type, std::string const &_name ) : type( _type ), name( _name )
{
}

RuntimeAdapter::~RuntimeAdapter()
{
}

std::string RuntimeAdapter::getType()
{
    return type;
}

std::string RuntimeAdapter::getName()
{
    return name;
}

std::string RuntimeAdapter::getVersion()
{
    return std::string( "0.0.0.1" );
}

void RuntimeAdapter::startApplications()
{
    std::cout << "RuntimeAdapter::startApplications" << std::endl;

    for ( auto const &[ name, runtime ] : runtimes )
    {
        std::cout << "name: " << name << std::endl;

        runtime->startApplications();
    }
}

void RuntimeAdapter::stopApplications()
{
    std::cout << "RuntimeAdapter::stopApplications" << std::endl;

    for ( auto const &[ name, runtime ] : runtimes )
    {
        std::cout << "name: " << name << std::endl;

        runtime->stopApplications();
    }
}

void RuntimeAdapter::subscribe( std::string const &name, std::shared_ptr< RuntimeIf > const runtime )
{
    std::cout << "RuntimeAdapter::subscribe "
              << "name: " << name;
    runtimes[ name ] = runtime;
}

std::shared_ptr< RuntimeIf > RuntimeAdapter::get( std::string const &name ) const
{
    std::shared_ptr< RuntimeIf > result( nullptr );

    auto const it = runtimes.find( name );
    if ( it != runtimes.end() )
    {
        result = it->second;
    }

    return result;
}