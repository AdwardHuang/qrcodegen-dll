// wrapper.cpp
#include "qrcodegen.hpp"
#include <cstring>

extern "C" {

// 提供给Python用的接口
const char* generate_qr(const char* text) {
    using namespace qrcodegen;
    static std::string result;

    QRCode qr = QRCode::encodeText(text, QRCode::Ecc::LOW);

    result.clear();
    for (int y = 0; y < qr.getSize(); y++) {
        for (int x = 0; x < qr.getSize(); x++) {
            result += (qr.getModule(x, y) ? '#' : ' ');
        }
        result += '\n';
    }

    return result.c_str();
}

}
