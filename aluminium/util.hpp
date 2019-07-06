#ifndef ALUMINIUM_UTIL
#define ALUMINIUM_UTIL

#include <algorithm>
#include <chrono>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <string>

namespace aluminium {
namespace util {

// this function is same as std::erase_if() in C++20 or later.
// use this function only if you are using C++17 or earlier.
template <class CharT, class Traits, class Allocator, class Predicate>
void erase_if(std::basic_string<CharT, Traits, Allocator> &c, Predicate pred) {
    c.erase(std::remove_if(c.begin(), c.end(), pred), c.end());
}

// log level 0: INFO
//           1: WARN
//           2: ERROR
//           3: FATAL
//           4: DEBUG
//           5: TRACE
//     default: none
void log(std::string s, int level = -1) {
    auto time = std::chrono::system_clock::now();
    auto in_time_t = std::chrono::system_clock::to_time_t(time);

    std::stringstream ss;
    ss << std::put_time(std::localtime(&in_time_t), "%Y-%m-%d_%H") << ".log";
    std::string fname = ss.str();
    std::ofstream file(fname, std::ios::app);

    file << "[" << std::put_time(std::localtime(&in_time_t), "%Y-%m-%d %X") << "] ";

    switch (level) {
    case 0:
        file << "[INFO] ";
        break;
    case 1:
        file << "[WARN] ";
        break;
    case 2:
        file << "[ERROR] ";
        break;
    case 3:
        file << "[FATAL] ";
        break;
    case 4:
        file << "[DEBUG] ";
        break;
    case 5:
        file << "[TRACE] ";
        break;
    default:
        break;
    }
    file << s << "\n";
}

// split a string into vector
std::vector<std::string> split(const std::string &str, const char sep) {
    std::vector<std::string> result;
    std::stringstream ss(str);
    std::string buf;

    while(std::getline(ss, buf, sep)) {
        result.push_back(buf);
    }

    return result;
}

} // namespace util
} // namespace aluminium

#endif
