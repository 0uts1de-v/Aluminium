#ifndef ALUMINIUM_SORT_QUICK
#define ALUMINIUM_SORT_QUICK

#include <utility>

namespace aluminium {
namespace sort {

template <class T>
void quick(T b, T e) {
    if (b == e)
        return;
    auto l = b, r = e - 1;
    while (l < r) {
        while (*r > *b)
            --r;
        while (*l <= *b && l < r)
            ++l;
        std::swap(*l, *r);
    }
    std::swap(*b, *l);
    quick(b, l);
    quick(l + 1, e);
}

} // namespace sort
} // namespace aluminium

#endif
