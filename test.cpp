#include <algorithm>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <random>
#include <vector>

#include "aluminium/aluminium.hpp"
#include "aluminium/macro.hpp"

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

    al::FisheirYates_shuffle(a.begin(), a.end(), engine);
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
    
    for (auto i : stalin) {
        std::cout << i << ", " << std::flush;
    }
    

    al::alprint();
    al::alprint(al::linear_search(a.begin(), a.end(), 50));
    al::alprint(al::linear_search(a.begin(), a.end(), 100));
    al::alprint(al::binary_search(a.begin(), a.end(), 50));
    al::alprint(al::binary_search(a.begin(), a.end(), 100));

    al::alprint();
    al::alprint(al::base64encode("al::base64"));
    al::alprint(al::base64encode_url("al::base64"));
    al::alprint(al::base64decode("QWx1bWluaXVtOjpiYXNlNjQ="));
    al::alprint(al::base64decode_url("QWx1bWluaXVtOjpiYXNlNjQ"));

    al::alprint();
    al::xorShift xs;
    al::LCGs lcgs;
    std::vector<int> r_xs(10), r_lcgs(10);
    al_REP(i, 10) {
        //xs.srand(1);
        r_xs.at(i) = xs.rand();
        r_lcgs.at(i) = lcgs.rand();
    }
    al::alprint("xorShift:", r_xs);
    al::alprint("LCGs:", r_lcgs);

    al::alprint();
    auto s = al::split("hello,world,1,2 2,3 3 3", ',');
    al::alprint(s);

    al::alprint();
    al::alprint("0! =", al::factorial(0));
    al::alprint("1! =", al::factorial(1));
    al::alprint("18! =", al::factorial(18));

    al::alprint();
    int n = 10000;

    al::alprint(n, ":", al::count_digit(n));
    n = -1000;
    al::alprint(n, ":", al::count_digit(n));
    n = 0;
    al::alprint(n, ":", al::count_digit(n));

    al::alprint();
    n = 210;
    auto facted_1 = al::prime_factorization(n);
    al::alprint(n, ":", facted_1);

    n = 1024;
    auto facted_2 = al::prime_factorization(n);
    al::alprint(n, ":", facted_2);

    n = 152100;
    auto facted_3 = al::prime_factorization(n);
    al::alprint(n, ":", facted_3);

    al::alprint();
    n = 36;
    std::vector<int> rho_n(100);
    al_REP(i, 100) {
        rho_n.at(i) = al::rho(n);
    }
    al::alprint(n, ":", rho_n);

    al::complex_ c;
    c.r(1);
    c.i(1.7320508);
    al::alprint(c.r(), c.i(), c.abs(), c.arg());

    return 0;
}
