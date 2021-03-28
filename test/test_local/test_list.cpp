#include <unity.h>
#include "SimpleList.h"
void test_list(void){
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