#ifndef ALUMINIUM_MATH
#define ALUMINIUM_MATH

#include <cmath>
#include <map>

namespace aluminium {
namespace math {

double round_n(double number, const unsigned int n) {
    number = number * std::pow(10, n - 1);
    number = std::round(number);
    number /= std::pow(10, n - 1);
    return number;
}

unsigned int count_digit(long long int n) {
    unsigned int digits = 0;
    for (; n != 0; n /= 10, ++digits) {}
    return digits;
}

double pi(const unsigned int precision) {
    double pi = 3.141592653589793;
    return round_n(pi, precision);
}

double e(const unsigned int precision) {
    double e = 2.718281828459045;
    return round_n(e, precision);
}

unsigned long long int factorial(const unsigned int n) {
    unsigned long long int ans = 1;
    for (unsigned int i = 1; i <= n; ++i) {
        ans *= i;
    }
    return ans;
}

/*
std::vector prime_enum

std::map prime_factorization(const unsigned long long int n) {
    std::map<unsigned long long int, unsigned long long int> result{};
    const unsigned int root_n = int(std::sqrt(n)) + 1;
}
*/


} // namespace math
} // namespace aluminium

#endif
