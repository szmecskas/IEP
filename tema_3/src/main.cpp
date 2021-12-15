#include <iostream>
#include <cstring>
#include <memory>
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

using namespace std;
person* newPerson() {       //factory design pattern
    return (new person);
}

int main()
{
	// std::cout<<"unique-ptr"<<std::endl;
    // {
    //     unique_ptr<person> p1(newPerson());
    //     p1->printAge();
    //     unique_ptr<person> p2 = move(p1);
    //     //unique_ptr<person> p2(p1);
    //     p2->printAge();
    //     p1->printAge();
    // }
    std::cout<<"shared-ptr"<<std::endl;
    {
        shared_ptr<person> s1(newPerson());
        shared_ptr<person> s2(s1);
        shared_ptr<person> s3(s1);
        shared_ptr<person> s4(s1);
        s1->printAge();
        s2->printAge();
        std::cout<<"shared copy nr: "<<s1.use_count()<<std::endl;
        shared_ptr<person> s5 = move(s1);
        std::cout<<"shared copy nr: "<<s1.use_count()<<std::endl;
    }
    
	return 0;
}
