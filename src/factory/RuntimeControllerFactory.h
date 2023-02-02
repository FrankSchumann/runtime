#pragma once

#include <memory>
#include <string>

#include "component/ComponentIf.h"
#include "factory/FactoryIf.h"

class RuntimeControllerFactory : public COPA::FactoryIf
{
   public:
    RuntimeControllerFactory();

    virtual std::shared_ptr< COPA::ComponentIf > create( std::string const &name ) const override;
    virtual std::string getType() const override;
    virtual std::vector< std::string > getDependencies() const override;

   private:
    const std::string type = std::string( "RuntimeController" );
};
