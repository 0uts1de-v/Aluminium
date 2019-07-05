#ifndef ALUMINIUM_RANDOM
#define ALUMINIUM_RANDOM

#include <cstdint>
namespace aluminium {
namespace random {

class xorshift {
  private:
    std::uint32_t x = 2463534242;

  public:
    void srand(std::uint32_t seed);
    std::uint32_t rand();
};

void xorshift::srand(std::uint32_t seed) {
    x = seed;
}

std::uint32_t xorshift::rand() {
    x ^= (x << 13);
    x ^= (x >> 17);
    x ^= (x << 15);
    return x;
}

class LCGs {
  private:
    std::uint32_t x = 123456789;

  public:
    void srand(std::uint32_t seed);
    std::uint32_t rand();
};

void LCGs::srand(std::uint32_t seed) {
    x = seed;
}

std::uint32_t LCGs::rand() {
    // consts by Park & Miller
    const std::uint32_t a = 48271, m = 2147483647;

    x = (a * x) % m;

    return x;
}

} // namespace random
} // namespace aluminium

#endif
