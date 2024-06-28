#include "IPAddress.h"
#include <sstream>

IPAddress::IPAddress(const std::string& addr) : address(addr) {}

std::string IPAddress::getAddress() const {
    return address;
}

char IPAddress::determineNetworkClass() const {
    std::istringstream iss(address);
    int first_octet;
    char dot;

    iss >> first_octet >> dot;

    if (first_octet >= 1 && first_octet <= 126) {
        return 'A';
    }
    else if (first_octet >= 128 && first_octet <= 191) {
        return 'B';
    }
    else if (first_octet >= 192 && first_octet <= 223) {
        return 'C';
    }
    else if (first_octet >= 224 && first_octet <= 239) {
        return 'D';
    }
    else if (first_octet >= 240 && first_octet <= 255) {
        return 'E';
    }
    else {
        return 'U'; // Unknown class
    }
}
