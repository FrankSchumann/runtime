#pragma once

#include <string>
#include <memory>
#include <map>

#include <core/component/ComponentIf.h>
#include "RuntimeIf.h"

class RuntimeControllerIf : public core::ComponentIf
{
   public:
    virtual void subscribe( std::string const& name, std::shared_ptr< RuntimeIf > const runtime ) = 0;
    virtual std::shared_ptr< RuntimeIf > get( std::string const& name ) const = 0;
    virtual std::map< std::string, std::shared_ptr< RuntimeIf > > getAll() const = 0;
};
