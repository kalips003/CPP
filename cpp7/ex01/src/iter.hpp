#ifndef ITER_CPP
#define ITER_CPP

#include <cstddef>
#include <iostream>

#include "../_colors.h"

template <typename T>
void    iter(T* array, size_t length, void (*f)(T&)) {
    for (size_t i = 0; i < length; i++)
        f(array[i]);
}

template <typename T>
void    ft_print(T& element) {
    std::cout << C_145 << element << RESET ", ";
}

#endif