#include <unity.h>
#include "pointers/SP.h"

class Test{
    public:
        int f;
};


void simple_test(){
    SP<Test> pointer(new Test()); 
    pointer->f = 1;
    SP<Test> p1 = pointer;
    TEST_ASSERT_EQUAL(1, p1 -> f);
    pointer->f = 2;
    TEST_ASSERT_EQUAL(2, p1 -> f);
    TEST_ASSERT_EQUAL(2, pointer -> f);
}

SP<Test> test_func(){
    SP<Test> pointer(new Test()); 
    pointer->f = 1;
    SP<Test> p1 = pointer;
    return p1;
}

void test_with_func(){
    SP<Test> res = test_func();
    TEST_ASSERT_EQUAL(1, res -> f);
}

void test_pointers(){
    RUN_TEST(simple_test);
    RUN_TEST(test_with_func);
}