#pragma once

#include <string>

#include "copa-pdk/factory/FactoryIf.h"

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
