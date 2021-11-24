#include <unity.h>
#include "collections/SimpleList.h"

void test_resize(){
    SimpleList <int>list(10);
    for(int i=0; i<1022; i++){
        list.add(i);
    }
    TEST_ASSERT_EQUAL_INT(1022, list.get_size());
    TEST_ASSERT_EQUAL_INT(1025, list.get_array_size());
    for(int i=0; i<list.get_size(); i++){
        TEST_ASSERT_EQUAL_INT(i, list.get(i));
    }

    list.resize_to(10);
    TEST_ASSERT_EQUAL_INT(10, list.get_size());
    TEST_ASSERT_EQUAL_INT(10, list.get_array_size());
    for(int i=0; i<list.get_size(); i++){
        TEST_ASSERT_EQUAL_INT(i, list.get(i));
    }
}

void test_pop(){

    SimpleList <int>list_new(5);
    list_new.add(1);
    list_new.add(2);
    list_new.add(3);
    list_new.add(4);
    list_new.add(5);
    TEST_ASSERT_EQUAL_INT(5, list_new.pop());
    TEST_ASSERT_EQUAL_INT(4, list_new.pop());
    TEST_ASSERT_EQUAL_INT(3, list_new.pop());
    TEST_ASSERT_EQUAL_INT(2, list_new.pop());
    TEST_ASSERT_EQUAL_INT(1, list_new.pop());
    TEST_ASSERT_EQUAL_INT(1, list_new.pop());

    list_new.clear();
    list_new.add(1024);
    TEST_ASSERT_EQUAL_INT(1, list_new.get_size());
    TEST_ASSERT_EQUAL_INT(5, list_new.get_array_size());
    TEST_ASSERT_EQUAL_INT(1024, list_new.pop());
}


void test_remove(){

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

void test_copy(){

    SimpleList <int>list_new(5);
    list_new.add(1);
    list_new.add(2);
    list_new.add(3);
    list_new.add(4);
    list_new.add(5);

    SimpleList <int>list_new_1 = list_new;
    TEST_ASSERT_EQUAL_INT(5, list_new_1.get_size());
}


void test_list(void){
    RUN_TEST(test_resize);
    RUN_TEST(test_pop);
    RUN_TEST(test_remove);
    RUN_TEST(test_copy);
}