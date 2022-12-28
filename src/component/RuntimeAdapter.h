#pragma once

#include <map>
#include <memory>
#include <string>

#include "runtime-sdk/RuntimeAdapterIf.h"
#include "runtime-sdk/RuntimeIf.h"
#include "copa-pdk/component/ComponentControllerIf.h"

class RuntimeAdapter : public RuntimeAdapterIf
{
   public:
    RuntimeAdapter( std::string const &_type, std::string const &_name );
    RuntimeAdapter( std::string const &_type, std::string const &_name, std::shared_ptr< COPA::ComponentControllerIf > _componentController);
    ~RuntimeAdapter();

    virtual void startApplications() const override;
    virtual void stopApplications() const override;
    virtual void subscribe( std::string const &name, std::shared_ptr< RuntimeIf > const runtime ) override;
    virtual std::shared_ptr< RuntimeIf > get( std::string const &name ) const override;

    virtual std::string getType() const override;
    virtual std::string getName() const override;
    virtual std::string getVersion() const override;

   private:
    std::map< std::string, std::shared_ptr< RuntimeIf > > runtimes;
    std::shared_ptr< COPA::ComponentControllerIf > componentController;

    std::string type;
    std::string name;
};
