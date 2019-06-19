#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include "loading.hpp"

std::string decorate(std::string, int);

void print_loading(std::string str, int duaration_ms, int speed_ms) {
    while (true) {
        for (unsigned long int i = 0; i < str.size(); ++i) {
            std::cout << "\r" << decorate(str, i) << std::flush;
            std::this_thread::sleep_for(std::chrono::milliseconds(speed_ms));
        }
    }
}

std::string decorate(std::string str, int i) {
    if (97 > str[i] or str [i] > 122) {
        return str;
    }
    else {
        str[i] -= 32;
        return str;
    }
}
