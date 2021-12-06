#include <unity.h>
#include "test_list.h"
#include "test_promise.h"
#include "test_pointers.h"
#include "test_str.h"
int main(){
    test_list();
    test_promise();
    test_pointers();
    test_str_main();
}