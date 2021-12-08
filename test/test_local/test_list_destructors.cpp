#include <unity.h>
#include "collections/SimpleList.h"
namespace {
volatile static int __references = 0;
class MyClass{
    public:
        int a;
        MyClass(int a){
            __references ++;
            this->a = a;
            printf("--init called[%d]: %d\n", a,  __references);

        }

        MyClass(){
            __references ++;
            this->a = __references + 1000;
            printf("--init called[%d]: %d\n", a,  __references);
        }

        MyClass& operator = (const MyClass& old){
	        __references ++;
            printf("--eq called[%d]: %d\n", a,  __references);
            return *this;
	    }

        MyClass(const MyClass &old){
            __references ++;
            this->a = old.a + 9000;
            printf("--copy init called[%d]: %d\n", a,  __references);
        }

        ~MyClass(){
            __references --;
            printf("--deinit called[%d]: %d\n", a,  __references);
        }
};

void list_call(MyClass myClass){
    printf("creating 1\n");
    MyClass cls(1);
    printf("creating list 1\n");
    SimpleList<MyClass> azz(20);
    printf("adding arg to list 1\n");
    azz.add(myClass);
    printf("adding created var to list 1\n");
    azz.add(cls);
    printf("returning from list_call\n");
}

void test_desctuctors(){
    __references = 0;
    TEST_ASSERT_EQUAL_INT(0, __references);
    MyClass a(3);
    TEST_ASSERT_EQUAL_INT(1, __references);
    printf("entering list_call\n");
    list_call(a);
    printf("returned from list_call\n");
    TEST_ASSERT_EQUAL_INT(1, __references);
}


SimpleList<MyClass> class_list(){
    MyClass mc(2);
    SimpleList<MyClass> listToRet;
    listToRet.add(mc);
    printf("pre return:%d, %d\n", mc.a, __references);
    return listToRet;
}


void test_ret(){
    __references = 0;
    printf("calling class lst\n");
    auto res = class_list();
    printf("returned:%d, %d\n", res.get_size(), __references);
    TEST_ASSERT_EQUAL_INT(1, __references);
    printf("finished:%d\n", res.get_size());
}


void test_remove_destructors(){

    SimpleList <int>list_new(5);
    list_new.add(1);
    list_new.add(2);
    list_new.add(3);
    list_new.add(4);
    list_new.add(5);

    list_new.remove(1);
    TEST_ASSERT_EQUAL_INT(4, list_new.get_size());
    TEST_ASSERT_EQUAL_INT(1, list_new.get(0));
    TEST_ASSERT_EQUAL_INT(3, list_new.get(1));
    list_new.remove(3);
    list_new.remove(3);
    TEST_ASSERT_EQUAL_INT(3, list_new.get_size());
}

}


void test_list_destructors(void){
    RUN_TEST(test_remove_destructors);
    RUN_TEST(test_desctuctors);
    RUN_TEST(test_ret);
}