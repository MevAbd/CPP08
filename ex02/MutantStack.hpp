/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 15:30:59 by malbrand          #+#    #+#             */
/*   Updated: 2022/07/19 15:41:45 by malbrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP
#include "iostream"
#include "string"
#include "list"
#include "stack"
#include "algorithm"

template<typename T>

class MutantStack : public std::stack<T>
{
public:
    MutantStack(void) : std::stack<T>(){};
    MutantStack(const MutantStack &rhs) : std::stack<T>(rhs){};
    ~MutantStack(void){};

    typedef typename std::stack<T>::container_type::iterator iterator;
    typedef typename std::stack<T>::container_type::const_iterator const_iterator;
    typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
    typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

    iterator begin(){return this->c.begin();}
    iterator end(){return this->c.end();}

    const_iterator cbegin(){return this->c.cbegin();}
    const_iterator cend(){return this->c.cend();}

    reverse_iterator rbegin(){return this->c.rbegin();}
    reverse_iterator rend(){return this->c.rend();}

    const_reverse_iterator crbegin(){return this->c.crbegin();}
    const_reverse_iterator crend(){return this->c.crend();}

    MutantStack &operator=(const MutantStack &src);
};

template <typename T> MutantStack<T> &MutantStack<T>::operator=(const MutantStack &rhs) {
    if (this != rhs)
        this->c.operator=(rhs);
    return (*this);
}


#endif
