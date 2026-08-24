#include<iostream>
#include<istream>
#include<sstream>
#include<fstream>

int main1() {
    // std::string student_input;
    // std::cin >> student_input;
    // std::cout << "student input is: " << student_input << std::endl;

    std::ofstream fout("data.txt");
    fout << "I am writing to the file";

    std::ifstream fin("data.txt");
    std::string first_word;
    fin >> first_word;

    std::cout << "first word from file: " << first_word << std::endl;

    return 0;
}

int main2() {
    double pi;
    std::cin >> pi;
    std::cout << pi / 2 << "\n";
}

int main() {
    std::string initial_quote = "Bjarne Stroustoup C makes it easy to shoot yourself in the foot\n";
    std::stringstream ss(initial_quote);

    std::string first;
    std::string last;
    std::string language, extracted_quote;

    ss >> first >> last >> language;
    std::getline(ss, extracted_quote, '\n');
    std::cout << first << " " << last << "said this: " << language << " " << extracted_quote << std::endl;
    return 0;
}