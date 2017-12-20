#ifndef SORTTEMPLATES_TSORT_H
#define SORTTEMPLATES_TSORT_H

#include <iostream>
template < typename T >
void Display (const T* beg, const T* end, char ofc = '\0'){
    for(const T *i = beg; i < end; i++){
        if(ofc != '\0')
            std::cout << ofc;
        std::cout << *i;
    }
}

template < typename T >
void InsertionSort (T* beg, T* end){
    if(end - beg < 2)
        return;

    T *i;
    T *j;
    T *k;
    T t;

    for(i = beg; i != end; ++i){
        t = *i;
        for(k = i, j = k--; j != beg && t < *k; --j, --k){
            *j = *k;
        }
        *j = t;
    }
}




#endif //SORTTEMPLATES_TSORT_H
