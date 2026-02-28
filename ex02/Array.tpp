/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisuzuk <kaisuzuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 09:37:47 by kaisuzuk          #+#    #+#             */
/*   Updated: 2026/02/28 09:40:33 by kaisuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template <typename T>
Array<T>::Array(): _data(NULL), _size(0) {}

template <typename T>
Array<T>::Array(unsigned int size): _data(new T[size]()), _size(size) {}

template <typename T>
Array<T>::Array(const Array &other): _data(NULL), _size(0) {
	*this = other;
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &other) {
	if (this != &other) {
		T *newArr = NULL;
		unsigned int size = other.size();
		try {
			newArr = new T[size]();
			for (unsigned int i = 0; i < size; i++)
				newArr[i] = other._data[i];
		} catch (std::exception &e) {
			delete[] newArr;
			throw;
		}
		delete[] this->_data;
		this->_data = newArr;
		this->_size = other._size;
	}
	return (*this);
}

template <typename T>
Array<T>::~Array() {
	delete[] this->_data;
}

template <typename T>
void Array<T>::checkIndex(unsigned int idx) const {
	if (idx >= this->_size)
		throw std::out_of_range("Index out of bounds");
}

template <typename T>
T &Array<T>::operator[](unsigned int idx) {
	checkIndex(idx);
	return (this->_data[idx]);
}

template <typename T>
const T &Array<T>::operator[](unsigned int idx) const {
	checkIndex(idx);
	return (this->_data[idx]);
}

template <typename T>
unsigned int Array<T>::size() const {
	return (this->_size);
}
