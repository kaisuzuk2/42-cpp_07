/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisuzuk <kaisuzuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 11:46:59 by kaisuzuk          #+#    #+#             */
/*   Updated: 2026/02/24 13:04:33 by kaisuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"
#include <iostream>
#include <string>

void header(int id, const std::string &title) {
	std::cout << "\n========== "<< id << ") " << title << " ==========" << std::endl;
}

template <typename T>
void printVal(const std::string &a, const std::string &b, T &v1, T &v2) {
	std::cout << a << " = " << v1 << ", " << b << " = " << v2 << std::endl;
}

int main( void ) {
	{
		header(0, "PFD");
		int a = 2;
		int b = 3;
		::swap( a, b );
		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
		std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
		std::string c = "chaine1";
		std::string d = "chaine2";
		::swap(c, d);
		std::cout << "c = " << c << ", d = " << d << std::endl;
		std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
		std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	}

	{
		header(1, "char test");
		char c1 = 'a';
		char c2 = 'b';
		::swap(c1, c2);
		printVal("c1", "c2", c1, c2);
		std::cout << "min(c1, c2) = " << ::min(c1, c2) << std::endl;
		std::cout << "max(c1, c2) = " << ::max(c1, c2) << std::endl;
	}

	{
		header(2, "float test");
		float f1 = 1.1f;
		float f2 = 1.2f;
		::swap(f1, f2);
		printVal("f1", "f2", f1, f2);
		std::cout << "min(f1, f2) = " << ::min(f1, f2) << std::endl;
		std::cout << "max(f1, f2) = " << ::max(f1, f2) << std::endl;
	}

	{
		header(3, "double test");
		double d1 = 123.45;
		double d2 = 42.111;
		::swap(d1, d2);
		printVal("d1", "d2", d1, d2);
		std::cout << "min(d1, d2) = " << ::min(d1, d2) << std::endl;
		std::cout << "max(d1, d2) = " << ::max(d1, d2) << std::endl;
	}

	{
		header(4, "equal test");
		int i1 = 42;
		int i2 = 42;
		printVal("i1", "i2", i1, i2);
		std::cout << "i1 = "  << &i1 << std::endl;
		std::cout << "i2 (expect) = " << &i2 << std::endl;
		std::cout << "min(i1, i2) = " << &::min(i1, i2) << std::endl;
		std::cout << "min(i1, i2) = " << &::max(i1, i2) << std::endl;
	}

	// error
	{
		// int i = 42;
		// float f = 42.195f;

		// std::cout << "min(f1, f2) = " << &::min(i, f);
	}
}
