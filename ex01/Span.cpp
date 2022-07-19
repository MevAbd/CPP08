/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 13:12:09 by malbrand          #+#    #+#             */
/*   Updated: 2022/07/19 15:08:59 by malbrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.class.hpp"

//*********************************CONTRUCTOR**********************************//
Span::Span(unsigned int n) : _n(n), _mem(0)
{
	std::cout << "Contructor called for n = " << this->_n << "." << std::endl;
	return ;
}

Span::Span(const Span &rhs)
{
	std::cout << "Copy contructor called for n = " << this->_n << "." << std::endl;
	*this = rhs;
	return ;
}

//*********************************DESTRUCTOR**********************************//
Span::~Span(void)
{
	std::cout << "Destructor called for n = " << this->_n << "." << std::endl;
	return ;
}

//*********************************OPERATOR OVERLOAD******************************//
Span	&Span::operator=(const Span &rhs)
{
	this->_n = rhs._n;
	this->_mem = rhs._mem;
	return (*this);
}

std::ostream	&operator<<(std::ostream &o, const Span &rhs)
{
	for (unsigned int i = 0; i < rhs.getMem(); i++)
		o << rhs.getStorage(i) << " | ";
	return (o);
}

//*********************************MEMBER FONCTION********************************//
void	Span::addNumber(int nb)
{
	if (this->_n == 0 || this->_mem >= this->_n)
		throw noSpaceLeft();
	this->_mem++;
	this->_storage.push_back(nb);
}

void Span::addNumber(std::vector<int> src, unsigned int size)
{
    std::vector<int>::iterator begin = src.begin();
    std::vector<int>::iterator end = src.end();
    unsigned int i = 0;
    while (i < size && begin != end)
    {
        this->addNumber(*begin);
        begin++;
        i++;
    }
}


unsigned int		Span::longestSpan(void) const
{
	if (this->_n <= 1 || this->_mem <= 1)
		throw noSpan();

	std::vector<int> v(this->_storage);	
	int low, high;

	std::sort (v.rbegin(), v.rend());	
	high = *v.begin();

	std::sort (v.begin(), v.end());		
	low = *v.begin();

	return (high - low);
}

unsigned int	Span::getMem(void)const
{
	return (this->_mem);
}

int	Span::getStorage(int n)const
{
	return (this->_storage[n]);
}

unsigned int	Span::shortestSpan(void) const
{
	if (this->_n <= 1 || this->_mem <= 1)
		throw noSpan();

	unsigned int ret = UINT_MAX;
	std::vector<int> cpy(this->_storage);
	std::sort (cpy.begin(), cpy.end());

	std::vector<int>::iterator tmp = cpy.begin();
	std::vector<int>::iterator tmpNext = cpy.begin() + 1;

	while (tmpNext != cpy.end())
	{
		if ((unsigned int)(*tmpNext - *tmp) < ret)
			ret = *tmpNext - *tmp;
		++tmpNext;
		++tmp;
	}
	return (ret);
}
