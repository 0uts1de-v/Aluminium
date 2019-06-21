#ifndef ALUMINIUM_SORT_QUICK
#define ALUMINIUM_SORT_QUICK

#include <utility>

namespace aluminium {
namespace sort {

template <class T>
void quick_sort(T b, T e) {
    if(b == e) return;
    auto l = b, r = e - 1;
    while(l < r){
        while(*r > *b) --r;
        while(*l <= *b && l < r) ++l;
        std::swap(*l, *r);
	}
    std::swap(*b, *l);
    quick_sort(b, l);
    quick_sort(l + 1, e);
}

}
}

#endif
