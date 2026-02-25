/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisuzuk <kaisuzuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 09:19:05 by kaisuzuk          #+#    #+#             */
/*   Updated: 2026/02/24 13:05:45 by kaisuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <exception>

template <typename T> 
class Array {
	private:
		T *_data;
		unsigned int _size;
		void checkIndex(unsigned int) const;
	public:
		Array();
		Array(unsigned int);
		Array(const Array &);
		Array &operator=(const Array &);
		~Array();
		T &operator[](unsigned int);	
		const T &operator[](unsigned int) const;
		unsigned int size() const;
};

#endif
