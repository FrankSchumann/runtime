#include <iostream>
#include "config.h"

int main(int argc, char **argv) {
	std::cout << "Hello World" << std::endl;
	std::cout << "Version " << PLUGIN_VERSION_MAJOR << "." << PLUGIN_VERSION_MINOR << std::endl;

	std::cout << "MAJOR_VERSION" << PLUGIN_VERSION_MAJOR << std::endl;
	return 0;
}
