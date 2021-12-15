#include <iostream>
#include <memory>
#include <cstring>
using namespace std;

class child{
    public:
        struct Child  
        {  
            std::string school;  
            int grade;  
            bool locked=false;
        } c;

        child() {}

        child(std::string school, int grade, bool locked) {
            this->c.school = school;
            this->c.grade = grade;
            this->c.locked = locked;
        }

        child(const child& y) {
            this->c.school = y.c.school;
            this->c.grade = y.c.grade;
            this->c.locked = y.c.locked;
         }

        child& operator*=(const child& x) {
            if(this == &x) {
                return *this;
            }

            c.grade *= x.c.grade;
            return *this;
        }

        // copy assignment operator
        child& operator=(const child& x) {
            if(this == &x) {
                return *this;
            }
            c.grade=x.c.grade;
            c.school=x.c.school;
            return *this;
        }

        int printGrade() {
            std::cout<< "grade: " << c.grade <<std::endl;
            return this->c.grade;
        }

        void setLocked(bool lock) {
            this->c.locked=lock;
        }

        bool printLocked() {
            std::cout<<"Locked: "<<c.locked<<std::endl;
            return this->c.locked;
        }

        void resourceAvailable() {
            if(this->c.locked) {
                std::cout<<"Resursa ok"<<std::endl;
            } else {
                std::cout<<"Resursa blocata"<<std::endl;
            }
        }

        ~child() {}

};

void lock(child &c) {
    c.setLocked(true);
}

void unlock(child &c) {
    c.setLocked(false);
}

class LockChild {   
        child &lockChild;
    public:
        LockChild(child &c): lockChild(c) {
            lock(lockChild);
        }
        ~LockChild() {
            unlock(lockChild);
        }
};

int main()
{
	child p1("CNCB",5,true);
    LockChild *c = new LockChild(p1);
    p1.resourceAvailable();
    delete c;
    p1.resourceAvailable();
    // child p2("Moisil",7,false);
    // p1 *= p2;
    // std::cout<< "age: " << p1.age <<std::endl;
	// return 0;
}
