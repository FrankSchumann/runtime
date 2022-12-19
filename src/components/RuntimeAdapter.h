#pragma once

#include <string>
#include "runtime-sdk/RuntimeAdapterIf.h"

class RuntimeAdapter : public RuntimeAdapterIf
{
   public:
    RuntimeAdapter( std::string const &_type, std::string const &_name );
    ~RuntimeAdapter();

    virtual std::string getType() override;
    virtual std::string getName() override;
    virtual std::string getVersion() override;

    virtual void startApplications() override;
    virtual void stopApplications() override;
    virtual void subscribe() override;

   private:
    std::string type;
    std::string name;

};
