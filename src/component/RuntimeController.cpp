#include "../component/RuntimeController.h"

#include <iostream>

std::string const RuntimeController::type = std::string( "RuntimeController" );

RuntimeController::RuntimeController( std::string const &_name ) : name( _name )
{
}

void RuntimeController::subscribe( std::shared_ptr< RuntimeIf > const runtime )
{
    std::string const runtimeName = runtime->getName();
    runtimes[ runtimeName ] = runtime;

    std::cout << "RuntimeController::subscribe "
              << "name: " << runtimeName << std::endl;
}

void RuntimeController::unsubscribe( std::string const &name )
{
    runtimes.erase( name );
}

std::shared_ptr< RuntimeIf > RuntimeController::get( std::string const &name ) const
{
    std::shared_ptr< RuntimeIf > result( nullptr );

    auto const it = runtimes.find( name );
    if ( it != runtimes.end() )
    {
        result = it->second;
    }

    return result;
}

std::map< std::string, std::shared_ptr< RuntimeIf > > RuntimeController::getAll() const
{
    return runtimes;
}

std::string RuntimeController::getType() const
{
    return RuntimeController::type;
}

std::string RuntimeController::getName() const
{
    return name;
}

std::string RuntimeController::getVersion() const
{
    return std::string( "0.0.0.1" );
}
