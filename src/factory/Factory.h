#pragma once

#include <string>

#include "COPA-PDK/factory/FactoryIf.h"

namespace Runtime
{
class Factory : public COPA::FactoryIf
{
   public:
    Factory();
    virtual ~Factory();

    virtual void create() override;
    virtual std::string getType() override;

   private:
    std::string type;
};

}
