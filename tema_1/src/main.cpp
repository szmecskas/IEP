#include<iostream>

class person {
    private:
    std::string eyes = "blue";
    std::string name = "Lidia";
    std::string mom = "Olena";
    std::string dad = "Fane";
    int age = 21;

    public:
    person() {}

    person(const person &p) { 
        std::string eyes = "brown";
        std::string name = "Miha";
        int age = 18;
    }

    person& operator=(const person& p) { 
        std::string eyes = "blue";
        std::string name = "Criss";
        int age = 10;
    }

    std::string printName() {
        std::cout <<"name: "<< std::endl;
        return this->name;
    }

    ~person() {}

};

int main() {
    person daughter1;
    person daughter2(daughter1);

    daughter1.printName();
    daughter2.printName();

    std::cout<<"Done"<<std::endl;
}

