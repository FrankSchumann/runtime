#pragma once

#include <map>
#include <memory>
#include <string>

#include "runtime-sdk/RuntimeAdapterIf.h"
#include "runtime-sdk/RuntimeIf.h"

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
    virtual void subscribe( std::string const &name, std::shared_ptr< RuntimeIf > const runtime ) override;
    virtual std::shared_ptr< RuntimeIf > get( std::string const &name ) const override;

   private:
    std::map< std::string, std::shared_ptr< RuntimeIf > > runtimes;

    std::string type;
    std::string name;
};