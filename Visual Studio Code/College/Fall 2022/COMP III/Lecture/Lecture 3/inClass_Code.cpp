#include <iostream>

void getInput(int &, int &, double &, double &);
void swapInts(int &, int &);
void swapDouble(double &, double &);

using namespace std;

int main() {

    int userInput1, userInput2;
    double userInput3, userInput4;
    getInput(userInput1, userInput2, userInput3, userInput4);
    cout << "The input read from the keyboard is: " << userInput1 << " and the second one is: " << userInput2 << endl;
    swapInts(userInput1, userInput2);
    cout << "The swapped ints are: " << userInput1 << " and: " << userInput2 << endl;

    cout << "The double read from the keyboard is: " << userInput3 << " and the second one is: " << userInput4 << endl;
    swapDouble(userInput3, userInput4);
    cout << "The swapped doubles are: " << userInput3 << " and: " << userInput4 << endl;

    return 0;
}

void getInput(int &input1, int &input2, double &input3, double &input4) {

    cout << "Please enter an int1: ";
    cin >> input1;

    cout << "Please enter an int2: ";
    cin >> input2;

    cout << "Please enter an int3: ";
    cin >> input3;

    cout << "Please enter an int4: ";
    cin >> input4;

}

void swapInts(int &input1, int &input2) {

    int temp = input1;
    input1 = input2;
    input2 = temp;

}

void swapDouble(double &input3, double &input4) {

    double temp = input3;
    input3 = input4;
    input4 = temp;

}