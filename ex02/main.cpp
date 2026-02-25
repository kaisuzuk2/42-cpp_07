/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisuzuk <kaisuzuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 11:49:28 by kaisuzuk          #+#    #+#             */
/*   Updated: 2026/02/26 08:21:33 by kaisuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include <cstdlib>
#include <string>
#include "Array.hpp"
#include "Array.tpp"

#define MAX_VAL 750

void header(int id, const std::string title) {
	std::cout << "\n========== " << id << ") " << title << " ==========" << std::endl;
}

template <typename T>
void printArr(T &arr) {
	unsigned int size = arr.size();
	for (unsigned int i = 0; i < size; i++) {
		std::cout << arr[i] << " ";
	}	
	std::cout << std::endl;
}

int main(int, char**)
{
    {
		header(0, "42main test");
		Array<int> numbers(MAX_VAL);
		int* mirror = new int[MAX_VAL];
		std::srand(time(NULL));
		for (int i = 0; i < MAX_VAL; i++)
		{
			const int value = std::rand();
			numbers[i] = value;
			mirror[i] = value;
		}
		//SCOPE
		{
			Array<int> tmp = numbers;
			Array<int> test(tmp);
		}

		for (int i = 0; i < MAX_VAL; i++)
		{
			if (mirror[i] != numbers[i])
			{
				std::cerr << "didn't save the same value!!" << std::endl;
				return 1;
			}
		}
		try
		{
			numbers[-2] = 0;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		try
		{
			numbers[MAX_VAL] = 0;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}

		for (int i = 0; i < MAX_VAL; i++)
		{
			numbers[i] = std::rand();
		}
		delete [] mirror;//
	}

	{
		header(1, "Default constructor");
		Array<int> arr;
		std::cout << "Size = " << arr.size() << std::endl;
		try {
			std::cout << arr[0] << std::endl; // error
		} catch (const std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}

	{
		header(2, "Arguments constructor");
		Array<int> arr(10);
		std::cout << "Size = " << arr.size() << std::endl; // 10
		try {
			printArr(arr);
			std::cout << std::endl;
		} catch (const std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}

	{
		header(3, "Copy constructor");
		Array<int> arrA(10);
		std::srand(time(0));
		for (unsigned int i = 0; i < arrA.size(); i++)
			arrA[i] = std::rand() % 10;
		Array<int> arrB(arrA);
		std::cout << "arrA: ";
		printArr(arrA);
		std::cout << "arrB: ";
		printArr(arrB);

		std::cout << "*** Deep copy test" << std::endl;
		std::cout << "arrA[0] = 42" << std::endl;
		arrA[0] = 42;
		std::cout << "arrA: ";
		printArr(arrA);
		std::cout << "arrB: ";
		printArr(arrB);

	}

	{
		header(4, "Copy assignment");
		Array<int> arrA(10);
		std::srand(time(0));
		for (unsigned int i = 0; i < arrA.size(); i++)
			arrA[i] = std::rand() % 10;
		Array<int> arrB(10);
		std::cout << "*** init" << std::endl;
		std::cout << "arrA: ";
		printArr(arrA);
		std::cout << "arrB: ";
		printArr(arrB);
		std::cout << "*** arrB = arrA" << std::endl;
		arrB = arrA;
		std::cout << "arrA: ";
		printArr(arrA);
		std::cout << "arrB: ";
		printArr(arrB);

		std::cout << "*** Deep copy test" << std::endl;
		std::cout << "arrA[0] = 42" << std::endl;
		arrA[0] = 42;
		std::cout << "arrA: ";
		printArr(arrA);
		std::cout << "arrB: ";
		printArr(arrB);
	}

	{
		header(5, "other type test");
		std::cout << "*** double" << std::endl;
		Array<double> arrd(10);
		for (unsigned int i = 0; i < arrd.size(); i++)
			arrd[i] = i * 1.234;
		std::cout << "arrd: ";
		printArr(arrd);

		std::cout << "*** char" << std::endl;
		Array<char> arrc(10);
		for (unsigned int i = 65; i < arrc.size() + 65; i++)
			arrc[i - 65] = i;
		std::cout << "arrc: ";
		printArr(arrc);

		std::cout << "*** string" << std::endl;
		Array<std::string> arrs(10);
		arrs[0] = "hello";
		arrs[1] = "world";
		arrs[2] = "42";
		std::cout << "arrs: ";
		printArr(arrs);
	}
    return 0;
}
