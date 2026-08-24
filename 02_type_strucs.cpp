#include<string>
#include<iostream>
#include<utility>
#include<cmath>

// this is considered a bad practice;
// using namespace std;

int main() {
    /* type test*/
    std::string a = "test";
    double b = 3.2 * 5 - 1;
    float c = 5 / 2;
    return 0;
}
float d(int foo) { return foo / 2; }
double e(double foo) { return foo / 2; }
int f(double foo) { return (int)(foo + 0.5); }
void g(double c) { std::cout << c << std::endl; }




/* structs */
struct StanfordID {
    std::string name;
    std::string sunet;
    int idNumber;
};


StanfordID issueNewId() {
    StanfordID id = {"The stanford Tree", "theTREE", 0000002};
    return id;
}

struct Order
{
    std::string item;
    int quantity;
};


struct Point {
    double x;
    double y;
};

struct Circle {
    Point center;
    double radius;
};

using Zeros = std::pair<double, double>;
using Solution = std::pair<bool, Zeros>;

Solution solveQuadratic(double a, double b, double c) {
    auto t = b * b - 4 * a * c;
    if (t < 0) {
        return { false, {0.0, 0.0 }};
    }
    auto x1 = (-b + std::sqrt(t)) / 2 * a;
    auto x2 = (-b - std::sqrt(t)) / 2 * a;
    return { true, {x1, x2}};
}

