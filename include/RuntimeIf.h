#pragma once

#include <core/component/ComponentIf.h>

#include <string>

class RuntimeIf : public core::ComponentIf
{
   public:
    virtual void startApplications() const = 0;
    virtual void stopApplications() const = 0;
    virtual std::string getRuntimeVersion() const = 0;
};
