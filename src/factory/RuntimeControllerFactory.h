#pragma once

#include <memory>
#include <string>

#include "copa-pdk/component/ComponentIf.h"
#include "copa-pdk/factory/FactoryIf.h"

class RuntimeControllerFactory : public COPA::FactoryIf
{
   public:
    RuntimeControllerFactory();

    virtual std::shared_ptr< COPA::ComponentIf > create( std::string const &name ) const override;
    virtual std::string getType() const override;

   private:
    const std::string type = std::string( "RuntimeController" );
};
