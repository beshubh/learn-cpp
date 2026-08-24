#include<String>

class StandFord {
    using String = std::string;
private:
    String name;
    String sunet;
    int idNumer;
public:
    StandFord();
    StandFord(String name, String sunet, int idNumber);

    String getName();
    String getSunet();
    int getID();
    void setName(String name);
    void setSunet(String sunet);
    void setID(int id);
};