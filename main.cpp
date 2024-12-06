#include <chrono>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <thread>
#include <time.h> /* time */
#include <utility>
#include <vector>

// clean screen - funtion
void cleanScreen() {
    for (int i = 0; i < 100; i++) {
        std::cout << "\n";
    }
}

// cross-platform sleep using https://en.cppreference.com/w/cpp/thread/sleep_for
void sleep(unsigned long long ms) {
    std::this_thread::sleep_for(std::chrono::milliseconds(ms));
}

const int N = 2;
// const int N = 2; // use size 2 only for test

void printMatrix(int[N][N]);

void fillMatrixWithRandomPairs(int[N][N], int);

// tests if player won or not
void testSoloWin(int l, int o);

class Player {
  public:
    std::string name;
    int score;

    Player(std::string playerName) : name(std::move(playerName)), score(0) {}

    void incrementScore() { score++; }
};

int gameMemoSendBox() {
    int matrix0[N][N];
    int listNumPair[N][N];

    //    TODO: initialize matrix
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            matrix0[i][j] = 0;
            listNumPair[i][j] = 0;
        }
    }

    // calculate total number of pairs
    const int totalPairs = N * N / 2;

    fillMatrixWithRandomPairs(listNumPair, totalPairs);

    std::string player1Name, player2Name;
    std::cout << "✖ Enter Player 1 Name: ";
    std::cin >> player1Name;
    std::cout << "━══━━══━──━══━──━══━──━══━──━══━\n";
    std::cout << "✖ Enter Player 2 Name: ";
    std::cin >> player2Name;
    cleanScreen();

    // message, so that the user knows that the numbers will be displayed
    std::cout << "━══━𖣯━═┫ Memorize the following numbers ┣═━𖣯━══━\n\n";
    sleep(3);
    cleanScreen();

    // initiate two counters: how many pairs each player opened
    int player1pairs = 0;
    int player2pairs = 0;

    // whose turn is it to make a move
    int move = 1; // 1 - player1, 2 - player2

    // start do while loop until number of open pairs less than to total number
    // of pairs
    do {
        printMatrix(listNumPair);
        std::cout << "\n━══━𖣯━═┫ Sleeping for 4s and clearing the screen... "
                     "┣═━𖣯━══━\n";

        sleep(4000);

        // call cleanScreen funtion
        cleanScreen();

        printMatrix(matrix0);

        int firstCellRow;
        int firstCellCol;
        int secondCellRow;
        int secondCellCol;
        int numPair;

        // TODO: print information who is moving right now
        // TODO: print information who many point current player has
        std::cout << "Player " << move
                  << ", enter the index of the row and column of the first "
                     "element (example: 0 1): ";
        std::cin >> firstCellRow >> firstCellCol;
        std::cout << "Player " << move
                  << ", enter the index of the row and column of the second "
                     "element (example: 0 1): ";
        std::cin >> secondCellRow >> secondCellCol;
        std::cout << "Player " << move << ", enter num pair: ";
        std::cin >> numPair;

        // TODO: figure out the better names for variables
        bool cond1 = listNumPair[firstCellRow][firstCellCol] == numPair &&
                     listNumPair[secondCellRow][secondCellCol] == numPair;

        bool cond2 =
            (firstCellCol != secondCellCol || firstCellRow != secondCellRow);

        bool cond3 = matrix0[firstCellRow][firstCellCol] == 0 &&
                     matrix0[secondCellRow][secondCellCol] == 0;

        if (cond1 && cond2 && cond3) {
            matrix0[firstCellRow][firstCellCol] = numPair;
            matrix0[secondCellRow][secondCellCol] = numPair;

            // increment number of open pairs

            int currentPoints;
            if (move == 1) {
                player1pairs++;
                currentPoints = player1pairs;
            } else {
                player2pairs++;
                currentPoints = player2pairs;
            }

            std::cout << "Player " << move << ", that is correct! Now you have "
                      << currentPoints << std::endl;
        } else {
            // if player made a mistake - it's other player move
            std::cout
                << "Player " << move
                << ", you made a wrong move. The turn goes to another player."
                << std::endl;

            if (move == 1) {
                move = 2;
            } else {
                move = 1;
            }
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                std::cout << matrix0[i][j] << " ";
            }
            std::cout << std::endl;
        }

        std::cout << std::endl;

    } while (player1pairs + player2pairs < totalPairs);
    // loop ends

    // if player1 opened more pairs than player2
    if (player1pairs > player2pairs) {
        // player1 won
        std::cout << "━══━𖣯━═┫ Player 1 is the winner! ┣═━𖣯━══━";
    }
    // else if player2 opened more pairs than player1
    else if (player2pairs > player1pairs) {
        // player2 won
        std::cout << "━══━𖣯━═┫ Player 2 is the winner! ┣═━𖣯━══━";
    }
    // else
    else {
        // it's a tie
        std::cout << "━══━𖣯━═┫ it's a tie! ┣═━𖣯━══━" << std::endl;
    }
    std::cout << std::endl;

    return 0;
}

