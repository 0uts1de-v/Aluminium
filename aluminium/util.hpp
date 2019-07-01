#ifndef ALUMINIUM_UTIL
#define ALUMINIUM_UTIL

#include <algorithm>
#include <string>

namespace aluminium {
namespace util {

// this function is same as std::erase_if() in C++20 or later.
// use this function only if you are using C++17 or earlier.
template <class CharT, class Traits, class Allocator, class Predicate>
void erase_if(std::basic_string<CharT, Traits, Allocator> &c, Predicate pred) {
    c.erase(std::remove_if(c.begin(), c.end(), pred), c.end());
}

} // namespace util
} // namespace aluminium

#endif
