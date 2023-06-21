/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sciftci <sciftci@student.42kocaeli.com.tr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 01:26:25 by sciftci           #+#    #+#             */
/*   Updated: 2023/06/21 02:53:44 by sciftci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <cstring>

template <typename T>
class Array
{
private:
    T *_arr;
    size_t _len;

public:
    Array<T>() : _len(0)
    {
        _arr = new T[0];
    }

    Array<T>(unsigned int n) : _len(n)
    {
        _arr = new T[n];
    }

    ~Array<T>()
    {
        delete[] _arr;
    }

    Array<T>(Array<T> const &copy)
    {
        *this = copy;
        /*_len = copy._len;
        _arr = new T[_len];
        memcpy(_arr, copy._arr, _len * sizeof(T));
        
        for (size_t i = 0; i < _len; i++)
        {
            _arr[i] = copy._arr[i];
        }*/
    }

    Array<T> &operator=(Array<T> const &assign)
    {
        _len = assign._len;
        delete[] _arr;
        _arr = new T[_len];
        memcpy(_arr, assign._arr, _len * sizeof(T));
        /*
        for (size_t i = 0; i < _len; i++)
        {
            _arr[i] = assign._arr[i];
        }*/
        return *this;
    }

    T &operator[](size_t i)
    {
        return (i < _len) ? _arr[i] : throw OutofBoundAccassException();
    }

    unsigned int size() const
    {
        return _len;
    }

    T *getArr()
    {
        return _arr;
    }

    class OutofBoundAccassException : public std::exception
    {
        virtual const char *what() const throw()
        {
            return "Out of Bound Access!";
        }
    };
};

template <typename T>
std::ostream &operator<<(std::ostream &stream, Array<T> &arr)
{
    stream << "[";
    for (size_t i = 0; i < arr.size(); i++)
    {
        stream << arr.getArr()[i] << ", ";
    }
    stream << "]";
    return stream;
}
