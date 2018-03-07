#include "shared_ptr.h"

struct Test{

    explicit Test(int val = 0):value(val){}
    int value;
};

using smart_point::shared_ptr;

int main()
{
    auto t = new Test();
    shared_ptr<Test> ptr_test(t);
    shared_ptr<Test> copy_test = ptr_test;

    std::cout<<copy_test.ues_count()<<" "<<copy_test->value<<" "<<(*copy_test).value<<std::endl;

}