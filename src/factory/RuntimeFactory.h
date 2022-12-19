#pragma once

#include <string>

#include "COPA-PDK/factory/FactoryIf.h"

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
