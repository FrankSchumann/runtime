#pragma once

#include <string>
#include <memory>

#include "copa-pdk/factory/FactoryIf.h"
#include "copa-pdk/component/ComponentIf.h"

class RuntimeFactory : public COPA::FactoryIf
{
   public:
    RuntimeFactory();
    virtual ~RuntimeFactory();

    virtual std::shared_ptr< COPA::ComponentIf > create( std::string const &name ) override;
    virtual std::string getType() override;

   private:
    std::string type;
};
