#include<iostream>
#include<iterator>

int main() {

    std::istream_iterator<int> it(std::cin);
    std::istream_iterator<int> end;

    while (it != end) {
        std::cout << *it << " ";
        ++it;
    }

    return 0;
}