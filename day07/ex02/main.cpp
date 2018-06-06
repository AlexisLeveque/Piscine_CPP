#include <iostream>
#include "Array.hpp"

int main() {
	Array<int> myIntArray0(0);
	Array<int> myIntArray1(1);
	std::cout << "myIntArray0.size() : " << myIntArray0.size() << std::endl;
	std::cout << "myIntArray1.size() : " << myIntArray1.size() << std::endl;
	std::cout << "myIntArray1[0] : " << myIntArray1[0] << std::endl;
	myIntArray1[0] = 42;
	std::cout << "myIntArray1[0] : " << myIntArray1[0] << std::endl << std::endl;
	Array<std::string> myStrArray3(3);
	myStrArray3[0] = "Bonjour,";
	myStrArray3[1] = "Non,";
	myStrArray3[2] = "Cordialement.";
	for (size_t i = 0; i < myStrArray3.size(); ++i) {
		std::cout << "myStrArray3[" << i << "] : " << myStrArray3[i] << std::endl;
	}

	try {
		std::cout << "Attempting to acces myStrArray3[4]" << std::endl;
		std::cout << myStrArray3[4] << std::endl;
		std::cout << "No problem all good" << std::endl;
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}


	return 0;
}