#include <iostream>
#include <cmath>
#include <map>
#include <ctime>

void swap(std::string &x, std::string &y) {
    std::string temp;
    temp = x;
    x = y;
    y = temp;
}

int findIndex(std::string array[], int size, std::string target) {
        for (int i = 0; i < size; i++) {
            if (array[i] == target) {
                return i;
            }
        }
        return -1;
    }

int bubbleSort(int array[], int size) {
    int temp;
    int status = 0;
    for (int i = 0; i < size - 1; i++) {
        if (array[i] > array[i + 1]) {
            temp = array[i];
            array[i] = array[i + 1];
            array[i + 1] = temp;
            status = 1;
        }
    }
    return status;
}

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

    /* std::string yourName;
    std::cout << "What is your name, with no spaces?\n";
    std::getline(std::cin, yourName);

    if (yourName.empty() || yourName.find(" ") != std::string::npos) {    // string method for finding a char, returns npos if not found
        std::cout << "Invalid name!\n";
    }
    else {
        std::string yourEmail = yourName.insert(0, "2019").append("@gmail.com");
        std::cout << yourEmail << " is your email address!\n";
    }
    */

    // 0.8 loops
    // 0.8.1 do-while loops

    /*
    int num;
    int guess;
    int tries = 0;

    srand(time(NULL));
    num = (rand() % 100) + 1;
    std::cout << "**************************************\n";

    do {
        std::cout << "Enter your guess: ";
        std::cin >> guess;
        tries++;

        if (guess > num) {
            std::cout << "Too big, try again!\n";
        }
        else if (guess < num) {
            std::cout << "Too small, try again!\n";
        }
        else {
            std::cout << "Bingo!\n";
        }
    } while (guess != num);

    std::cout << "Number of tries: " << tries << "\n";
    std::cout << "**************************************\n";

    // 0.9 arrays and looping through the array
    std::string weapons[] = {"Tanks", "Planes", "Guns"};

    for (int i = 0; i < sizeof(weapons)/sizeof(std::string); i++) {
        std::cout << weapons[i] << "\n";
    }

    for (std::string weapon : weapons) {
        std::cout << weapon << "\n";
    }

    ## when arrays are passed to functions, what gets passed is only a pointer to the array
    ## as such the function have no info regarding the array itself, pass size as a seperate argument.
    
    # 0.9.1 searching for an element of an array, linear search

    int size = sizeof(weapons) / sizeof(std::string);

    int idx = findIndex(weapons, size, "Guns");
    std::cout << idx;

    # 0.9.1 searching for an element of an array, linear search

    int array[] = {1,2,3,4,6,7,5,8,0,9};
    int size = sizeof(array) / sizeof(int);
    int status = 0;
    int cycles = 0;

    do {
        status = bubbleSort(array, size);
        cycles++;
    } while (status);

    for (int i : array) {
        std::cout << i << ' ';
    }
    std::cout << '\n' << "Ths operations took " << cycles << " cycles, for an array of " << size << " integers."; 

    # 0.10 multidimensional arrays

    std::string cars[][3] = {
        {"car1", "car2", "car3"},
        {"car4", "car5", "car6"},
        {"car7", "car8", "car9"}
    };

    for (int i = 0; i < sizeof(cars)/sizeof(cars[0]); i++) {
        for (int j = 0; j < sizeof(cars[0])/sizeof(std::string); j++) {
            std::cout << cars[i][j] << " ";
        }
        std::cout << "\n";
    }

    // 1.0 address, pointers
    std::cout << &name << "\n";
    std::cout << &age << "\n";

    // passing address vs passing value into function
    // inputs to functions are copies of the original values,
    // as such, in order to switch the values in place, we pass in the addresses by adding & in function args
    // doing so will switch the addresses, which then swaps the values.
    std::string new_x = "X";
    std::string new_y = "Y";
    swap(new_x, new_y);

    std::cout << new_x << " and " << new_y;
    */

   return 0;
}