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

// clean screen - funtion
void cleanScreen (){
    for (int i = 0; i < 100; i++){
        cout << "\n";
    }
}

const int N = 4;
//const int N = 2; // use size 2 only for test

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
        
        //call cleanScreen funtion
        cleanScreen();
    
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

void mainMenu();  //Prototype, so returnToMain recognize the mainMenu funcion
void returnToMain (){
    int returnKey;
    std::cout << "✖ ᴇɴᴛᴇʀ [𝟣] ᴛᴏ ʀᴇᴛᴜʀɴ ᴛᴏ ᴍᴀɪɴ ᴍᴇɴᴜ: ";
    std::cin >> returnKey;
    if (returnKey == 1) {
        cleanScreen();
        mainMenu();
    }
}

//----- mainMenu ------
void mainMenu(){
    int option;
    std::cout << "┏═━𖣯━══━𖣯━══━𖣯━═┫ Wᴇʟᴄᴏᴍᴇ Tᴏ Tʜᴇ Mᴇᴍᴏʀʏ Gᴀᴍᴇ ┣═━𖣯━══━𖣯━══━𖣯━═┓\n\n";
    std::cout << "                  ✖ sᴛᴀʀᴛ ɢᴀᴍᴇ        [𝟭]\n";
    std::cout << "                  ✖ ʜᴏᴡ ᴛᴏ ᴘʟᴀʏ       [𝟮]\n";
    std::cout << "                  ✖ ᴄʀᴇᴅɪᴛs           [𝟯]\n\n";
    std::cout << "┗═━𖣯━═━𖣯━══━𖣯━══━𖣯━══━𖣯━══━𖣯━══━𖣯━══━𖣯━══━𖣯━══━𖣯━══━𖣯━═━𖣯━═┛\n\n";
    std::cout << "✖ ᴇɴᴛᴇʀ ʏᴏᴜʀ ᴏᴘᴛɪᴏɴ: ";
    std::cin >> option;
    
    cleanScreen();
    
    if(option == 1){
        gameMemoSendBox();
    }
    else if (option == 2){
    std::cout << "┏═━𖣯━══━𖣯━══━𖣯━══━𖣯━══━𖣯━═┫ How To Play ┣═━𖣯━══━𖣯━══━𖣯━══━\n\n";
    std::cout << "ᴡᴇʟᴄᴏᴍᴇ ᴛᴏ ᴛʜɪꜱ ᴇxᴄɪᴛɪɴɢ ᴀɴᴅ ꜰᴜɴ ᴍᴇᴍᴏʀʏ ᴘᴀɪʀ ɢᴀᴍᴇ! ɪᴛ’ꜱ ᴅᴇꜱɪɢɴᴇᴅ ᴛᴏ ʜᴇʟᴘ ʏᴏᴜ ɪᴍᴘʀᴏᴠᴇ ʏᴏᴜʀ ᴍᴇᴍᴏʀʏ ᴀɴᴅ ꜰᴏᴄᴜꜱ. ʜᴇʀᴇ ᴀʀᴇ ᴛʜᴇ ꜱᴛᴇᴘꜱ ᴛᴏ ᴘʟᴀʏ:\n\n";
    std::cout << "𝟣. ꜱᴇᴛᴜᴘ ᴛʜᴇ ɢᴀᴍᴇ: ᴛʜᴇ ɢᴀᴍᴇ ʜᴀꜱ ᴘᴀɪʀꜱ ᴏꜰ ɴᴜᴍʙᴇʀꜱ ᴘʟᴀᴄᴇᴅ ꜰᴀᴄᴇ ᴅᴏᴡɴ ᴏɴ ᴀ ɢʀɪᴅ. ᴇᴀᴄʜ ɴᴜᴍʙᴇʀ ᴀᴘᴘᴇᴀʀꜱ ᴛᴡɪᴄᴇ ᴏɴ ᴛʜᴇ ɢʀɪᴅ, ᴄʀᴇᴀᴛɪɴɢ ᴀ ᴘᴀɪʀ.\n";
    std::cout << "𝟤. ᴍᴇᴍᴏʀɪᴢᴀᴛɪᴏɴ: ʏᴏᴜ ᴡɪʟʟ ɢᴇᴛ ᴀ ꜰᴇᴡ ꜱᴇᴄᴏɴᴅꜱ (ᴇ.ɢ., 𝟥 ꜱᴇᴄᴏɴᴅꜱ) ᴛᴏ ʟᴏᴏᴋ ᴀᴛ ᴛʜᴇ ɢʀɪᴅ ᴀɴᴅ ᴍᴇᴍᴏʀɪᴢᴇ ᴡʜᴇʀᴇ ᴛʜᴇ ɴᴜᴍʙᴇʀꜱ ᴀʀᴇ ʟᴏᴄᴀᴛᴇᴅ.\n";
    std::cout << "𝟥. ꜰʟɪᴘ ʙᴀᴄᴋ: ᴀꜰᴛᴇʀ ᴛʜᴇ ꜱʜᴏʀᴛ ᴛɪᴍᴇ, ᴛʜᴇ ɴᴜᴍʙᴇʀꜱ ᴀʀᴇ ꜰʟɪᴘᴘᴇᴅ ʙᴀᴄᴋ ᴏᴠᴇʀ, ʜɪᴅɪɴɢ ᴛʜᴇᴍ.\n";
    std::cout << "𝟦. ᴛᴀᴋᴇ ᴛᴜʀɴꜱ: ᴘʟᴀʏᴇʀꜱ ᴛᴀᴋᴇ ᴛᴜʀɴꜱ ᴄʜᴏᴏꜱɪɴɢ ᴛᴡᴏ ꜱᴘᴏᴛꜱ ᴏɴ ᴛʜᴇ ɢʀɪᴅ ᴛᴏ ꜰʟɪᴘ ᴏᴠᴇʀ. ɪꜰ ᴛʜᴇ ɴᴜᴍʙᴇʀꜱ ᴏɴ ʙᴏᴛʜ ꜱᴘᴏᴛꜱ ᴍᴀᴛᴄʜ, ᴛʜᴇ ᴘʟᴀʏᴇʀ ꜱᴄᴏʀᴇꜱ ᴀ ᴘᴏɪɴᴛ ᴀɴᴅ ᴋᴇᴇᴘꜱ ᴛʜᴇ ᴘᴀɪʀ ꜰʟɪᴘᴘᴇᴅ.  ɪꜰ ᴛʜᴇʏ ᴅᴏɴ’ᴛ ᴍᴀᴛᴄʜ, ᴛʜᴇ ɴᴜᴍʙᴇʀꜱ ᴀʀᴇ ꜰʟɪᴘᴘᴇᴅ ʙᴀᴄᴋ ᴏᴠᴇʀ, ᴀɴᴅ ᴛʜᴇ ɴᴇxᴛ ᴘʟᴀʏᴇʀ ᴛᴀᴋᴇꜱ ᴛʜᴇɪʀ ᴛᴜʀɴ.\n";
    std::cout << "𝟧. ᴡɪɴɴɪɴɢ ᴛʜᴇ ɢᴀᴍᴇ: ᴛʜᴇ ɢᴀᴍᴇ ᴄᴏɴᴛɪɴᴜᴇꜱ ᴜɴᴛɪʟ ᴀʟʟ ᴘᴀɪʀꜱ ᴀʀᴇ ꜰᴏᴜɴᴅ.  ᴛʜᴇ ᴘʟᴀʏᴇʀ ᴡɪᴛʜ ᴛʜᴇ ᴍᴏꜱᴛ ᴘᴏɪɴᴛꜱ ᴀᴛ ᴛʜᴇ ᴇɴᴅ ᴏꜰ ᴛʜᴇ ɢᴀᴍᴇ ᴡɪɴꜱ.\n\n";
    std::cout << "┗═━𖣯━══━𖣯━══━𖣯━══━𖣯━══━𖣯━══━𖣯━═━𖣯━══━𖣯━══━𖣯━══━𖣯━══━𖣯━══━𖣯━═━𖣯━══━𖣯━══━𖣯━══━𖣯━══━𖣯━══━𖣯━─\n\n";
        returnToMain();
    }
    else if (option == 3){
    std::cout << "┏═━𖣯━═┫ ᴄʀᴇᴅɪᴛꜱ ┣═━𖣯━═┓\n";
    std::cout << "     ✖ ᴀɴᴀꜱᴛᴀꜱɪɪᴀ\n";
    std::cout << "     ✖ ᴊᴀᴠᴏɴ\n";
    std::cout << "     ✖ ᴇʀɪᴋᴀ\n";
    std::cout << "     ✖ ᴊᴜꜱᴛɪɴ\n";
    std::cout << "     ✖ ᴀʟᴀɴ\n";
    std::cout << "┗═━𖣯━══━𖣯━══━𖣯━══━𖣯━═┛\n\n";
        returnToMain();
    }
}

int main(int argc, const char * argv[]) {
    
    //----- call mainMenu ------
    mainMenu();
    
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

// TODO: think about other improvements
