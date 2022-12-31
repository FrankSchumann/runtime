#include <iostream>
#include <memory>

#include "config.h"
#include "copa-pdk/factory/FactoryController.h"
#include "factory/RuntimeAdapterFactory.h"
#include "factory/RuntimeControllerFactory.h"

extern "C" void subscribePlugin()
{
    std::cout << "runtime - subscribePlugin" << std::endl;

    std::shared_ptr< COPA::FactoryController > factoryController = std::make_shared< COPA::FactoryController >();

    std::shared_ptr< COPA::FactoryIf > runtimeAdapterFactory = std::make_shared< RuntimeAdapterFactory >();
    std::shared_ptr< COPA::FactoryIf > runtimeControllerFactory = std::make_shared< RuntimeControllerFactory >();

    factoryController->subscribe( runtimeAdapterFactory );
    factoryController->subscribe( runtimeControllerFactory );

    std::cout << std::endl;
}

extern "C" void unsubscribePlugin()
{
    std::cout << "runtime - unsubscribePlugin" << std::endl;

    std::cout << std::endl;
}

extern "C" const char* getName()
{
    return PLUGIN_NAME.c_str();
}

extern "C" const char* getVersion()
{
    return PLUGIN_VERSION.c_str();
}
