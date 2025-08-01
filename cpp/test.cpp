#include <iostream>
#include <cmath>
#include <map>

// 0.4 namespace, to define variables and use repeated names

namespace earth {
    const float gravity = 9.81;
    const float circumference = 10917;
}

namespace moon {
    const float gravity = 1.62;
    const float circumference = 1737;
}

// 0.5 typedef and using, for alias of datatypes

typedef std::string text_t;
using text_t = std::string;

int main() {

    // 0.1 basics

    /*
    std::cout << "I like pizza!" << '\n';
    std::cout << "It's really good!" << std::endl;
    */

    // 0.2 basic variables

    int age;
    double smallNumber = -23;
    double hugeNumber = pow(smallNumber, 2);
    double positiveSmallNumber = abs(smallNumber); // and many other math operations
    const double pi = 3.1415;
    float temperature = 37.8;
    double largeNumber = 9000000000000000000;
    char dollarSign = '$';
    bool power = true;
    std::string name;
    text_t firstName = "Bro";

    /* 
    std::cout << largeNumber << '\n';
    std::cout << hugeNumber << '\n';

    std::cout << "Hello " << name << '\n';
    std::cout << "You are " << temperature << " degrees Celsius!" << '\n';

    # namespaces
    std::cout << "Gravity measured in m/s is " << earth::gravity << " on earth!" << '\n';
    std::cout << "Gravity measured in m/s is " << moon::gravity << " on the moon!" << '\n';
    
    # taking user input
    std::cout << "What is your age?\n";
    std::cin >> age;
    std::cout << "What is your name?\n";
    std::getline(std::cin >> std::ws, name); // use getline for strings with spaces, add ws for getline inputs after a prev input
    
    std::cout << "My name is " << name << " and I'm " << age << " years old!\n";
    */

    // 0.3 type casting and integer division
    int questions = 10;
    int correct = 8;

    double score = correct / (double) questions;  // type cast into double for division, note that only the 2nd number need to be changed
    // std::cout << score * 100 << "%\n";  // shortened, from using statement
    
    // 0.6 ifelse/switch case
    // Grades Generator

    /*
    double testScore;
    std::cout << "Input your score: ";
    std::cin >> testScore;

    if (testScore > 100 || testScore < 0) {     // if else works as usual
        std::cout << "Invalid Score!\n";
    } else if (testScore >= 70) {
        std::cout << "Grade: A\n";
    } else if (testScore >= 65) {
        std::cout << "Grade: B+\n";
    } else {
        std::cout << "Try harder next time!\n";
    }

    // 0.6.1 ternary operator for ifelse (condition ? expression 1 : expression 2)
    testScore > 100 ? std::cout << "Good job!" : std::cout << "Try harder next time!\n";
 
    // Months conversion
    int month;
    std::cout << "Input the numeral month: ";
    std::cin >> month;

    switch(month) {                  // switch only works with int, char, enum etc.
        case 1:                      // cannot use conditions, only constants allowed here
            std::cout << "January";  
            break;
        case 2:
            std::cout << "Feburary";
            break;
        default:
            std::cout << "Wrong Month!\n";
    }
    */

    // 0.7 string methods (incl in iostream)
    std::string yourName;
    std::cout << "What is your name, with no spaces?\n";
    std::getline(std::cin, yourName);

    if (yourName.empty() || yourName.find(" ") != std::string::npos) {    // string method for finding a char, returns npos if not found
        std::cout << "Invalid name!\n";
    }
    else {
        std::string yourEmail = yourName.insert(0, "2019").append("@gmail.com");
        std::cout << yourEmail << " is your email address!\n";
    }






    return 0;
}