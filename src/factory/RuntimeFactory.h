#pragma once

#include <string>

#include "copa-pdk/factory/FactoryIf.h"

class RuntimeFactory : public COPA::FactoryIf
{
   public:
    RuntimeFactory();
    virtual ~RuntimeFactory();

    virtual void create() override;
    virtual std::string getType() override;

   private:
    std::string type;
};
