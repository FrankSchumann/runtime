#pragma once

#include <string>

#include <core/component/ComponentIf.h>
#include "RuntimeIf.h"

class RuntimeAdapterIf : public core::ComponentIf
{
   public:
    virtual void startApplications() const = 0;
    virtual void stopApplications() const = 0;
};
