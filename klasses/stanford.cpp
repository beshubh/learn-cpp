#include "stanford.h"
#include<string>

// default constructer
StandFord::StandFord() {
    name = "John Appleseed";
    sunet = "jappleseed";
    idNumer = 0000001;
}

StandFord::StandFord(std::string name, std::string sunet, int idNumber): 
name{name}, sunet{sunet}, idNumer{idNumber}{}

int StandFord::getID() {
    return this->idNumer;
}

std::string StandFord::getName() {
    return this->name;
}

std::string StandFord::getSunet() {
    return this->sunet;
}

void StandFord::setName(std::string name) {
    this->name = name;
}

void StandFord::setSunet(std::string sunet) {
    this->sunet = sunet;
}
void StandFord::setID(int id) {
 
    this->idNumer = id;
}


template <typename T>
class vector {
    using iterator = T*;
    // implmentation
};

int main() {

}