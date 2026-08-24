#include<iostream>
#include<map>
#include<tuple>
#include<vector>
#include<string>
#include<math.h>

void checkCool(float temp) {
    if (temp > 100.0) {
        std::cout << "Emergency cooling activated!" << std::endl;
    } else {
        std::cout << "Temperature normal. No emergency cooling required" << std::endl;
    }
}


// Direct initialization
int main1() {

    int numOne = 12.0;
    int numTwo(12.0);

    std::cout << "numOne is: " << numOne << std::endl;
    std::cout << "numTwo is: " << numTwo << std::endl;

    float tempReading(100.8);
    int temp = tempReading;
    checkCool(temp);

    return 0;
}

// Uniform initialization
int main2() {
    // does not works
    // int numOne = {12.0};
    int numOne  = { 12 };
    int numTwo{12};
    float tempReading { 100.8 };
    int temp { 100 };
    std::cout << "tempRead: " << tempReading << std::endl;
    return 0;
}

std::tuple<std::string, std::string, std::string> getClassInfo() {
    std::string className = "CS106L";
    std::string buildingName = "Thorton 110";
    std::string language = "C++";
    return {className, buildingName, language};
}

// Uniform map
int main3() {
    std::map<std::string, int> ages {
        { "Alice", 25},
        {"Bob", 30},
        {"Charlie", 35}
    };

    std::cout << "Alice's age: " << ages["Alice"] << std::endl;
    std::cout << "Bob's age: " << ages.at("Bob") << std::endl;
    // std::cout << "Non existing: " << ages.at("Nitika",) << std::endl;

    std::vector<int> numbers { 1, 2, 3, 4, 5};

    // Accessing vector elements
    for (int num: numbers) {
        std::cout << num << std::endl;
    }
    std::cout <<  std::endl;

    auto [className, buildingName, language] = getClassInfo();
    std::cout << "Come to " << buildingName << " and join us for " << className << " to learn " << language  << "!" << std::endl;
    return 0;
}

void squareN(int& n) {
    n = pow(n, 2);
}

int squareNVal(int n) {
    n = pow(n, 2);
    return n;
}

void buggyShift(std::vector<std::pair<int, int>> &nums) {
    // nothing done
    for (auto [num1, num2] /*copy*/: nums) {
        num1++;
        num2++;
    }
}

void shift(std::vector<std::pair<int, int>> &nums) {
    for (auto& [num1, num2] /*copy*/: nums) {
        num1++;
        num2++;
    }
}

// References
int main4() {
    int miToMoon = 238855;
    std::cout << "Moon is " << miToMoon << "mi away. " << std::endl;
    int& ISS = miToMoon;
    ISS -= 254;
    std::cout << "ISS is: " << ISS << "mi to moon." << std::endl;
    std::cout << "Moon is " << miToMoon << "mi away. " << std::endl;

    auto n = 10;
    squareN(n);

    auto x = 20;
    squareNVal(x);
    printf("n is: %d\n", n);
    printf("x is: %d\n", x);
    return 0;
}


// lvalue vs R-values

void powerOf2(int &n) {
    n = pow(n, 2);
}
int main5() {
    // won't work
    // powerOf2(10);
    int num = 10;
    powerOf2(num);
    return 0;
}

// const & reference
int main() {
    std::vector<int> vec { 1, 2, 3 };

    const std::vector<int> const_vec { 1, 2, 3};
    std::vector<int>& ref_vec { vec };
    const std::vector<int>& const_ref { vec };

    vec.push_back(3);
    // const_vec.push_back(3); // error
    ref_vec.push_back(3);
    // const_ref.push_back(3); // error

    const int a = 10;
    const int& b = a;
    // b++;
    std::cout << a << std::endl;
    return 0;
}