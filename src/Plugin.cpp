#include <iostream>
#include <memory>

#include "COPA-PDK/factory/FactoryController.h"
#include "factory/RuntimeFactory.h"

extern "C" void subscribePlugin()
{
    std::cout << "Runtime - subscribePlugin2" << std::endl;

    std::shared_ptr< COPA::FactoryController > factoryController = std::make_shared< COPA::FactoryController >();

    std::shared_ptr< COPA::FactoryIf > runtimeFactory = std::make_shared< RuntimeFactory >();

    factoryController->subscribe( runtimeFactory );

    factoryController->doSomething();
}
