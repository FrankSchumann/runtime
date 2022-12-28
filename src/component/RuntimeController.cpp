#include "../component/RuntimeController.h"

#include <iostream>

RuntimeController::RuntimeController( std::string const &_type, std::string const &_name ) : type( _type ), name( _name )
{
}

RuntimeController::~RuntimeController()
{
}


void RuntimeController::subscribe( std::string const &name, std::shared_ptr< RuntimeIf > const runtime )
{
    std::cout << "RuntimeAdapter::subscribe "
              << "name: " << name;
    runtimes[ name ] = runtime;
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
