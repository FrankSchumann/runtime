#include <iostream>
#include <memory>

#include "COPA-PDK/factory/FactoryController.h"
#include "factory/Factory.h"

static void subscribePluginIntern()
{
    std::cout << "Runtime - subscribePluginIntern" << std::endl;

    std::shared_ptr< COPA::FactoryController > factoryController = std::make_shared< COPA::FactoryController >();

    std::shared_ptr< COPA::FactoryIf > runtimeFactory = std::make_shared< Runtime::Factory >();

    factoryController->subscribe( runtimeFactory );

    factoryController->doSomething();
}

extern "C" void subscribePlugin()
{
    std::cout << "Runtime - subscribePlugin" << std::endl;

    subscribePluginIntern();
}
