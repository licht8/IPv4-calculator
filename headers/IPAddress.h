#ifndef IPADDRESS_H
#define IPADDRESS_H

#include <string>

class IPAddress {
private:
    std::string address;

public:
    IPAddress(const std::string& addr);
    std::string getAddress() const;
    char determineNetworkClass() const;
};

#endif // IPADDRESS_H
