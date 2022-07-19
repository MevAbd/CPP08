/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 12:37:56 by malbrand          #+#    #+#             */
/*   Updated: 2022/07/19 12:50:35 by malbrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main()
{
	std::list<int> test;
	for (int i = 0; i < 10; i++)
		test.push_back(i);

	std::list<int>::const_iterator	it = test.end();

	try
	{
		it = ::easyfind(test, 0);
		if (it != test.end())
			std::cout << *it << " found" << std::endl;
		it = ::easyfind(test, 1);
		if (it != test.end())
			std::cout << *it << " found" << std::endl;
		it = ::easyfind(test, 2);
		if (it != test.end())
			std::cout << *it << " found" << std::endl;
		it = ::easyfind(test, 3);
		if (it != test.end())
			std::cout << *it << " found" << std::endl;
		it = ::easyfind(test, 4);
		if (it != test.end())
			std::cout << *it << " found" << std::endl;
		it = ::easyfind(test, 5);
		if (it != test.end())
			std::cout << *it << " found" << std::endl;
		it = ::easyfind(test, 6);
		if (it != test.end())
			std::cout << *it << " found" << std::endl;
		it = ::easyfind(test, 7);
		if (it != test.end())
			std::cout << *it << " found" << std::endl;
		it = ::easyfind(test, 8);
		if (it != test.end())
			std::cout << *it << " found" << std::endl;
		it = ::easyfind(test, 9);
		if (it != test.end())
			std::cout << *it << " found" << std::endl;
		it = ::easyfind(test, 15);
		if (it != test.end())
			std::cout << *it << " found" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}
