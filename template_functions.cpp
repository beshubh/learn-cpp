#include<iostream>
#include <vector>

struct StanfordID {
    std::string name;
    std::string sunet;
    int idNumber;
};

template <typename T>
concept Comparable = requires(T a, T b) {
    { a < b} -> std::convertible_to<bool>;
};

// variadic templates
template<Comparable T>
T min(const T& v) { return v;}

template<Comparable T, Comparable... Args>
T min(const T& v, const Args&... args) {
    auto m = min(args...);
    return v < m ? v: m;
}

template<std::input_iterator Iterator, typename TElem>
Iterator find_me(
    Iterator begin,
    Iterator end,
    TElem value
) {
    Iterator it = begin;
    while (it != end) {
        if (*it == value) break;
        ++it;
    }
    return it;
}

void format(const std::string& fmt) {
    std::cout << fmt << std::endl;
}

template<typename T, typename... Args>
void format(const std::string& fmt, T value, Args... args) {
    auto pos = fmt.find("{}");
    if (pos == std::string::npos) throw std::runtime_error("Extra arg");
    std::cout << fmt.substr(0, pos);
    std::cout << value;
    format(fmt.substr(pos + 2), args...);
}

// Template Meta Programming (TMP)
template<size_t N>
struct Factorial {
    enum { value = N * Factorial<N - 1>::value };
};

template <>
struct Factorial<0> {
    enum { value = 1};
};

template<size_t N>
struct Fibonacci {
    enum { value = Fibonacci<N - 1>::value + Fibonacci<N - 2>::value};
};
template <>
struct Fibonacci<1> {
    enum { value = 1};
};

template <>
struct Fibonacci<0> {
    enum { value = 0};
};

// compiler may try to run this at compile time
constexpr size_t factorial(size_t n) {
    if (n == 0) return 1;
    return n * factorial(n - 1);
}

// compiler will run this at compile time by the order of consteval
consteval size_t factorial_compile(size_t n) {

    if (n == 0) return 1;
    return n * factorial_compile(n - 1);
}

int main() {
    const auto m = min<int>(106, 107);
    auto n = min(1.2, 2.5);
    const auto l = min(10, 20, 30, 4);
    const std::vector<std::string> v {"seven", "kingdoms"};
    auto it = find_me(v.begin(), v.end(), "kingdoms");
    StanfordID preston { "Preston", "pseay" };
    StanfordID rachel { "Rachel", "rfern" };
    // auto m = min<StanfordID>(preston, rachel); // won't compile
    format("Lecture {}: {} (week {})", 9, "Templates", 5);
    std::cout << Factorial<7>::value << "\n";
    std::cout << Fibonacci<10>::value << std::endl;
    return 0;
}