#pragma once
#include <memory>
namespace std_overrides{
    template <typename T>
    class Allocator {
        public:
            static T* allocate(int size){
                return malloc(sizeof(T[size]));
            }

            static void deallocate(T * element){
                free(element);
            }

            static void destroy(T * element){
                element -> ~T();
            }
    };
}
