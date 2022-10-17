/*
Computing III -- COMP.2010 Honor Statement
The practice of good ethical behavior is essential for maintaining
good order in the classroom, providing an enriching learning
experience for students, and as training as a practicing computing
professional upon graduation. This practice is manifested in the
University’s Academic Integrity policy. Students are expected to
strictly avoid academic dishonesty and adhere to the Academic
Integrity policy as outlined in the course catalog. Violations will
be dealt with as outlined therein.
All programming assignments in this class are to be done by the
student alone. No outside help is permitted except the instructor and
approved tutors.
I certify that the work submitted with this assignment is mine and was
generated in a manner consistent with this document, the course
academic policy on the course website on Blackboard, and the UMass
Lowell academic code.
Date: 09/11/22
Name: Matthew Flores
*/
/***********************************************
Author: Matthew flores
Date: 09/11/22
Purpose: Play game with user to get random number
Sources of Help: None
Time Spent: 30-45 minutes
***********************************************/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void guessMin(int &);
void guessMax(int &, int &);
void numofGuesses(int &);

int main(int argc, char * argv[]) {
    int min = 0;
    int max = 0;
    int guess = 0;
    char decider = 'y';
    int randomNum = 0;
    int userGuess = 0;

    cout << "Welcome to the guesing game!" << endl;
    guessMin(min);
    guessMax(max, min);
    numofGuesses(guess);
    
    int tempGuess = guess;

    do { 
        srand((unsigned int)time(NULL));

        randomNum = rand() % max + 1;

        //cout << randomNum << endl;

        while (userGuess != randomNum) {
            cout << "I have a number between " << min << " and " << max << ". Can you guess the number in " << tempGuess << " tries?" << endl;
            cout << "Enter your first guess!: ";
            cin >> userGuess;

            if (userGuess > max || userGuess < min) {
                cout << "Please make sure you enter a number in the correct range!" << endl;
            }
            if (userGuess > randomNum) {
                cout << "Ah shucks! You were higher than the random number!" << endl << endl;
            } else if (userGuess < randomNum) {
                cout << "Ah shucks! You were lower than the random number!" << endl << endl;
            }

            tempGuess--;

            if (tempGuess == 0) {
                cout << "Ah shucks! You ran out of guesses!" << endl;
                break;
            }

        }
        if (userGuess == randomNum) {
            cout << endl << "Congrats! You got the number!" << endl;
        }

        cout << "Would you like to play again? (y,n): ";
        cin >> decider;
        if (decider == 'y') {
            tempGuess = guess;
        }
        
    } while (decider == 'y');
    
    return 0;
}

//this function gets the user response for the minimum number in the range
void guessMin(int &min) {
    do {
        cout << "Please enter the minimum #, (ensure it is a positive integer): ";
        cin >> min;
        cout << endl;
        if (min <= 0) {
            cout << "Please make sure you entered a positive integer!" << endl;
            min = 0;
        }
    } while (min <= 0);
}

//this function gets the user response for the maximum number in the range
void guessMax(int &max, int &min) {
    do {
        cout << "Please enter the maximum #, (ensure it is a positive integer and it is less than 1,000): ";
        cin >> max;
        cout << endl;
        if (max <= min || max >= 1000) {
            cout << "Please make sure you entered a positive integer!" << endl;
            max = 0;
        }
    } while (max <= 0);
}

//this function gets the user response for guesses in the range
void numofGuesses(int &guess) {
    do {
        cout << "Please enter the # of guesses you want, (ensure it is between 1 and 10): ";
        cin >> guess;
        cout << endl;
        if (guess < 1 || guess > 10) {
            cout << "Please make sure you entered a valid integer!" << endl;
            guess = 0;
        }
    } while (guess <= 0);
}