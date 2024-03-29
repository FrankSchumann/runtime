#pragma once

#include <core/component/ComponentIf.h>

#include <map>
#include <memory>
#include <string>

#include "RuntimeIf.h"

class RuntimeControllerIf : public core::ComponentIf
{
   public:
    virtual void subscribe( std::shared_ptr< RuntimeIf > const runtime ) = 0;
    virtual void unsubscribe( std::string const& name ) = 0;
    virtual std::shared_ptr< RuntimeIf > get( std::string const& name ) const = 0;
    virtual std::map< std::string, std::shared_ptr< RuntimeIf > > getAll() const = 0;
};
