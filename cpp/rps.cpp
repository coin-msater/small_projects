#include <iostream>
#include <map>
#include <vector>
#include <ctime>

std::map<char, char> gameRules = {
    {'R', 'P'},
    {'P', 'S'},
    {'S', 'R'}
};

class rpsGame {
    public:
        char machineChoice;
        char userChoice;
        int userWin;
        
    char getUserChoice() {
        std::cout << "********************************\n";
        std::cout << "Rock, Paper, Scissors Game Start\n";
        
        char userChoice;
        do {
            std::cout << "What will you play? (R, P or S)\n";
            std::cin >> userChoice;

            if (userChoice != 'S' && userChoice != 'R' && userChoice != 'P') {
                std::cout << "Invalid input: Input either R, P or S\n";
            }

        } while (userChoice != 'S' && userChoice != 'R' && userChoice != 'P');
        
        return userChoice;
    }

    char getMachineChoice() {
        std::vector<char> choices = {'R', 'P', 'S'};
        std::srand(std::time(nullptr));
        int randIndex = rand() % 3;
        return choices[randIndex];
    }

    int getResult(char machineChoice, char userChoice) {
        if (machineChoice == userChoice) {
            return 1;
        }
        else if (gameRules[machineChoice] == userChoice) {
            return 2;
        }
        else {
            return 3;
        }
    }
    

    void showResult(bool result, char machineChoice) {
        std::cout << "Opponent played " << machineChoice << "\n";
        if (userWin == 2) {
            std::cout << "You won!";
        }
        else if (userWin == 3) {
            std::cout << "You lost :(\n";
        }
        else {
            std::cout << "It's a draw :)\n";
        }
    }
};

int main() {
    rpsGame game;
    game.userChoice = game.getUserChoice();
    game.machineChoice = game.getMachineChoice();
    game.userWin = game.getResult(game.machineChoice, game.userChoice);
    game.showResult(game.userWin, game.machineChoice);
}
