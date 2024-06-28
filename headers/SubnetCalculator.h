#ifndef SUBNETCALCULATOR_H
#define SUBNETCALCULATOR_H

#include <string>

class SubnetCalculator {
public:
    static std::string decimalToBinary(int decimal);
    static void printSubnetMask(unsigned int subnet_mask);
    static void printOctetsBinary(const std::string& binary_address);
    static std::string calculateNetworkAddressBinary(const std::string& ip_address, unsigned int subnet_mask);
    static std::string calculateBroadcastAddressBinary(const std::string& ip_address, unsigned int subnet_mask);
    static std::string calculateFirstAddressBinary(const std::string& network_address_binary, unsigned int subnet_mask);
    static std::string calculateLastAddressBinary(const std::string& broadcast_address_binary, unsigned int subnet_mask);
    static void calculateSubnetAndHostBits(unsigned int subnet_mask);
    static void calculateMaxHostsAndSubnets(unsigned int subnet_mask);
    static constexpr unsigned int pow2(int n);
};

#endif // SUBNETCALCULATOR_H
