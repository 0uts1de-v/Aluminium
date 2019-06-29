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
        encoded += table[std::stoi(bitstr.substr(i, 6), nullptr, 2)];
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
        encoded += table[std::stoi(bitstr.substr(i, 6), nullptr, 2)];
    }
    return encoded;
}

std::string base64decode(std::string code) {
    auto table = [](int x){return (65 <= x && x <= 90) ? x - 65 : (97 <= x && x <= 122) ? x - 71 : (48 <= x && x <= 57) ? x + 4 : (x == 43) ? 62 : 63;};
    std::string bitstr, decoded;
    code.erase(std::remove_if(code.begin(), code.end(), [](char c){return c == '=';}), code.end());
    for (const auto& i : code) {
        bitstr += std::bitset<6>(table(i)).to_string();
    }
    bitstr.erase(bitstr.size() - 1 - bitstr.size() % 8, bitstr.size() % 8);
    for (unsigned int i = 0; i < bitstr.size(); i += 8) {
        decoded += char(std::stoi(bitstr.substr(i, 8), nullptr, 2));
    }
    return decoded;
}

std::string base64decode_url(std::string code) {
    auto table = [](int x){return (65 <= x && x <= 90) ? x - 65 : (97 <= x && x <= 122) ? x - 71 : (48 <= x && x <= 57) ? x + 4 : (x == 45) ? 62 : 63;};
    std::string bitstr, decoded;
    for (const auto& i : code) {
        bitstr += std::bitset<6>(table(i)).to_string();
    }
    bitstr.erase(bitstr.size() - 1 - bitstr.size() % 8, bitstr.size() % 8);
    for (unsigned int i = 0; i < bitstr.size(); i += 8) {
        decoded += char(std::stoi(bitstr.substr(i, 8), nullptr, 2));
    }
    return decoded;
}

}
}

#endif
