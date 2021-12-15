namespace std_overrides {
    template <typename T>
    inline void swap( T __x, T __y) noexcept
    {
        T __tmp = __x;
        __x = __y;
        __y = __tmp;
    }
    
}