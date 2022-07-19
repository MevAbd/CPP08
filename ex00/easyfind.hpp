/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 07:41:41 by malbrand          #+#    #+#             */
/*   Updated: 2022/07/19 12:43:13 by malbrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <algorithm>
# include <string>
# include <exception>
# include <list>

class notFound : public std::exception
{
    virtual const char *what() const throw() {return ("Not found.");};
};

template <typename T> typename T::iterator easyfind(T &t, int i)
{
    typename T::iterator it = std::find(t.begin(), t.end(), i);
    if(it == t.end())
        throw notFound();
    return (it);
}

#endif
