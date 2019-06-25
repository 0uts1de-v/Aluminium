#ifndef ALUMINIUM_BASE64
#define ALUMINIUM_BASE64

#include <string>

namespace aluminium {
namespace base64 {

std::string encode(std::string plain) {
    const char table[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    std::string encoded = "";
    return encoded;
}

std::string encode_url(std::string plain) {
    const char table[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789-_";
    std::string encoded = "";
    return encoded;
}

}
}

#endif
