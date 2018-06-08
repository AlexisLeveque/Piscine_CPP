//
// Created by Alexis LEVEQUE on 6/7/18.
//

#ifndef EX01_SPAN_HPP
#define EX01_SPAN_HPP

#include <iostream>
#include <vector>

class Span {
public:
	class TooManyNumberException : public std::exception {
	public:
		virtual const char* what() const throw() {
			return ("Can't add one more number");
		}
	};

	class NoSpanException : public std::exception {
	public:
		virtual const char* what() const throw() {
			return ("There isno span");
		}
	};

public:
	Span(unsigned int nbr);

	Span(Span const &src);

	Span &operator=(Span const &rhs);

	~Span(void);

	void	addNumber(int nbr);

	template<typename T>
	void	addNumber(T range);

	int	shortestSpan(void);

	int	longestSpan(void);

private:
	std::vector<int>	_vector;
	size_t 			_size_max;
	Span(void);


};


#endif //EX01_SPAN_HPP
