#ifndef ALUMINIUM_RANDOM
#define ALUMINIUM_RANDOM

#include <cstdint>

namespace aluminium {
namespace random {

class xorShift {
  private:
    std::uint32_t x = 2463534242;

  public:
    xorShift(){};
    xorShift(std::uint32_t seed);
    void srand(std::uint32_t seed);
    std::uint32_t rand();
    std::uint32_t operator()();
};

xorShift::xorShift(std::uint32_t seed) {
    srand(seed);
}

void xorShift::srand(std::uint32_t seed) {
    x = seed;
}

std::uint32_t xorShift::rand() {
    x ^= (x << 13);
    x ^= (x >> 17);
    x ^= (x << 15);
    return x;
}

std::uint32_t xorShift::operator()() {
    return rand();
}

class LCGs {
  private:
    std::uint32_t x = 123456789;

  public:
    LCGs(){};
    LCGs(std::uint32_t);
    void srand(std::uint32_t seed);
    std::uint32_t rand();
    std::uint32_t operator()();
};

LCGs::LCGs(std::uint32_t seed) {
    srand(seed);
}

void LCGs::srand(std::uint32_t seed) {
    x = seed;
}

std::uint32_t LCGs::rand() {
    // consts by Park & Miller
    const std::uint32_t a = 48271, m = 2147483647;
    x = (a * x) % m;
    return x;
}

std::uint32_t LCGs::operator()() {
    return rand();
}

} // namespace random
} // namespace aluminium

#endif
