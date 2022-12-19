#include <iostream>
#include <memory>

#include "COPA-PDK/factory/FactoryController.h"
#include "factory/RuntimeFactory.h"
#include "config.h"

extern "C" void subscribePlugin()
{
    std::cout << "Runtime - subscribePlugin2" << std::endl;

    std::shared_ptr< COPA::FactoryController > factoryController = std::make_shared< COPA::FactoryController >();

    std::shared_ptr< COPA::FactoryIf > runtimeFactory = std::make_shared< RuntimeFactory >();

    factoryController->subscribe( runtimeFactory );

    factoryController->doSomething();
}

extern "C" const char* getName()
{
	return PLUGIN_NAME.c_str();
}

extern "C" const char* getVersion()
{
	return PLUGIN_VERSION.c_str();
}