// single player mode
int singlePlayerSendBox() {
    int matrix0[N][N];
    int listNumPair[N][N];

    //    TODO: initialize matrix
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            matrix0[i][j] = 0;
            listNumPair[i][j] = 0;
        }
    }

    // calculate total number of pairs
    const int totalPairs = N;

    fillMatrixWithRandomPairs(listNumPair, totalPairs);

    // initiate two counters: how many pairs each player opened
    int player1pairs = 0;

    // whose turn is it to make a move
    //    int move = 1; // 1 - player1, 2 - player2

    // start do while loop until number of open pairs less than to total number
    // of pairs
    do {

        printMatrix(listNumPair);
        std::cout << "Sleeping for 3s and clearing the screen...\n";

        // sleep for 5 s
        // works for macos and linux
        sleep(5000);

        // call cleanScreen funtion
        cleanScreen();

        printMatrix(matrix0);

        int firstCellRow;
        int firstCellCol;
        int secondCellRow;
        int secondCellCol;
        int numPair;

        // TODO: print information who is moving right now
        // TODO: print information who many point current player has
        std::cout << "Enter numbers example 0 1: ";
        std::cin >> firstCellRow >> firstCellCol;
        std::cout << "Enter numbers example 0 1: ";
        std::cin >> secondCellRow >> secondCellCol;
        std::cout << "Enter num pair: ";
        std::cin >> numPair;

        // TODO: figure out the better names for variables
        bool cond1 = listNumPair[firstCellRow][firstCellCol] == numPair &&
                     listNumPair[secondCellRow][secondCellCol] == numPair;

        bool cond2 =
            (firstCellCol != secondCellCol || firstCellRow != secondCellRow);

        bool cond3 = matrix0[firstCellRow][firstCellCol] == 0 &&
                     matrix0[secondCellRow][secondCellCol] == 0;

        if (cond1 && cond2 && cond3) {
            // TODO: print information that player made a correct move
            matrix0[firstCellRow][firstCellCol] = numPair;
            matrix0[secondCellRow][secondCellCol] = numPair;

            // increment number of open pairs
            // TODO: print information whose move is it now
            // Add points to player
            player1pairs++;
            std::cout << "Correct" << std::endl;
        } else {
            // if player made a mistake - it's other player move
            // TODO: print information that player made a wrong move
            std::cout << "Wrong " << std::endl;
            sleep(1000);
            cleanScreen();
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                std::cout << matrix0[i][j] << " ";
            }
            std::cout << std::endl;
        }

        std::cout << std::endl;

    } while (player1pairs < totalPairs);
    // loop ends

    // if player1 opened more pairs than player2
    testSoloWin(player1pairs, totalPairs);
    std::cout << std::endl;

    return 0;
}

void mainMenu(); // Prototype, so returnToMain recognize the mainMenu funcion
void returnToMain() {
    int returnKey;
    std::cout << "✖ ᴇɴᴛᴇʀ [𝟣] ᴛᴏ ʀᴇᴛᴜʀɴ ᴛᴏ ᴍᴀɪɴ ᴍᴇɴᴜ: ";
    std::cin >> returnKey;
    if (returnKey == 1) {
        cleanScreen();
        mainMenu();
    }
}

