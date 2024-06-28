#include <iostream>
#include <sstream>
#include <bitset>
#include "headers/IPAddress.h"
#include "headers/SubnetCalculator.h"

int main() {
    setlocale(0, "");

    std::string ip_address;
    std::cout << "Enter the IP address (in the format xxx.xxx.xxx.xxx): ";
    std::cin >> ip_address;

    std::istringstream iss(ip_address);
    int octet;
    char dot;

    unsigned int subnet_mask;
    std::cout << "Enter the subnet mask (1 to 32): ";
    std::cin >> subnet_mask;

    if (!(subnet_mask) || subnet_mask < 1 || subnet_mask > 32) {
        std::cerr << "Invalid subnet mask. Enter a number between 1 and 32." << std::endl;
        return 1;
    }

    IPAddress ip(ip_address);

    std::cout << "\nAddress: \t";
    for (int i = 0; i < 4; ++i) {
        iss >> octet >> dot;
        std::cout << SubnetCalculator::decimalToBinary(octet);
        if (i < 3) std::cout << ".";
    }
    std::cout << std::endl;

    SubnetCalculator::printSubnetMask(subnet_mask);

    std::string networkAddressBinary = SubnetCalculator::calculateNetworkAddressBinary(ip_address, subnet_mask);
    char network_class = ip.determineNetworkClass();

    std::cout << "Class: " << network_class << std::endl;

    std::cout << "\nNetwork: \t";
    SubnetCalculator::printOctetsBinary(networkAddressBinary);
    std::cout << "\t";

    for (int i = 0; i < 4; ++i) {
        std::bitset<8> octet_bits(networkAddressBinary.substr(i * 8, 8));
        std::cout << octet_bits.to_ulong();
        if (i < 3) std::cout << ".";
    }
    std::cout << std::endl;

    std::string broadcastAddressBinary = SubnetCalculator::calculateBroadcastAddressBinary(ip_address, subnet_mask);

    std::cout << "\nBroadcast: \t";
    SubnetCalculator::printOctetsBinary(broadcastAddressBinary);
    std::cout << "\t";

    for (int i = 0; i < 4; ++i) {
        std::bitset<8> octet_bits(broadcastAddressBinary.substr(i * 8, 8));
        std::cout << octet_bits.to_ulong();
        if (i < 3) std::cout << ".";
    }
    std::cout << std::endl;

    std::string firstAddressBinary = SubnetCalculator::calculateFirstAddressBinary(networkAddressBinary, subnet_mask);
    std::string lastAddressBinary = SubnetCalculator::calculateLastAddressBinary(broadcastAddressBinary, subnet_mask);

    std::cout << "\nHostMin: \t";
    SubnetCalculator::printOctetsBinary(firstAddressBinary);
    std::cout << "\t";

    for (int i = 0; i < 4; ++i) {
        std::bitset<8> octet_bits(firstAddressBinary.substr(i * 8, 8));
        std::cout << octet_bits.to_ulong();
        if (i < 3) std::cout << ".";
    }
    std::cout << std::endl;

    std::cout << "HostMax: \t";
    SubnetCalculator::printOctetsBinary(lastAddressBinary);
    std::cout << "\t";

    for (int i = 0; i < 4; ++i) {
        std::bitset<8> octet_bits(lastAddressBinary.substr(i * 8, 8));
        std::cout << octet_bits.to_ulong();
        if (i < 3) std::cout << ".";
    }
    std::cout << std::endl;

    SubnetCalculator::calculateSubnetAndHostBits(subnet_mask);
    SubnetCalculator::calculateMaxHostsAndSubnets(subnet_mask);

    std::cout << "\nPress any key...";
    while (std::cin.get() != ' ');

    return 0;
}
