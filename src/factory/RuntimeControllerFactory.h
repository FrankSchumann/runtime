#pragma once

#include <core/component/ComponentIf.h>
#include <core/factory/FactoryIf.h>

#include <memory>
#include <string>

class RuntimeControllerFactory : public core::FactoryIf
{
   public:
    RuntimeControllerFactory();

    virtual std::shared_ptr< core::ComponentIf > create( std::string const &name ) const override;
    virtual void cleanup( std::string const &name ) const override{};
    virtual std::string getType() const override;
    virtual std::vector< std::string > getDependencies() const override;
};
