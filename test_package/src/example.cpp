#include "runtime/RuntimeIf.h"
#include "runtime/RuntimeControllerIf.h"
#include "runtime/RuntimeAdapterIf.h"

#include <iostream>

extern "C" const char* getName();
extern "C" const char* getVersion();

int main()
{
    std::cout << "Plugin : " << getName() << std::endl;
    std::cout << "Version: " << getVersion() << std::endl;
}

