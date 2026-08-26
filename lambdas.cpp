#include <iostream>
#include <ranges>
#include <string>
#include <vector>

using namespace std;

struct Trail {
    string name;
    float distance;
    bool hasWaterfall;
};

/* This defines the stream insertion operator for
   Trail & the function getTrails() that returns a vector
   of trails. */
#include "setup"

// This currently filters trails (or any type with .distance).
template <typename T, typename Pred>
vector<T> filter(const vector<T>& all, Pred predicate) {
    vector<T> filtered;
    // Look at all items.
    for (T t : all) {
        if (predicate(t)) {
            filtered.push_back(t);
        }
    }
    return filtered;
}

// These are two predicates that you can use!
bool wouldMakePrestonHappy(Trail t) {
    return t.hasWaterfall;
}
bool isOneToThreeMiles(Trail t) {
    return t.distance > 1 && t.distance < 3;
}

struct StanfordID {
    std::string name;
    std::string sunet;
    int idNumber;
};

template <typename T> 
struct std::greater {
    bool operator() (const T& a, const T& b) const {
        return a > b;
    }
};

template <>
struct std::hash<StanfordID> {
    size_t operator()(const StanfordID& v) const {
        return 10; 
    }
};

struct my_functor {
    int operator()(int a) const {
        return a * value;
    }
    int value;
};
template <typename It, typename UnaryPred>
std::vector<It> find_all(It begin, It end, UnaryPred pred) {
    std::vector<It> its {begin};
    for (auto it = begin; it != end; ++it) {
        if (pred(*it)) {
            its.push_back(it);
        }
    }
    its.push_back(end);
    return its;
}

int main() {
    vector<Trail> allTrails = getTrails();
    
    // TASK: Replace these two lines with one lambda!
    
    vector<Trail> myTrails = filter(allTrails, [](const Trail& t) {
        return wouldMakePrestonHappy(t) && isOneToThreeMiles(t);
    });
    cout << "These are my trails:\n\n";
    for (const auto& t : myTrails) {
        if (t.hasWaterfall) cout << t << "\n";
    }

    std::greater<int> g;
    g(1, 2);

    auto isVowel = [](char c) {
        c = toupper(c);
        return c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
    };

    std::vector<char> letters = {'a', 'b', 'c', 'd', 'e'};
    std::vector<char> upperVowel = letters 
        | std::ranges::views::filter(isVowel) 
        | std::ranges::views::transform(toupper)
        | std::ranges::to<std::vector<char>>();
    return 0;
}