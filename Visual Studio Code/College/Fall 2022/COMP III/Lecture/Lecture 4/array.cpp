#include <iostream>
#include <cstdlib>
#include <ctime>

const int MAX_NUM_DIE = 2;
const int MIN_NUM_DIE = 5;
const int MAX_DIE_VALUE = 6;

using namespace std;

int main() {

    int numofDice = 0;
    do {
        cout << "Please enter # of dice desired: ";
        cin >> numofDice;
    } while (numofDice < MAX_NUM_DIE || numofDice > MIN_NUM_DIE);

    srand((unsigned int)time(NULL));

    //int diceArr[MAX_NUM_DIE];
    int *dice;
    //dice = (int*)malloc(sizeof(int)*numofDice);
    dice = new int [numofDice];

    if (dice == nullptr) {
        cout << "Could not allocate memory!" << endl;
        exit(1);
    }

    int sum = 0;
    for (int i = 0; i < numofDice; i++) {
        dice[i] = rand() % MAX_DIE_VALUE + 1;
        sum += dice[i];
        cout << "Die Value: " << dice[i] << endl;
        //diceArr[i] = rand() % MAX_DIE_VALUE + 1;
        //sum += diceArr[i];
        //cout << "Die Value: " << diceArr[i] << endl;
    }

    double average = static_cast<double>(sum)/numofDice;
    cout << "The sum is: " << sum << endl;
    cout << "The average is: " << average << endl;

    //free(dice);

    delete[]dice;
    dice = nullptr;

    return 0;
}