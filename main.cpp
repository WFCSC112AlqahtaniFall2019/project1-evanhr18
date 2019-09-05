#include <iostream>
using namespace std;
#include <vector>
#include <cstdlib>
#include <time.h>

int main() {

    int row = 3;
    int col = 3;
    int row1;
    int row2;
    int col1;
    int col2;
    int guessRow;
    int guessCol;
    int points = 0;
    vector <int>  vec(col, 0);
    vector <vector<int>> matrix(row,vec);

    srand (time(NULL));         // randomly generating two battleship locations

    row1 = rand() % 3;
    col1 = rand() % 3;
    row2 = rand() % 3;
    col2 = rand() % 3;
    matrix.at(row1).at(col1) = 1;
    matrix.at(row2).at(col2) = 1;

    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix.at(i).size(); j++) {
            cout << "Matrix["<<i<<"]["<<j<<"]=" << matrix.at(i).at(j) <<endl;
        }
    }

    cout << endl << "Welcome to Battleship!" << endl;           // game instructions
    cout << "In order to win, you must guess the two locations on the 3 by 3 grid where a battleship is located" << endl;
    cout << "Guess by inputting a row number and a column number on each turn (ex. 1 2)" << endl << endl;

    // printing game board
    cout << "___|___|___" << endl;
    cout << "___|___|___" << endl;
    cout << "___|___|___" << endl << endl;

    cout << "What is your guess?" << endl;          //guessing
    cin >> guessRow >> guessCol;

    if (matrix.at(guessRow).at(guessCol) == 1) {
        cout << "You guessed correctly!" << endl;
        points = points + 1;
    }
    else {
        cout << "Oh no! You guessed wrong!" << endl;
    }



    return 0;
}