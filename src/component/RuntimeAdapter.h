#pragma once

#include <map>
#include <memory>
#include <string>

#include "copa-pdk/component/ComponentControllerIf.h"
#include "runtime-sdk/RuntimeAdapterIf.h"
#include "runtime-sdk/RuntimeControllerIf.h"
#include "runtime-sdk/RuntimeIf.h"

class RuntimeAdapter : public RuntimeAdapterIf
{
   public:
    RuntimeAdapter( std::string const &_type, std::string const &_name );
    RuntimeAdapter( std::string const &_type, std::string const &_name,
                    std::shared_ptr< COPA::ComponentControllerIf > componentController );
    ~RuntimeAdapter();

    virtual void startApplications() const override;
    virtual void stopApplications() const override;

    virtual std::string getType() const override;
    virtual std::string getName() const override;
    virtual std::string getVersion() const override;

   private:
    std::shared_ptr< RuntimeControllerIf > runtimeController;

    std::string type;
    std::string name;
};
