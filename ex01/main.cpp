/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisuzuk <kaisuzuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 08:20:27 by kaisuzuk          #+#    #+#             */
/*   Updated: 2026/02/24 08:34:11 by kaisuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>

template <typename T>
void print(T &x) {
	std::cout << x << " ";
}

template <typename T>
void printConst(const T &x) {
	std::cout << x << " ";
}

template <typename T>
void increment(T &x) {
	++x;
}

void header(int id, const std::string &title) {
	std::cout << "\n========== " << id << ") " << title << " ==========" << std::endl;
}

void sec(const std::string &sec_st) {
	std::cout << "*** " << sec_st << std::endl;
 }

int main(void) {
	{
		header(0, "int");	
		sec("print");
		int arr[] = {1, 2, 3, 4, 5};
		::iter(arr, sizeof(arr) / sizeof(arr[0]), print<int>);
		std::cout << std::endl;

		sec("increment");
		::iter(arr, sizeof(arr) / sizeof(arr[0]), increment<int>);
		::iter(arr, sizeof(arr) / sizeof(arr[0]), print<int>);
		std::cout << std::endl;
	}

	{
		header(1, "double");	
		sec("print");
		double arr[] = {1.1, 2.2, 3.3, 4.4, 5.5};
		::iter(arr, sizeof(arr) / sizeof(arr[0]), print<double>);
		std::cout << std::endl;

		sec("increment");
		::iter(arr, sizeof(arr) / sizeof(arr[0]), increment<double>);
		::iter(arr, sizeof(arr) / sizeof(arr[0]), print<double>);
		std::cout << std::endl;
	}

	{
		header(2, "const int");
		sec("print");
		const int arr[] = {1, 2, 3, 4, 5};
		::iter(arr, sizeof(arr) / sizeof(arr[0]), printConst<int>);
		std::cout << std::endl;
	}

}