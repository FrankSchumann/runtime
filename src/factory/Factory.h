#pragma once

#include "COPA-PDK/factory/FactoryIf.h"
#include <string>

namespace Runtime
{

class Factory : public COPA::FactoryIf
{
public:
	Factory(std::string const &_name);
	virtual ~Factory();

	virtual void create() override;
	virtual std::string getName() override;

private:
	std::string name;
};

}
