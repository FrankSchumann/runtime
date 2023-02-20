#pragma once

#include <memory>
#include <string>

#include <core/component/ComponentIf.h>
#include <core/factory/FactoryIf.h>

class RuntimeControllerFactory : public core::FactoryIf
{
   public:
    RuntimeControllerFactory();

    virtual std::shared_ptr< core::ComponentIf > create( std::string const &name ) const override;
    virtual std::string getType() const override;
    virtual std::vector< std::string > getDependencies() const override;

   private:
    const std::string type = std::string( "RuntimeController" );
};
