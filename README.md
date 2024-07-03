# System Specifications

This program is designed to handle various operations and calculations related to IP addresses and subnet masks. It includes classes and functions to determine the network class of an IP address, convert decimal numbers to binary, calculate network and broadcast addresses, and provide information about the subnet and host bits.

## Features

* IP Address Validation:
Ensures the user inputs a valid IP address in the format xxx.xxx.xxx.xxx.

* Subnet Mask Validation:
Accepts a subnet mask value between 1 and 32, ensuring it is within the valid range for IPv4 addresses.

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
Computes and displays the first and last host addresses within the subnet in both binary and decimal formats.

* Subnet and Host Bits Calculation:
Calculates and displays the number of bits used for subnetting and the number of bits available for host addresses.

* Maximum Hosts and Subnets Calculation:
Computes and displays the maximum number of hosts per subnet and the total number of subnets that can be created with the given subnet mask.

* User-Friendly Output:
Formats the output neatly, making it easy to read and understand the calculated results.
Uses clear and descriptive labels for each piece of information presented.

* Error Handling:
Provides informative error messages for invalid inputs, such as an out-of-range subnet mask.

* Interactive Command Line Interface:
Engages the user with prompts to input the necessary data and waits for user interaction before terminating, making it suitable for learning and practical use.

* Modular Design:
Separates the functionality into classes (IPAddress and SubnetCalculator), making the code more organized and easier to maintain or extend.

* Educational Tool:
  Offers a practical way for users to learn about IP addresses, subnetting, and network classes through hands-on interaction and immediate feedback on their inputs.

* Compatibility:
  Designed to run in a standard C++ environment, ensuring broad compatibility and ease of use across different systems.



## Dependencies
[CMake (version 3.10 and above)](https://cmake.org/download/)

## Building the Project
```
git clone https://github.com/licht8/system-specifications.git
```
and then you have to open [**RUN.bat**]() file

## Running the Application
After successfully building the project, the executable file will start automatically, but if you want to open it again or have any problems:

* Start **RUN.bat**
* Find [**SystemSpecifications.exe**]() in **/build/Debug** for Debug and **/build/Release** for Release
