#include<cstddef>

template <typename T>
std::size_t Vector<T>::size() const noexcept {
    return elements.size();
}

template <typename T>
bool Vector<T>::empty() const noexcept {
    return elements.empty();
}

template <typename T>
T& Vector<T>::operator[](std::size_t index) {
    return elements[index];
}

template <typename T>
const T& Vector<T>::operator[](std::size_t index) const {
    return elements[index];
}

template <typename T>
T& Vector<T>::at(std::size_t index) {
    return elements.at(index);
}

template <typename T>
const T& Vector<T>::at(std::size_t index) const {
    return elements.at(index);
}

template <typename T>
void Vector<T>::push_back(const T& elem) {
    elements.push_back(elem);
}
