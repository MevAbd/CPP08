/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 14:13:31 by malbrand          #+#    #+#             */
/*   Updated: 2022/07/19 15:17:40 by malbrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.class.hpp"

void	classicTest(void)
{
	Span	test(8);

	try
	{
		for (int i = 0; i < 10; i++)
		{
			test.addNumber(rand() % 100);
		}
	}
	catch(const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << test << std::endl;
	try
	{
		std::cout << test.longestSpan() << std::endl;
		std::cout << test.shortestSpan() << std::endl;
	}
	catch(const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}	
}

void	bigTest(void)
{
	Span	test(10000);

	try
	{
		for (int i = 0; i < 10000; i++)
		{
			test.addNumber(rand() % 100);
		}
	}
	catch(const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	//std::cout << test << std::endl;
	try
	{
		std::cout << test.longestSpan() << std::endl;
		std::cout << test.shortestSpan() << std::endl;
	}
	catch(const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

void	rangeIterator(void)
{
	std::vector<int> test;

	for (int i = 0; i < 20; i++)
	{
		test.push_back(rand() % 100);
		std::cout << test[i] << " | ";
	}
	std::cout << std::endl;

	Span	range(20);
	range.addNumber(test, 20);
	std::cout << range << std::endl;
}

int	main(void)
{
	std::cout << "********************CLASSIC TEST*********************" << std::endl;
	classicTest();

	std::cout << "********************BIG TEST*********************" << std::endl;
	bigTest();

	std::cout << "********************RANGE OF ITERATOR*********************" << std::endl;
	rangeIterator();
}


/*
int main()
{
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	return 0;
}*/
