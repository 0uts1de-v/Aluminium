#ifndef ALUMINIUM_LOADING
#define ALUMINIUM_LOADING

#include <chrono>
#include <iostream>
#include <string>
#include <thread>

namespace aluminium {

std::string decorate(std::string, int);

void print_loading(std::string str, int duration_ms, int speed_ms) {
    auto start = std::chrono::system_clock::now();
    while (duration_ms >= std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now() - start).count()) {
        for (unsigned long int i = 0; i < str.size(); ++i) {
            std::cout << "\r" << decorate(str, i) << std::flush;
            std::this_thread::sleep_for(std::chrono::milliseconds(speed_ms));
        }
    }
}

std::string decorate(std::string str, int i) {
    if (97 > str[i] or str[i] > 122) {
        return str;
    } else {
        str[i] -= 32;
        return str;
    }
}

}

#endif
