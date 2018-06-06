//
// Created by alexis on 06/06/2018.
//

template <typename T>
void	swap(T & x, T & y) {
	T z = x;
	x = y;
	y = z;
}