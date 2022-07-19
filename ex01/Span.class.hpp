/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.class.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 13:09:33 by malbrand          #+#    #+#             */
/*   Updated: 2022/07/19 15:10:05 by malbrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_CLASS_HPP
# define SPAN_CLASS_HPP

# include <vector>
# include <iostream>
# include <climits>
# include <algorithm>

class Span
{
	private :
				Span(void){};
				unsigned int		_n;
				unsigned int		_mem;
				std::vector<int>	_storage;
	public :
	//**************************************************************************//
				Span(unsigned int n);
				Span(const Span &rhs);
	//**************************************************************************//
				virtual ~Span(void);
	//**************************************************************************//
				Span	&operator=(const Span &rhs);
	//**************************************************************************//
				void				addNumber(int nb);
 				void addNumber(std::vector<int> src, unsigned int size);
				unsigned int		shortestSpan(void)const;
				unsigned int		longestSpan(void)const;
				int					getStorage(int n) const;
				unsigned int		getMem(void) const;
	//**************************************************************************//
				class noSpaceLeft : public std::exception
				{
					const char *what() const throw() {return "You cant add more int.";}
				};
				class noSpan : public std::exception
				{
					const char *what() const throw() {return "I can't give a span. Sorry.";}
				};
};

std::ostream &operator<<(std::ostream &o, Span const &rhs);

#endif
