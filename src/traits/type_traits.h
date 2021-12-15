#pragma once

namespace std_overrides{
    template<typename T>
    struct identity {
        typedef T type;
    };
    template<typename T>
    T&& forward(typename identity<T>::type&& param)
    {
        return static_cast<identity<T>::type&&>(param);
    }
}
