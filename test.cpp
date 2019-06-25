#include <iomanip>
#include <iostream>
#include <vector>

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

    std::vector<int> a{13, 32, 272, 2, 2223, 22};
    aluminium::sort::quick_sort(a.begin(), a.end());
    //aluminium::sort::bubble_sort(a.begin(), a.end());
    //aluminium::sort::comb_sort(a.begin(), a.end());
    //aluminium::sort::insertion_sort(a.begin(), a.end());
    //aluminium::sort::selection_sort(a.begin(), a.end());
    //aluminium::sort::gnome_sort(a.begin(), a.end());
    for (auto i : a) {
        std::cout << i << std::endl;
    }

    std::cout << aluminium::search::linear_search(a.begin(), a.end(), 32) << std::endl;
    std::cout << aluminium::search::linear_search(a.begin(), a.end(), 34) << std::endl;

    std::cout << aluminium::search::binary_search(a.begin(), a.end(), 32) << std::endl;
    std::cout << aluminium::search::binary_search(a.begin(), a.end(), 34) << std::endl;

    //std::cout << aluminium::base64::encode("test") << std::endl;

    return 0;
}
