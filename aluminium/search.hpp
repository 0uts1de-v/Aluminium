#ifndef ALUMINIUM_SEARCH
#define ALUMINIUM_SEARCH

namespace aluminium {
namespace search {

template <class T, class T_value>
long long int linear(T b, T e, const T_value& key) {
    for (auto i = b; i < e; ++i) {
        if (*i == key) {
            return i - b;
        }
    }
    return -1;
}

}
}

#endif
