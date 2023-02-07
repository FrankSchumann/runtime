#pragma once

#include <string>

#include <copa/component/ComponentIf.h>

class RuntimeIf : public COPA::ComponentIf
{
   public:
    virtual void startApplications() const = 0;
    virtual void stopApplications() const = 0;
    virtual std::string getRuntimeVersion() const = 0;
};