//----- mainMenu ------
void mainMenu() {
    int option;
    std::cout << "┏═━𖣯━══━𖣯━══━𖣯━═┫ Welcome  To  The  Memory  Game "
                 "┣═━𖣯━══━𖣯━══━𖣯━═┓\n\n";
    std::cout << "                    ✖ Start Game        [1]\n";
    std::cout << "                    ✖ How To Play       [2]\n";
    std::cout << "                    ✖ Credits           [3]\n\n";
    std::cout << "┗══━𖣯━══━𖣯━══━𖣯━══━𖣯━══━𖣯━══━𖣯━══━𖣯━══━𖣯━══━𖣯━══━𖣯━══━𖣯━══━𖣯━"
                 "══┛\n\n";
    std::cout << "✖ Enter Your Option: ";
    std::cin >> option;

    cleanScreen();

    // multiplayer or solo
    if (option == 1) {
        int optionTwo;
        std::cout << "┏═━𖣯━══━𖣯━══━𖣯━═┫ Game  Mode ┣═━𖣯━══━𖣯━══━𖣯━═┓\n\n";
        std::cout << "           ✖ Solo               [1]\n";
        std::cout << "           ✖ Multiplayer        [2]\n\n";
        std::cout << "           ✖ go to Main Menu    [3]\n\n";
        std::cout << "┗══━𖣯━══━𖣯━══━𖣯━══━𖣯━══━𖣯━══━𖣯━══━𖣯━══━𖣯━══━┛\n\n";
        std::cout << "✖ Enter Your Option: ";
        std::cin >> optionTwo;
        if (optionTwo == 1) {
            cleanScreen();
            singlePlayerSendBox();
        } else if (optionTwo == 2) {
            cleanScreen();
            gameMemoSendBox();
        } else if (optionTwo == 3) {
            cleanScreen();
            mainMenu();
        } else {
            std::cout << "━══━𖣯━═┫ Invalid Option Entered ┣═━𖣯━══━\n";
            returnToMain();
        }
    } else if (option == 2) {
        std::cout
            << "┏═━𖣯━══━𖣯━══━𖣯━══━𖣯━══━𖣯━═┫ How To Play┣═━𖣯━══━𖣯━══━𖣯━══━\n\n";
        std::cout << "Welcome to this exciting and fun memory pair game! It’s "
                     "designed to help you improve your memory and focus. Here "
                     "are the steps to play:\n\n";
        std::cout << "1. Setup the game: The game has pairs of numbers placed "
                     "face down on a grid. Each number appears twice on the "
                     "grid, creating a pair.\n";
        std::cout << "2. Memorization: You will get a few seconds (e.g., 3 "
                     "seconds) to look at the grid and memorize where the "
                     "numbers are located.\n";
        std::cout << "3. Flip back: After the short time, the numbers are "
                     "flipped back over, hiding them.\n";
        std::cout << "4. Take turns: Players take turns choosing two spots on "
                     "the grid to flip over. If the numbers on both spots "
                     "match, the player scores a point and keeps the pair "
                     "flipped. If they don’t match, the numbers are flipped "
                     "back over, and the next player takes their turn.\n";
        std::cout << "5. Winning the game: The game continues until all pairs "
                     "are found. The player with the most points at the end of "
                     "the game wins.\n\n";
        std::cout << "┗═━𖣯━══━𖣯━══━𖣯━══━𖣯━══━𖣯━══━𖣯━═━𖣯━══━𖣯━══━𖣯━══━𖣯━══━𖣯━══━"
                     "𖣯━═━𖣯━══━𖣯━══━𖣯━══━𖣯━══━𖣯━══━𖣯━─\n\n";
        returnToMain();
    } else if (option == 3) {
        std::cout << "┏═━𖣯━═┫ Credits ┣═━𖣯━═┓\n";
        std::cout << "     ✖ Anastaassia\n";
        std::cout << "     ✖ Javon\n";
        std::cout << "     ✖ Erika\n";
        std::cout << "     ✖ Justin\n";
        std::cout << "     ✖ Alan\n";
        std::cout << "┗═━𖣯━══━𖣯━══━𖣯━══━𖣯━═┛\n\n";
        returnToMain();
    } else {
        std::cout << "━══━𖣯━═┫ Invalid Option Entered ┣═━𖣯━══━\n";
        returnToMain();
    }
}

int main(int argc, const char *argv[]) {

    //----- call mainMenu ------
    mainMenu();

    return 0;
}

void printMatrix(int matrix[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void fillMatrixWithRandomPairs(int listNumPair[N][N], int totalPairs) {
    // TODO
    int pair = 1;
    int c = 0;

    /* initialize random seed: */
    srand(time(NULL));

    do {
        int i = rand() % N;
        int j = rand() % N;

        if (listNumPair[i][j] == 0) {
            listNumPair[i][j] = pair;
            c++;

            if (c == 2) {
                c = 0;
                pair++;
            }
        }

    } while (pair <= totalPairs);
}

void testSoloWin(int player1pairs, int totalPairs) {
    if ((player1pairs / totalPairs) > 0.8) {
        std::cout << "You Win!\n"
                  << " Press Enter to Continue:";
    } else {
        std::cout << "You Lose, Try Again:";
    };
}
// TODO: think about other improvements
