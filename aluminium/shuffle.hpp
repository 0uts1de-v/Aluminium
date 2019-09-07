#ifndef ALUMINIUM_SHUFFLE
#define ALUMINIUM_SHUFFLE

#include <algorithm>

namespace aluminium {
namespace shuffle {

template <class T, class UniformRandomBitGenerator>
void FisheirYates_shuffle(T first, T last, UniformRandomBitGenerator &&g) {
    if (first == last)
        return;

    for (auto it = first + 1; it != last; ++it)
        std::iter_swap(it, first + (g() % (it - first)));
}

} // namespace shuffle
} // namespace aluminium

#endif
