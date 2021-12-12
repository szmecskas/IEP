#include <iostream>
#include "main.cpp"
#include <cstring>
using namespace std;

class child: public person {
    private:
        struct Child  
        {  
            std::string school;  
            int grade;  
        } c;

    public:
        child():person() {}

        child& operator*=(const child& x) {
            if(this == &x) {
                return *this;
            }
            person::operator*=(x);
            c.grade *= x.c.grade;
            return *this;
        }

        // copy assignment operator
        child& operator=(const child& x) {
            if(this == &x) {
                return *this;
            }
            person::operator=(x);
            c.grade=x.c.grade;
            c.school=x.c.school;
            return *this;
        }

        int printGrade() {
            std::cout<< "grade: " << c.grade <<std::endl;
            return this->c.grade;
        }

        ~child() {}

};

int main()
{
	child p1;
    child p2;
    p1.p.age= 13;
    p1 *= p2;
    std::cout<< "age: " << p1.p.age <<std::endl;
	return 0;
}
