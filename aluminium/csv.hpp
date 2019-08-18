#ifndef ALUMINIUM_CSV
#define ALUMINIUM_CSV

#include <fstream>
#include <string>
#include <vector>

namespace aluminium {
namespace csv {

class csv {
    private:
    public:
        std::vector<std::vector<std::string>> load(std::ifstream file, const char sep);
        std::vector<std::vector<std::string>> loads(std::string data);
        int dump(std::vector<std::vector<std::string>> data, std::ofstream file, const char sep);
        std::string dumps(std::vector<std::vector<std::string>> data);
}

std::vector<std::vector<std::string>> csv::load(std::ifstream file, const char sep) {
}

std::vector<std::vector<std::string>> loads(std::string data) {
}

int csv::dump(std::ofstream file, const char sep) {
}

std::string dumps(std::vector<std::vector<std::string>> data) {
}


} // namespace csv
} // namespace aluminium

#endif
