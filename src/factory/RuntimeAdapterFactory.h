#pragma once

#include <memory>
#include <string>

#include "component/ComponentIf.h"
#include "factory/FactoryIf.h"

class RuntimeAdapterFactory : public COPA::FactoryIf
{
   public:
    RuntimeAdapterFactory();

    virtual std::shared_ptr< COPA::ComponentIf > create( std::string const &name ) const override;
    virtual std::string getType() const override;
    virtual std::vector< std::string > getDependencies() const override;

   private:
    const std::string type = std::string( "RuntimeAdapter" );
};
