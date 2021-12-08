#pragma once
#include <string.h>
#include "collections/SimpleList.h"
#include "pointers/SP.h"
namespace str_util {
    inline int len(char * str){
        return strlen(str);
    }
    bool eq(const char * string1, const char * string2);
    SimpleList<SP<char>> split(const char * str, const char * delimiter);
}
