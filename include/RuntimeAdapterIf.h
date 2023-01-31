#pragma once

#include <string>

#include "copa-pdk/component/ComponentIf.h"
#include "RuntimeIf.h"

class RuntimeAdapterIf : public COPA::ComponentIf
{
   public:
    virtual void startApplications() const = 0;
    virtual void stopApplications() const = 0;
};
