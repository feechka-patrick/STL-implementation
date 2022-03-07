#include <vector>
#include <iostream>

#define lib std
class Test {
public:
    Test() : some_(0) {
        str_ = new char[1];
    }

    Test(int s) : some_(s) {
        str_ = new char[1];
    }

    Test(Test const & x) : some_(x.some_) {
        str_ = new char[1];
    }

    ~Test() {
        delete str_;
        this->some_ = 0;
        this->str_  = 0;
    }

    Test &operator=(Test const & x) {
        if (this == &x)
            return (*this);
        str_ = new char[1];
        this->some_ = x.some_;
        return (*this);
    }

    int   some_;
    char* str_;

};

int main(){
    lib::vector<Test> vv;

    vv.resize(100);
    std::cout << "capacity: " << vv.capacity() << std::endl;
    vv.resize(21);
    std::cout << "capacity: " << vv.capacity() << std::endl;
    vv.resize(10);
    std::cout << "capacity: " << vv.capacity() << std::endl;
}