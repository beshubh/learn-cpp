#include<iostream>
#include<iterator>
#include<vector>


struct Bibble {
    int zarf;
};


int main1() {

    std::istream_iterator<int> it(std::cin);
    std::istream_iterator<int> end;

    while (it != end) {
        std::cout << *it << " ";
        ++it;
    }

    return 0;
}

int main2() {
    std::vector<Bibble> v{ { 10}};
    auto it = v.begin();
    int m = (*it).zarf;
    return 0;
}

int main3() {
    std::ostream_iterator<int> it(std::cout, ", ");
    *it = 10;
    ++it;
    *it = 20;
    ++it;
    *it = 30;
    return 0;
}

/**
 * EXERCISE: Implement binary search RECURSIVELY using vector iterators.
 * @param begin  Iterator to the start of the current search range
 * @param end    Iterator to the end of the current search range (exclusive) 
 * @param value  The integer to search for
 * @return       true if found, false otherwise
 */
bool binarySearch(std::vector<int>::iterator begin, std::vector<int>::iterator end, int value) {
    // 1. Base Case: If the range is empty, the value isn't here.
    if (begin >= end) {
        return false;
    }

    // 2. Calculate the midpoint
    auto mid = begin + (std::distance(begin, end) / 2);
    std::cout << "Mid is: " << *mid << std::endl;

    // 3. Recursive Logic
    if (*mid == value) {
        return true;
    } 
    
    if (*mid > value) {
        // Search the left half: [begin, mid)
        return binarySearch(begin, mid, value);
    } else {
        // Search the right half: [mid + 1, end)
        return binarySearch(mid + 1, end, value);
    }

    return false; // Placeholder
}

int main() {
    std::vector<int> data = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    
    int testValues[] = {23, 2, 91, 40}; // Found, Boundary (Start), Boundary (End), Not Found
    std::cout << "Recursive Iterator Binary Search Test:" << std::endl;
    for (int val : testValues) {
        std::cout << "Searching for " << val << ": " 
                  << (binarySearch(data.begin(), data.end(), val) ? "SUCCESS" : "FAILURE") 
                  << std::endl;
    }
    
    return 0;
}