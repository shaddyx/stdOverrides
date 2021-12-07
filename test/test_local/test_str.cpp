#include <unity.h>
#include "str/str_util.h"

void test_str_cmp(){
    TEST_ASSERT_EQUAL(false, str_util::eq("aaa", "bbb"));
    TEST_ASSERT_EQUAL(true, str_util::eq("aaa", "aaa"));
    char str[] = "aaa";
    TEST_ASSERT_EQUAL(true, str_util::eq("aaa", str));
}


void test_str_main(void){
    RUN_TEST(test_str_cmp);   
}