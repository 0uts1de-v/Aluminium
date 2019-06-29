#ifndef ALUMINIUM_BASE64
#define ALUMINIUM_BASE64

#include <bitset>
#include <string>

namespace aluminium {
namespace base64 {

std::string base64encode(std::string plain) {
    const char table[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    std::string bitstr, encoded;
    for (unsigned int i = 0; i < plain.size(); ++i) {
        bitstr += std::bitset<8>(plain[i]).to_string();
    }
    for (unsigned int i = 0; i < bitstr.size() % 6; ++i) {
        bitstr += "0";
    }
    for (unsigned int i = 0; i < bitstr.size(); i += 6) {
        encoded += table[stoi(bitstr.substr(i, 6), nullptr, 2)];
    }
    for (unsigned int i = 0; i < encoded.size() % 4; ++i) {
        encoded += "=";
    }
    return encoded;
}

std::string base64encode_url(std::string plain) {
    const char table[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789-_";
    std::string bitstr, encoded;
    for (unsigned int i = 0; i < plain.size(); ++i) {
        bitstr += std::bitset<8>(plain[i]).to_string();
    }
    for (unsigned int i = 0; i < bitstr.size() % 6; ++i) {
        bitstr += "0";
    }
    for (unsigned int i = 0; i < bitstr.size(); i += 6) {
        encoded += table[stoi(bitstr.substr(i, 6), nullptr, 2)];
    }
    return encoded;
}

}
}

#endif
