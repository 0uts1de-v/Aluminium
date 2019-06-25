#ifndef ALUMINIUM_SORT
#define ALUMINIUM_SORT

#include <utility>

namespace aluminium {
namespace sort {

template <class T>
void quicik_sort(T b, T e) {
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
    quick_sort(b, l);
    quick_sort(l + 1, e);
}

template <class T>
void bubble_sort(T b, T e) {
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
void comb_sort(T b, T e) {
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
void insertion_sort(T b, T e) {
    auto i = b;
    auto tmp = *b;
    for (auto it = b; it < e; ++it) {
        i = it - 1;
        tmp = *it;
        while (i >= b && *i > tmp) {
            *(i + 1) = *i;
            --i;
        }
        *(i + 1) = tmp;
    }
}

template <class T>
void selection_sort(T b, T e) {
    auto min = b;
    for (auto it = b; it < e - 1; ++it)
    {
        min = it;
        for (auto it_2 = it + 1; it_2 < e; ++it_2)
        {
            if (*it_2 < *min)
                min = it_2;
        }
        std::swap(*it, *min);
    }
}

template <class T>
void gnome_sort(T b, T e) {
    auto it = b;
    while (it < e - 1)
    {
        if (*it < *(it + 1))
        {
            ++it;
        }
        else
        {
            std::swap(*it, *(it + 1));
            --it;
            if (it == b - 1)
                ++it;
        }
    }
}

/*
template <class T>
void merge_sort(T b, T e) {
    if (left + 1 < right) {
        auto mid = (left + right) / 2;
        merge_sort(left, mid);
        merge_sort(mid, right);
        std::merge(A, left, mid, right);
    }
}

template <class T>
void tmp(T b, T e) {
}
*/

} // namespace sort
} // namespace aluminium

#endif
