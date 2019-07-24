#ifndef ALUMINIUM_MATH
#define ALUMINIUM_MATH

#include <cmath>

namespace aluminium {
namespace math {

double round_n(double number, unsigned int n) {
    number = number * std::pow(10, n - 1);
    number = std::round(number);
    number /= std::pow(10, n - 1);
    return number;
}

double pi(unsigned int precision) {
    double pi = 3.141592653589793;
    return round_n(pi, precision);
}

double e(unsigned int precision) {
    double e = 2.718281828459045;
    return round_n(e, precision);
}

unsigned long long int factorial(unsigned int n) {
    unsigned long long int ans = 1;
    for (unsigned int i = 1; i <= n; ++i) {
        ans *= i;
    }
    return ans;
}

} // namespace math
} // namespace aluminium

#endif
