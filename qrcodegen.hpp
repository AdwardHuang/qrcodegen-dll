// qrcodegen.hpp
#pragma once

#include <vector>
#include <string>

namespace qrcodegen {

class QRCode final {

public:
    enum class Ecc {
        LOW, MEDIUM, QUARTILE, HIGH
    };

private:
    int size;
    std::vector<std::uint8_t> modules;

public:
    QRCode();
    int getSize() const;
    bool getModule(int x, int y) const;
    static QRCode encodeText(const char *text, Ecc ecl);
};

}
