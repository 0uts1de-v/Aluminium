#include <algorithm>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <random>
#include <vector>

#include "aluminium/aluminium.hpp"

int main() {
    al::hello();
    //al::print_loading("hello world", 1000, 50);
    //std::cout << std::endl;

    std::cout << std::setprecision(11) << "pi = " << al::pi(10) << "\ne = " << al::e(10) << std::endl;

    std::vector<int> a(100), b(50), stalin;
    std::iota(a.begin(), a.end(), 0);
    std::iota(b.begin(), b.end(), 0);
    std::copy(b.begin(), b.end(), std::back_inserter(a));
    std::random_device seed_gen;
    std::mt19937 engine(seed_gen());
    std::shuffle(a.begin(), a.end(), engine);
    al::quick_sort(a.begin(), a.end());
    //al::bubble_sort(a.begin(), a.end());
    //al::comb_sort(a.begin(), a.end());
    //al::insertion_sort(a.begin(), a.end());
    //al::selection_sort(a.begin(), a.end());
    //al::gnome_sort(a.begin(), a.end());
    //al::stooge_sort(a.begin(), a.end());
    //al::slow_sort(a.begin(), a.end() - 1);
    //al::bucket_sort(a.begin(), a.end());
    //al::hitler_sort(a.begin(), a.end());

    al::alprint(a);
    //al::stalin_sort(a, stalin);
    /*
    for (auto i : stalin) {
        std::cout << i << ", " << std::flush;
    }
    */
    std::cout << std::endl;

    std::cout << al::linear_search(a.begin(), a.end(), 50) << std::endl;
    std::cout << al::linear_search(a.begin(), a.end(), 100) << std::endl;

    std::cout << al::binary_search(a.begin(), a.end(), 50) << std::endl;
    std::cout << al::binary_search(a.begin(), a.end(), 100) << std::endl;

    std::cout << al::base64encode("al::base64") << std::endl;
    std::cout << al::base64encode_url("al::base64") << std::endl;

    std::cout << al::base64decode("QWx1bWluaXVtOjpiYXNlNjQ=") << std::endl;
    std::cout << al::base64decode_url("QWx1bWluaXVtOjpiYXNlNjQ") << std::endl;

    al::xorshift xs;
    std::vector<int> randoms(100);
    //al::LCGs lcgs;
    for (int i = 0; i < 100; ++i) {
        //xs.srand(1);
        randoms.at(i) = xs.rand();
    }
    al::alprint(randoms);
    std::cout << std::endl;

    //al::log("test", 0);

    auto s = al::split("hello,world,1,2 2,3 3 3", ',');
    al::alprint(s);

    std::cout << "0! = " << al::factorial(0) << std::endl;
    std::cout << "1! = " << al::factorial(1) << std::endl;
    std::cout << "18! = " << al::factorial(18) << std::endl;

    al::alprint();
    al::alprint("a", "bc", 123);
    al::alprint("d");

    std::cout << std::endl;

    int n = 10000;
    std::cout << n << ": " << al::count_digit(n) << std::endl;
    n = -1000;
    std::cout << n << ": " << al::count_digit(n) << std::endl;
    n = 0;
    std::cout << n << ": " << al::count_digit(n) << std::endl;

    std::cout << std::endl;

    n = 210;
    auto facted_1 = al::prime_factorization(n);
    al::alprint(n,":\n",facted_1);

    n = 1024;
    auto facted_2 = al::prime_factorization(n);
    al::alprint(n,":\n",facted_2);

    n = 152100;
    auto facted_3 = al::prime_factorization(n);
    al::alprint(n,":\n",facted_3);

    n = 36;
    std::vector<int> rho_n(100);
    for (int i = 0; i < 100; ++i) {
        rho_n.at(i) = al::rho(n);
    }
    al::alprint(n, ": ", rho_n);

    return 0;
}
