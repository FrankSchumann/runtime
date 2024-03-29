#include "core/component/ComponentController.h"

#include "core/factory/FactoryController.h"

namespace core
{
ComponentController::ComponentController()
{
}

ComponentController::ComponentController( std::shared_ptr< FactoryControllerIf > const &_factoryController )
{
}

void ComponentController::create( std::string const &type, std::string const &name )
{
}

std::shared_ptr< ComponentIf > ComponentController::get( std::string const &type, std::string const &name ) const
{
    return nullptr;
}

void ComponentController::erase( std::string const &type, std::string const &name )
{
}

void ComponentController::erase( std::string const &type )
{
}

void ComponentController::list() const
{
}

}
