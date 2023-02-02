#include <iostream>
#include <memory>

#include "config.h"
#include "factory/FactoryController.h"
#include "component/ComponentController.h"
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

    std::shared_ptr< COPA::ComponentController > componentController = std::make_shared< COPA::ComponentController >();

    std::shared_ptr< COPA::FactoryController > factoryController = std::make_shared< COPA::FactoryController >();

    std::shared_ptr< COPA::FactoryIf > runtimeAdapterFactory = std::make_shared< RuntimeAdapterFactory >();
    std::shared_ptr< COPA::FactoryIf > runtimeControllerFactory = std::make_shared< RuntimeControllerFactory >();

    auto const runtimeAdapterType = runtimeAdapterFactory->getType();
    auto const runtimeControllerType = runtimeControllerFactory->getType();

    componentController->erase( runtimeAdapterType );
    componentController->erase( runtimeControllerType );

    factoryController->unsubscribe( runtimeAdapterType );
    factoryController->unsubscribe( runtimeControllerType );

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
