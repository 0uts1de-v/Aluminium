#ifndef ALUMINIUM_MATH
#define ALUMINIUM_MATH

#include <cmath>
#include <map>
#include <numeric>
#include <vector>

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

std::vector<unsigned int> enumerate_prime(const unsigned int n) {
    std::vector<unsigned int> result(n);
    std::iota(result.begin(), result.end(), 0);
    for (unsigned int i = 2; i * i < n; ++i) {
        if (result.at(i) < i) continue;
        for (unsigned int j = i * i; j < n; j += i)
            if (result.at(j) == j) result.at(j) = i;
    }
    return result;
}

std::map<unsigned int, unsigned int> prime_factorization(unsigned int n) {
    std::map<unsigned int, unsigned int> result{};
    auto min_factor = enumerate_prime(n + 1);
    while (n > 1) {
        ++result[min_factor.at(n)];
        n /= min_factor.at(n);
    }
    return result;
}


} // namespace math
} // namespace aluminium

#endif
