#pragma once
#include <string.h>
#include "collections/SimpleList.h"
#include "pointers/SP.h"
namespace str_util {
    struct CharArray{
        char * data;
        ~CharArray(){
            delete data;
        }
    };

    inline int len(char * str){
        return strlen(str);
    }
    bool eq(const char * string1, const char * string2);
    SimpleList<SP<CharArray>> split(const char * str, const char * delimiter);
}
