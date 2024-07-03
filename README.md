# System Specifications

This program is designed to handle various operations and calculations related to IP addresses and subnet masks. It includes classes and functions to determine the network class of an IP address, convert decimal numbers to binary, calculate network and broadcast addresses, and provide information about the subnet and host bits.

## Features
* Network Class Determination:
Determines and displays the class (A, B, C, D, E, or U for unknown) of the provided IP address based on the first octet.

* Binary Conversion:
Converts each octet of the IP address to an 8-bit binary representation.
Converts the subnet mask to its binary equivalent.

* Subnet Mask Display:
Displays the subnet mask in binary format, separated into octets.

* Network Address Calculation:
Calculates the network address in both binary and decimal formats based on the given IP address and subnet mask.

* Broadcast Address Calculation:
Calculates the broadcast address in both binary and decimal formats for the specified IP address and subnet mask.

* First and Last Host Address Calculation:
Calculates and displays the first and last host addresses within the subnet in both binary and decimal formats.

* Subnet and Host Bits Calculation:
Calculates and displays the number of bits used for subnetting and the number of bits available for host addresses.

* Maximum Hosts and Subnets Calculation:
Calculates and displays the maximum number of hosts per subnet and the total number of subnets that can be created with the given subnet mask.

* User-Friendly Output:
Formats the output neatly, making it easy to read and understand the calculated results.
Uses clear and descriptive labels for each piece of information presented.

* Educational Tool:
  Offers a practical way for users to learn about IP addresses, subnetting, and network classes through hands-on interaction and immediate feedback on their inputs.

## Dependencies
[CMake (version 3.10 and above)](https://cmake.org/download/)

## Building the Project
```
git clone https://github.com/licht8/IPv4-calculator.git
```
and then you have to open [**RUN.bat**]() file

**If you want to build the program manually follow these commands:**
* Make and open "build" directory as well:
```mkdir build && cd build```
* Start building using CMake:
```cmake .. && cmake --build .```

## Running the Application
After successfully building the project, the executable file will start automatically, but if you want to open it again or have any problems:

* Start **RUN.bat**
* Find [**IPv4-Calculator.exe**]() in **/build/Debug** for Debug and **/build/Release** for Release

![Image alt](https://github.com/licht8/system-specifications/blob/main/images/photo_2024-02-23_21-38-15.jpg)
