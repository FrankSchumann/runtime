#pragma once

#include <map>
#include <memory>
#include <string>

#include "RuntimeControllerIf.h"
#include "RuntimeIf.h"

class RuntimeController : public RuntimeControllerIf
{
   public:
	RuntimeController( std::string const &_type, std::string const &_name );

    virtual void subscribe( std::string const &name, std::shared_ptr< RuntimeIf > const runtime ) override;
    virtual void unsubscribe( std::string const &name ) override;
    virtual std::shared_ptr< RuntimeIf > get( std::string const &name ) const override;
    virtual std::map< std::string, std::shared_ptr< RuntimeIf > > getAll() const override;

    virtual std::string getType() const override;
    virtual std::string getName() const override;
    virtual std::string getVersion() const override;

   private:
    std::map< std::string, std::shared_ptr< RuntimeIf > > runtimes;

    std::string type;
    std::string name;
};
