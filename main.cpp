#include <iostream>
using namespace std;
#include <vector>
#include <cstdlib>
#include <time.h>

int main() {

    int row = 3;            // declaring variables
    int col = 3;
    int row1;
    int col1;
    int guessRow;
    int guessCol;
    int points = 0;
    int guesses = 1;
    vector <int>  vec(col, 0);
    vector <vector<int>> matrix(row,vec);

    srand (time(NULL));         // randomly generating battleship location

    row1 = rand() % 3;
    col1 = rand() % 3;
    matrix.at(row1).at(col1) = 1;

    cout << "Welcome to Battleship!" << endl;           // game instructions
    cout << "In order to win, you must guess the location on the 3 by 3 grid where a battleship is located" << endl;
    cout << "Guess by inputting a row number [0-2] and a column number [0-2] between on each turn (ex. 0 2)" << endl << endl;

   while (points < 1) {             // game loop

       cout << "Guess number " << guesses << endl;      // guessing
       cout << "What is your guess?" << endl;
       cin >> guessRow >> guessCol;

       if (matrix.at(guessRow).at(guessCol) == 1) {
           cout << "You guessed correctly!" << endl;
           matrix.at(guessRow).at(guessCol) = 3;
           points = points + 1;
       } else {
           cout << "Oh no! You guessed wrong!" << endl;
           matrix.at(guessRow).at(guessCol) = 2;
       }
       guesses = guesses + 1;

       // printing game board
       for (int i = 0; i < matrix.size(); i++) {
           for (int j = 0; j < matrix.size(); j++) {
               if (matrix.at(i).at(j) == 2) {
                   cout << "| 0 |";
               }
               else if (matrix.at(i).at(j) == 3) {
                   cout << "| X |";
               }
               else {
                   cout << "|   |";
               }
           }
           cout << endl;
       }
       cout << endl;
   }

   cout << "Congrats! You sunk my battleship!" << "(" << guesses << " guesses)"; // end game



    return 0;
}