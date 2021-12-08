#include "str_util.h"
namespace str_util {
    bool eq(const char * string1, const char * string2){
        return !strcmp(string1, string2);
    }
    SimpleList<SP<char>> split(const char * str, const char * delimiter){
        SimpleList<SP<char>> str_res;
        int start = 0;

        while(auto res = strstr(str + start, delimiter)){
            auto sizeToCopy = res - str + start;
            auto val = new char[sizeToCopy + 1];
            memcpy(val, str + start, sizeToCopy);
            val[sizeToCopy - 1] = 0;
            SP<char> pointer(val);
            str_res.add(pointer);
        }
        return str_res;
    }
}