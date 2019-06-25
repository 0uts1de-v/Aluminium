#ifndef ALUMINIUM_SEARCH
#define ALUMINIUM_SEARCH

namespace aluminium {
namespace search {

template <class T, class T_value>
int linear_search(T b, T e, const T_value& key) {
    for (auto i = b; i < e; ++i) {
        if (*i == key) {
            return i - b;
        }
    }
    return -1;
}

template <class T, class T_value>
int binary_search(T b, T e, const T_value& key) {
    int l = -1, r = e - b, m;  //left, right, middle
    while (r - l > 1) {
        m = l + (r - l) / 2;
        if (*(b + m) >= key) {
            r = m;
        }
        else {
            l = m;
        }
    }
    if (*(b + r) != key || r == -1) {
        return -1;
    }
    else {
        return r;
    }
}

}
}

#endif
