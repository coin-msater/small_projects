#include <iostream>
#include <cstdlib>
>

class Game {
    protected:
        std::string sampleBoard[3][3] = {
            {"11", "12", "13"},
            {"21", "22", "23"},
            {"31", "32", "33"}
        };
        
        char gameBoard[3][3] = {
            {' ', ' ', ' '},
            {' ', ' ', ' '},
            {' ', ' ', ' '}
        };
    
    public:
        Game();
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
                    std::cout << "-----------";
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

        int play(Player player, int pos) {
            int x = pos / 10 - 1;
            int y = pos % 10 - 1;

            if (gameBoard[x][y] != ' ') {
                std::cout << "Already occupied!";
                return -1;
            }
            
            gameBoard[x][y] = player.getSymbol();
            return 0;
        }
};

class Player {
    protected:
        char symbol;
    
    public:
        Player(char symbol);
        
        char getSymbol() {
            return symbol;
        }

        int playX() {
            int pos;
            std::cout << "What will be your next move? Input the coordinate of the empty box.\n";
            std::cin >> pos;
            return pos;
        }

        int playO( {

        })
};