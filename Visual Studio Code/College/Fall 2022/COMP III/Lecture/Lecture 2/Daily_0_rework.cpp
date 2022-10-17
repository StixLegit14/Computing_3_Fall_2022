//#include <stdio.h>
#include <iostream>
//#include <stdlib.h>
#include <cstdlib> //same a <stdlib.h>
//#include <time.h>
#include <ctime> // same a <time.h>

//#define MAX_DIE_NUM     2
//#define MIN_DIE_NUM     5
//#define MAX_DIE_VALUE   6

const int MAX_NUM_DIE = 2;
const int MIN_NUM_DIE = 5;
const int MAX_DIE_VALUE = 6;

//using namespace std;

int main() {

    int numofDice = 0;
    do {
        //printf("Please enter # of dice desired: ");
        std::cout << "Please enter # of dice desired: ";
        //scanf("%d", &numofDice);
        std::cin >> numofDice;
    } while (numofDice < MAX_NUM_DIE || numofDice > MIN_NUM_DIE);

    srand((unsigned int)time(NULL));

    int diceArr[MAX_NUM_DIE];
    int sum = 0;
    for (int i = 0; i < numofDice; i++) {
        diceArr[i] = rand() % MAX_DIE_VALUE + 1;
        sum += diceArr[i];
        //printf("Die Value: %d\n", diceArr[i]);
        std::cout << "Die Value: " << diceArr[i] << std::endl;
    }

    double average = static_cast<double>(sum)/numofDice;
    //printf("The sum is: %d\n", sum);
    std::cout << "The sum is: " << sum << std::endl;
    //printf("The average is: %.2f\n", average);
    std::cout << "The average is: " << average << std::endl;

    return 0;
}