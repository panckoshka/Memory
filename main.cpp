//
//  projectSandBox.hpp
//  cst117
//
//  Created by Anastasiia Slastina on 10/13/24.
//
// TODO: remove unsued headers
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <unistd.h>
#include <utility>
#include <vector>
#include <cstdlib>
#include <time.h>       /* time */


using namespace std;

//const int N = 4;
const int N = 2; // use size 2 only for test

void printMatrix(int[N][N]);

void fillMatrixWithRandomPairs(int[N][N], int);

// TODO: add Player class
// TODO: add player name

int gameMemoSendBox() {
    int matrix0[N][N];
    int listNumPair[N][N];
    
//    TODO: initialize matrix
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N;j++) {
            matrix0[i][j] = 0;
            listNumPair[i][j] = 0;
        }
    }
    
    // calculate total number of pairs
    const int totalPairs = N * N / 2;
    
    
    fillMatrixWithRandomPairs(listNumPair,totalPairs);
    
    // initiate two counters: how many pairs each player opened
    int player1pairs = 0;
    int player2pairs = 0;
    
    // whose turn is it to make a move
    int move = 1; // 1 - player1, 2 - player2
    
    // start do while loop until number of open pairs less than to total number of pairs
    do {
        
        printMatrix(listNumPair);
        cout << "Sleeping for 3s and clearing the screen...\n";
        
        // sleep for 3 s
        // works for macos and linux
        sleep(5);
        
        // clear the screen
        for (int i = 0; i < 100; i++)
            cout << "\n";
        
        printMatrix(matrix0);
        
        int firstCellRow;
        int firstCellCol;
        int secondCellRow;
        int secondCellCol;
        int numPair;
        
        // TODO: print information who is moving right now
        // TODO: print information who many point current player has
        cout << "Enter numbers example 0 1: ";
        cin >> firstCellRow >> firstCellCol;
        cout << "Enter numbers example 0 1: ";
        cin >> secondCellRow >> secondCellCol;
        cout << "Enter num pair: ";
        cin >> numPair;
        
        // TODO: figure out the better names for variables
        bool cond1 = listNumPair[firstCellRow][firstCellCol] == numPair &&
                     listNumPair[secondCellRow][secondCellCol] == numPair;
        
        bool cond2 = (firstCellCol != secondCellCol || firstCellRow != secondCellRow);
        
        bool cond3 = matrix0[firstCellRow][firstCellCol] == 0 &&
        matrix0[secondCellRow][secondCellCol] == 0;
        
        if (cond1 && cond2 && cond3) {
            // TODO: print information that player made a correct move
            matrix0[firstCellRow][firstCellCol] = numPair;
            matrix0[secondCellRow][secondCellCol] = numPair;
            
            // increment number of open pairs
            // TODO: print information whose move is it now
            if (move == 1) {
                player1pairs++;
            } else {
                player2pairs++;
            }
        } else {
            // if player made a mistake - it's other player move
            // TODO: print information that player made a wrong move
            if (move == 1) {
                move = 2;
            } else {
                move = 1;
            }
        }
        
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cout << matrix0[i][j] << " ";
            }
            cout << endl;
        }
        
        
        cout << endl;
        
    } while (player1pairs + player2pairs < totalPairs);
    // loop ends
    
    // if player1 opened more pairs than player2
    if (player1pairs > player2pairs) {
        // player1 won
        cout << "Player 1 is the winner!";
    }
    // else if player2 opened more pairs than player1
    else if (player2pairs > player1pairs) {
        // player2 won
        cout << "Player 2 is the winner!";
    }
    // else
    else {
        // it's a tie
        cout << "it's a tie!";
    }
    cout << endl;
    
    return 0;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    gameMemoSendBox();
    
    return 0;
}


void printMatrix(int matrix[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void fillMatrixWithRandomPairs(int listNumPair[N][N], int totalPairs) {
    // TODO
    int pair = 1;
    int c = 0;
    
    /* initialize random seed: */
    srand (time(NULL));
    
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
