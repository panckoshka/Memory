//
//  projectSandBox.hpp
//  cst117
//
//  Created by Anastasiia Slastina on 10/13/24.
//
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <unistd.h>
#include <utility>
#include <vector>

using namespace std;

int gameMemoSendBox() {
    const int N = 2;
    int maxtrix0[N][N] = {{0, 0}, {0, 0}};
    int listNumPair[N][N] = {{1, 2}, {2, 1}};

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << listNumPair[i][j] << " ";
        }
        cout << endl;
    }
    cout << "Sleeping for 3s and clearing the screen...\n";

    // sleep for 3 s
    // works for macos and linux
    sleep(5);

    // clear the screen
    for (int i = 0; i < 100; i++)
        cout << "\n";

    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            cout << maxtrix0[row][col] << " ";
        }
        cout << endl;
    }

    int firstCellRow;
    int firstCellCol;
    int secondCellRow;
    int secondCellCol;
    int numPair;

    cout << "Enter numbers example 0 1: ";
    cin >> firstCellRow >> firstCellCol;
    cout << "Enter numbers example 0 1: ";
    cin >> secondCellRow >> secondCellCol;
    cout << "Enter num pair: ";
    cin >> numPair;

    if (listNumPair[firstCellRow][firstCellCol] == numPair &&
        listNumPair[secondCellRow][secondCellCol] == numPair) {
        maxtrix0[firstCellRow][firstCellCol] = numPair;
        maxtrix0[secondCellRow][secondCellCol] = numPair;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << maxtrix0[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;

    return 0;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    gameMemoSendBox();
    return 0;
}
