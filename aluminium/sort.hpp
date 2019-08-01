#ifndef ALUMINIUM_SORT
#define ALUMINIUM_SORT

#include <utility>
#include <vector>

namespace aluminium {
namespace sort {

template <class T>
void quick_sort(T b, T e) {
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
    for (auto it = b; it < e - 1; ++it) {
        min = it;
        for (auto it_2 = it + 1; it_2 < e; ++it_2) {
            if (*it_2 < *min)
                min = it_2;
        }
        std::swap(*it, *min);
    }
}

template <class T>
void gnome_sort(T b, T e) {
    auto it = b;
    while (it < e - 1) {
        if (*it < *(it + 1)) {
            ++it;
        } else {
            std::swap(*it, *(it + 1));
            --it;
            if (it == b - 1)
                ++it;
        }
    }
}

template <class T>
void stooge_sort(T b, T e) {
    if (*b > *(e - 1)) {
        std::swap(*b, *(e - 1));
    }
    if (e - b > 2) {
        int t = (e - b) / 3;
        stooge_sort(b, e - t);
        stooge_sort(b + t, e);
        stooge_sort(b, e - t);
    }
}

template <class T>
void slow_sort(T b, T e) {
    if (b >= e) {
        return;
    }
    auto m = b + (e - b) / 2;
    slow_sort(b, m);
    slow_sort(m + 1, e);
    if (*m > *e) {
        std::swap(*m, *e);
    }
    slow_sort(b, e - 1);
}

template <class T>
void bucket_sort(T b, T e) {
    int max = -1;
    for (auto it = b; it < e; ++it) {
        if (max < *it) {
            max = *it;
        }
    }
    std::vector<unsigned int> bucket(max + 1);
    for (auto it = b; it < e; ++it) {
        ++bucket[*(it)];
    }
    int k = 0;
    for (int i = 0; i <= max; ++i) {
        for (unsigned int j = 0; j < bucket[i]; ++j) {
            *(b + k) = i;
            ++k;
        }
    }
}

template <class T>
void stalin_sort(const std::vector<T> &b, std::vector<T> &a) { // before, after
    auto tmp = b.at(0);
    a.push_back(tmp);
    for (unsigned int i = 1; i < b.size(); ++i) {
        if (b.at(i) >= tmp) {
            tmp = b.at(i);
            a.push_back(tmp);
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
