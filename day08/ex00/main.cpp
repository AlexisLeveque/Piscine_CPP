#include <vector>
#include <iostream>
#include <algorithm>
#include "easyfind.hpp"


int main() {
	std::vector<int> myvector;

	myvector.push_back(12);
	myvector.push_back(32);
	myvector.push_back(42);
	myvector.push_back(2);
	myvector.push_back(1);
	myvector.push_back(85);
	myvector.push_back(12);
	myvector.push_back(11);

	try {
		std::vector<int>::iterator it = easyfind(myvector, 20);
		std::cout << *it << std::endl;
	}
	catch (std::exception e) {
		std::cout << "No occurence" << std::endl;

	}

	myvector.push_back(20);
	try {
		std::vector<int>::iterator it = easyfind(myvector, 20);
		std::cout << *it << std::endl;
	}
	catch (std::exception e) {
		std::cout << "No occurence" << std::endl;
	}
	return 0;
}