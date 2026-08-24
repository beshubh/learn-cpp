#pragma once

#include <cstddef>
#include <vector>

template <typename T>
class Vector {
public:
    std::size_t size() const noexcept;
    bool empty() const noexcept;

    T& operator[](std::size_t index);
    const T& operator[](std::size_t index) const;
    T& at(std::size_t index);
    const T& at(std::size_t index) const;
    void push_back(const T& elem);

private:
    std::vector<T> elements;
};

#include "Vector.cpp"
