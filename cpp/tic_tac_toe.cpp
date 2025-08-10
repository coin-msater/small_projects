#include <iostream>
#include <ctime>
#include <vector>

class Game {
    protected:
    std::vector<int> sampleBoard[3];
    std::vector<char> gameBoard[3];

    public:
        Game() {
            sampleBoard[0] = {11, 12, 13};
            sampleBoard[1] = {21, 22, 23};
            sampleBoard[2] = {31, 32, 33};

            gameBoard[0] = {' ', ' ', ' '};
            gameBoard[1] = {' ', ' ', ' '};
            gameBoard[2] = {' ', ' ', ' '};
        }
        void showBoard() {
            std::cout << "********************************\n";
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    std::cout << " " << gameBoard[i][j] << " ";

                    if (j == 2) {
                        std::cout << "\n";
                    }
                    else {
                        std::cout << "|";
                    }
                }
                if (i == 2) {
                    std::cout << "\n";
                }
                else {
                    std::cout << "-----------\n";
                }
            }
            std::cout << "********************************\n"; 
        }

        void showSampleBoard() {
            std::cout << "********************************\n";
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    std::cout << " " << sampleBoard[i][j] << " ";

                    if (j == 2) {
                        std::cout << "\n";
                    }
                    else {
                        std::cout << "|";
                    }
                }
                if (i == 2) {
                    std::cout << "\n";
                }
                else {
                    std::cout << "-------------\n";
                }
            }
            std::cout << "********************************\n"; 
        }

        int checkRows() {
            for (int i = 0; i < 3; i++) {
                char temp = gameBoard[i][0];
                if (temp == ' ') {
                    continue;
                }

                bool win = true;
                for (int j = 1; j < 3; j++) {
                    if (gameBoard[i][j] != temp) {
                        win = false;
                        break;
                    }
                }

                if (win) {
                    return (temp == 'X') ? 1 : 2; 
                }
            }
            return 0;
        }

        int checkCols() {
            for (int i = 0; i < 3; i++) {
                char temp = gameBoard[0][i];
                if (temp == ' ') {
                    continue;
                }

                bool win = true;
                for (int j = 1; j < 3; j++) {
                    if (gameBoard[j][i] != temp) {
                        win = false;
                        break;
                    }
                }

                if (win) {
                    return (temp == 'X') ? 1 : 2; 
                }
            }
            return 0;
        }

        int checkDiags() {
            if (gameBoard[1][1] == ' ') {
                return 0;
            }
            else if (
                (gameBoard[0][0] == gameBoard[2][2] && gameBoard[0][0] != ' ') || 
                (gameBoard[2][0] == gameBoard[0][2] && gameBoard[0][2] != ' ')
            )
                {
                    return (gameBoard[1][1] == 'X') ? 1 : 2;
                }
        }

        int checkDraw() {
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    if (gameBoard[i][j] == ' ') {
                        return -5;
                    }
                }
            }
            return 0;
        }

        void playX() {
            int pos;
            std::cout << "What will you play? Input the index of the empty space.\n";
            std::cin >> pos;

            int x = pos / 10 - 1;
            int y = pos % 10 - 1;
            
            while (x > 2 || x < 0 || y > 2 || y < 0 || gameBoard[x][y] != ' ') {
                std::cout << "Invalid input, try again.\n";
                std::cin >> pos;

                x = pos / 10 - 1;
                y = pos % 10 - 1;
            }

            gameBoard[x][y] = 'X';
        }

        void playO() {
            // find available spaces
            std::vector<int> spaces;
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    if (gameBoard[i][j] == ' ') {
                        spaces.push_back(sampleBoard[i][j]);
                    }
                }
            }

            // randomize the space to use
            std::srand(std::time(nullptr));
            int randIndex = rand() % spaces.size();
            int pos = spaces[randIndex];

            // convert to coords
            int x = pos / 10 - 1;
            int y = pos % 10 - 1;

            gameBoard[x][y] = 'O';
        }
        
};

int main() {
    Game ttt;
    int round = 0;
    int status = 0;

    ttt.showSampleBoard();
    while (!status) {
        switch(round % 2) {
            case 0: ttt.playX(); break;
            case 1: ttt.playO(); break;
        }
        ttt.showBoard();
        status = ttt.checkCols() + ttt.checkDiags() + ttt.checkRows() + ttt.checkDraw();
    }
    
    switch(status) {
        case 1: std::cout << "You win!"; break;
        case -4: std::cout << "You win!"; break;
        case 2: std::cout << "You lost!"; break;
        case -3: std::cout << "You lost!"; break;
        case -5: std::cout << "It's a draw!"; break;
    }

    return 0;
};