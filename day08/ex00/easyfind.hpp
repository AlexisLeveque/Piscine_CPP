//
// Created by Alexis LEVEQUE on 6/7/18.
//

#include <algorithm>

template <typename T>
typename T::iterator 	easyfind(T tab, int i) {
	typename T::iterator it;
	it = std::find(tab.begin(), tab.end(), i);
	if (it == tab.end()) throw std::exception();
	return it;



}