#include <iostream>

// name space

namespace earth {
    const float gravity = 9.81;
    const float circumference = 10917;
}

namespace moon {
    const float gravity = 1.62;
    const float circumference = 1737;
}

int main() {

    // basics

    /*
    std::cout << "I like pizza!" << '\n';
    std::cout << "It's really good!" << std::endl;
    */

    // basic variables

    int smallNumber = 9000000000000000000;
    const double pi = 3.1415;
    float temperature = 37.8;
    double largeNumber = 9000000000000000000;
    char dollarSign = '$';
    bool power = true;
    std::string name = "Bro";

    /* 
    std::cout << smallNumber << '\n';
    std::cout << largeNumber << '\n';
    std::cout << hugeNumber << '\n';

    std::cout << "Hello " << name << '\n';
    std::cout << "You are " << temperature << " degrees Celsius!" << '\n';

    std::cout << "Gravity measured in m/s is " << earth::gravity << " on earth!" << '\n';
    std::cout << "Gravity measured in m/s is " << moon::gravity << " on the moon!" << '\n';
    */
   
    return 0;
}