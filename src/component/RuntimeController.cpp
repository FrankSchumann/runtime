#include "../component/RuntimeController.h"

#include <iostream>

RuntimeController::RuntimeController( std::string const &_type, std::string const &_name )
    : type( _type ), name( _name )
{
}

void RuntimeController::subscribe( std::string const &name, std::shared_ptr< RuntimeIf > const runtime )
{
    std::cout << "RuntimeController::subscribe "
              << "name: " << name << std::endl;
    runtimes[ name ] = runtime;
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
    return type;
}

std::string RuntimeController::getName() const
{
    return name;
}

std::string RuntimeController::getVersion() const
{
    return std::string( "0.0.0.1" );
}
