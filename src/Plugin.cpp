#include <iostream>
#include <memory>

#include "config.h"
#include <core/factory/FactoryController.h>
#include <core/component/ComponentController.h>
#include "factory/RuntimeAdapterFactory.h"
#include "factory/RuntimeControllerFactory.h"

extern "C" void subscribePlugin()
{
    std::cout << "runtime - subscribePlugin" << std::endl;

    auto factoryController = std::make_shared< core::FactoryController >();

    std::shared_ptr< core::FactoryIf > runtimeAdapterFactory = std::make_shared< RuntimeAdapterFactory >();
    std::shared_ptr< core::FactoryIf > runtimeControllerFactory = std::make_shared< RuntimeControllerFactory >();

    factoryController->subscribe( runtimeAdapterFactory );
    factoryController->subscribe( runtimeControllerFactory );

    std::cout << std::endl;
}

extern "C" void unsubscribePlugin()
{
    std::cout << "runtime - unsubscribePlugin" << std::endl;

    auto componentController = std::make_shared< core::ComponentController >();

    auto factoryController = std::make_shared< core::FactoryController >();

    auto runtimeAdapterFactory = std::make_shared< RuntimeAdapterFactory >();
    auto runtimeControllerFactory = std::make_shared< RuntimeControllerFactory >();

    auto const runtimeAdapterType = runtimeAdapterFactory->getType();
    auto const runtimeControllerType = runtimeControllerFactory->getType();

    std::cout << "runtime - unsubscribePlugin before erase" << std::endl;
    componentController->list();
    componentController->erase( runtimeAdapterType );
    componentController->erase( runtimeControllerType );
    //componentController->erase( "RuntimeController" );
    std::cout << "runtime - unsubscribePlugin after erase" << std::endl;

    factoryController->unsubscribe( runtimeAdapterType );
    factoryController->unsubscribe( runtimeControllerType );

    std::cout << "runtime - unsubscribePlugin finished" << std::endl;
}

extern "C" const char* getName()
{
    return PLUGIN_NAME.c_str();
}

extern "C" const char* getVersion()
{
    return PLUGIN_VERSION.c_str();
}
