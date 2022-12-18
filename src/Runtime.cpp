#include <iostream>
#include "config.h"

int main(int argc, char **argv) {
	std::cout << "Hello World" << std::endl;
	std::cout << "Version " << Runtime_VERSION_MAJOR << "." << Runtime_VERSION_MINOR << std::endl;

	std::cout << "MAJOR_VERSION" << VERSION_MAJOR << std::endl;
	return 0;
}
