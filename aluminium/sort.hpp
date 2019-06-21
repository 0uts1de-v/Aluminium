#ifndef ALUMINIUM_SORT
#define ALUMINIUM_SORT

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

template <class T>
void comb(T b, T e) {
    unsigned int h = (e - b) / 1.3;
    bool swapped = true;
    while (swapped || h != 1) {
        swapped = false;
        for (auto it = b; it + h < e; ++it) {
            if (*it > *(it + h)) {
                std::swap(*it, *(it + h));
                swapped = true;
            }
        }
        if (h != 1) {
            h /= 1.3;
        }
        if (h == 9 || h == 10) {
            h = 11;
        }
    }

}

template <class T>
void tmp(T b, T e) {
}

} // namespace sort
} // namespace aluminium

#endif
