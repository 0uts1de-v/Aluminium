#include "aluminium/hello.hpp"
#include "aluminium/loading.hpp"

int main() {
    aluminium::hello();
    aluminium::print_loading("hello world", 10000, 250);
    return 0;
}
