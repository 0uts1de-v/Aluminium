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

template <class T>
void bubble(T b, T e) {
    bool swapped = true;
    while (swapped) {
        swapped = false;
        for (auto it = b; it != e - 1; ++it) {
            if (*it > *(it + 1)) {
                std::swap(*it, *(it + 1));
                swapped = true;
            }
        }
    }
}

} // namespace sort
} // namespace aluminium

#endif
