#include <iomanip>
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <random>

#include "aluminium/hello.hpp"
#include "aluminium/loading.hpp"
#include "aluminium/math/consts.hpp"
#include "aluminium/sort.hpp"
#include "aluminium/search.hpp"
#include "aluminium/base64.hpp"

int main() {
    aluminium::hello();
    //aluminium::print_loading("hello world", 1000, 50);
    //std::cout << std::endl;

    std::cout << std::setprecision(11) << "pi = " << aluminium::math::pi(10) << "\ne = " << aluminium::math::e(10) << std::endl;
    
    std::vector<int> a(100), b(50);
    std::iota(a.begin(), a.end(), 0);
    std::iota(b.begin(), b.end(), 0);
    std::copy(b.begin(), b.end(), std::back_inserter(a));
    std::random_device seed_gen;
    std::mt19937 engine(seed_gen());
    std::shuffle(a.begin(), a.end(), engine);
    //aluminium::sort::quick_sort(a.begin(), a.end());
    //aluminium::sort::bubble_sort(a.begin(), a.end());
    //aluminium::sort::comb_sort(a.begin(), a.end());
    //aluminium::sort::insertion_sort(a.begin(), a.end());
    //aluminium::sort::selection_sort(a.begin(), a.end());
    //aluminium::sort::gnome_sort(a.begin(), a.end());
    //aluminium::sort::stooge_sort(a.begin(), a.end());
    //aluminium::sort::slow_sort(a.begin(), a.end() - 1);
    aluminium::sort::bucket_sort(a.begin(), a.end());
    for (auto i : a) {
        std::cout << i << ", " << std::flush;
    }
    std::cout << std::endl;

    std::cout << aluminium::search::linear_search(a.begin(), a.end(), 50) << std::endl;
    std::cout << aluminium::search::linear_search(a.begin(), a.end(), 100) << std::endl;

    std::cout << aluminium::search::binary_search(a.begin(), a.end(), 50) << std::endl;
    std::cout << aluminium::search::binary_search(a.begin(), a.end(), 100) << std::endl;

    std::cout << aluminium::base64::base64encode("Aluminium::base64") << std::endl;
    std::cout << aluminium::base64::base64encode_url("Aluminium::base64") << std::endl;

    return 0;
}
