#include "SubnetCalculator.h"
#include <iostream>
#include <bitset>
#include <sstream>
#include <cmath>

std::string SubnetCalculator::decimalToBinary(int decimal) {
    return std::bitset<8>(decimal).to_string();
}

void SubnetCalculator::printSubnetMask(unsigned int subnet_mask) {
    std::cout << "Netmask: \t";

    int ones = subnet_mask;
    for (int i = 0; i < 4; ++i) {
        if (ones >= 8) {
            std::cout << decimalToBinary(255);
            ones -= 8;
        }
        else {
            std::cout << decimalToBinary(255 - (255 >> ones));
            ones = 0;
        }

        if (i < 3) std::cout << ".";
    }

    std::cout << std::endl;
}

void SubnetCalculator::printOctetsBinary(const std::string& binary_address) {
    std::bitset<32> bits(binary_address);
    for (size_t i = 0; i < 32; ++i) {
        std::cout << bits[31 - i];
        if ((i + 1) % 8 == 0 && i + 1 < 32) {
            std::cout << ".";
        }
    }
}

std::string SubnetCalculator::calculateNetworkAddressBinary(const std::string& ip_address, unsigned int subnet_mask) {
    std::istringstream iss(ip_address);
    int octet;
    char dot;

    std::bitset<32> network_address_bits;

    for (int i = 0; i < 4; ++i) {
        iss >> octet >> dot;
        std::bitset<32> ip_octet_bits(octet);
        network_address_bits = (network_address_bits << 8) | ip_octet_bits;
    }

    if (subnet_mask != 32) {
        std::bitset<32> subnet_mask_bits(0xFFFFFFFF);
        subnet_mask_bits <<= (32 - subnet_mask);
        network_address_bits &= subnet_mask_bits;
    }

    return network_address_bits.to_string();
}

std::string SubnetCalculator::calculateBroadcastAddressBinary(const std::string& ip_address, unsigned int subnet_mask) {
    std::bitset<32> ip_address_bits;
    std::bitset<32> subnet_mask_bits(0xFFFFFFFF);

    std::istringstream iss(ip_address);
    int octet;
    char dot;
    for (int i = 0; i < 4; ++i) {
        iss >> octet >> dot;
        std::bitset<32> octet_bits(octet);
        ip_address_bits = (ip_address_bits << 8) | octet_bits;
    }

    if (subnet_mask != 32) {
        subnet_mask_bits <<= (32 - subnet_mask);
        ip_address_bits |= ~subnet_mask_bits;
    }

    return ip_address_bits.to_string();
}

std::string SubnetCalculator::calculateFirstAddressBinary(const std::string& network_address_binary, unsigned int subnet_mask) {
    if (subnet_mask == 32) {
        return network_address_binary;
    }

    std::bitset<32> network_address_bits(network_address_binary);
    network_address_bits = network_address_bits.to_ulong() + 1;

    return network_address_bits.to_string();
}

std::string SubnetCalculator::calculateLastAddressBinary(const std::string& broadcast_address_binary, unsigned int subnet_mask) {
    if (subnet_mask == 32) {
        return broadcast_address_binary;
    }

    std::bitset<32> broadcast_address_bits(broadcast_address_binary);
    broadcast_address_bits = broadcast_address_bits.to_ulong() - 1;

    return broadcast_address_bits.to_string();
}

void SubnetCalculator::calculateSubnetAndHostBits(unsigned int subnet_mask) {
    int host_bits = 32 - subnet_mask;
    int subnet_bits = subnet_mask;

    std::cout << "\nBits / subnet: \t" << subnet_bits << std::endl;
    std::cout << "Bits / host: \t" << host_bits << std::endl;
}

void SubnetCalculator::calculateMaxHostsAndSubnets(unsigned int subnet_mask) {
    int host_bits = 32 - subnet_mask;
    int subnet_bits = subnet_mask;

    unsigned int max_hosts = pow2(host_bits) - 2;
    unsigned int max_subnets = pow2(subnet_bits);

    std::cout << "\nMax hosts: \t" << max_hosts << std::endl;
    std::cout << "Max subnets: \t" << max_subnets << std::endl;
}

constexpr unsigned int SubnetCalculator::pow2(int n) {
    return (n == 0) ? 1 : 2 * pow2(n - 1);
}