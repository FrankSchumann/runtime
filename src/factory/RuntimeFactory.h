#pragma once

#include <memory>
#include <string>

#include "copa-pdk/component/ComponentIf.h"
#include "copa-pdk/factory/FactoryIf.h"

class RuntimeFactory : public COPA::FactoryIf
{
   public:
    RuntimeFactory();
    virtual ~RuntimeFactory();

    virtual std::shared_ptr< COPA::ComponentIf > create( std::string const &name ) override;
    virtual std::string getType() override;

   private:
    const std::string type = std::string( "RuntimeAdapter" );
};
