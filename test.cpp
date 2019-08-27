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

    for (auto i : a) {
        std::cout << i << ", " << std::flush;
    }
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
    //al::LCGs lcgs;
    for (int i = 0; i < 100; ++i) {
        //xs.srand(1);
        std::cout << xs.rand() << ", ";
    }
    std::cout << std::endl;

    //al::log("test", 0);

    std::vector<std::string> s;
    s = al::split("hello,world,1,2 2,3 3 3", ',');
    for (const auto &i : s) {
        std::cout << i << std::endl;
    }

    std::cout << "0! = " << al::factorial(0) << std::endl;
    std::cout << "1! = " << al::factorial(1) << std::endl;
    std::cout << "18! = " << al::factorial(18) << std::endl;

    al::alprint();
    al::alprint("a", "bc", 123);
    al::alprint("d");

    return 0;
}
