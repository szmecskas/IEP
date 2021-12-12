#include <iostream>
#include <cstring>
using namespace std;

class person {
    public:
        struct Person  
        {  
            std::string name;  
            std::string citizenship;  
            int age = 3;  
        } p;

        person() { }

        person(std::string y, std::string x, int age) { 
            this->p.name = y;
            this->p.citizenship = x;
            this->p.age = age;
        }

        // Copy constructor
        person(const person& x) {
            this->p.name = x.p.name;
            this->p.citizenship = x.p.citizenship;
            this->p.age = x.p.age;
         }

        person& operator*=(const person& x) {
           if(this == &x) {
                return *this;
            }
            p.age *= x.p.age;
            return *this;
        }

        // person& operator=(std::string x) {
        //     int count=0, i;
        //     for(i=p.name.length(); i <= p.name.length() + x.length(); i++);
        //         p.name[i] = x[count];
        //     return *this;
        // }

        // copy assignment operator
        person& operator=(const person& x) {
            if(this == &x) {
                return *this;
            }
            p = x.p;
            return *this;
        }

        std::string printName() {
            std::cout<< "name: " << p.name <<std::endl;
            return this->p.name;
        }

        std::string printCitizenship() {
            std::cout<< "citizenship: " << p.citizenship <<std::endl;
            return this->p.citizenship;
        }

        int printAge() {
            std::cout<< "age: " << p.age <<std::endl;
            return this->p.age;
        }

        ~person() {}

};

// int main()
// {
// 	person p1("Lidia","english",21);
//     person p2("Miha","romanian",18);
//     p1.printName();
//     p1 *= p2;
//     p1.printAge();
//     p1 = p2;
//     p1.printName();
// 	// person p2(p1); // calls copy constructor
// 	// p2 = p1; // calls copy assignment operator
// 	return 0;
// }
