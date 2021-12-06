#include "str_util.h"
namespace str_util {
    bool eq(const char * string1, const char * string2){
        return !strcmp(string1, string2);
    }
}