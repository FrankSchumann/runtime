#pragma once

#include <string>

#include <core/component/ComponentIf.h>

class RuntimeIf : public core::ComponentIf
{
   public:
    virtual void startApplications() const = 0;
    virtual void stopApplications() const = 0;
    virtual std::string getRuntimeVersion() const = 0;
};
