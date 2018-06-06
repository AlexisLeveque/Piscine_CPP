#include <iostream>

template <typename T>
void	iter(T tab[], size_t const & size, void (func)(T &)) {
	if (size > 0) {
		for (size_t i = 0; i < size; ++i) {
			func(tab[i]);
		}
	}
}

template <typename T>
void	calc(T & nbr) {
	nbr = nbr * 2;
}

void pow(int & nbr) {
	nbr = nbr*nbr;
}

int main() {
	int tabInt[] = {1, 2, 3, 4};
	size_t size = 4;
	::iter(tabInt, size, calc);
	for (size_t i = 0; i < size; ++i) {
		std::cout << "index: " << i << ", value: " << tabInt[i] << std::endl;
	}
	std::cout << std::endl;
	::iter(tabInt, size, pow);
	for (size_t i = 0; i < size; ++i) {
		std::cout << "index: " << i << ", value: " << tabInt[i] << std::endl;
	}
	std::cout << std::endl;



}