#ifndef ALUMINIUM_RAND
#define ALUMINIUM_RAND

#include <cstdint>
namespace aluminium {
namespace random {

std::uint32_t xorshift() {
    static std::uint32_t x = 2463534242;
    x ^= (x << 13);
    x ^= (x >> 17);
    x ^= (x << 15);
    return x;
}

} // namespace random
} // namespace aluminium

#endif
