#include <iostream>

using std::cin;
using std::cout;

int main() {

    int slices;
    cout << "How many slices of pizza do you want?: ";
    cin >> slices;
    cout << "You have " << slices << " slices of pizza!\n" << std::endl;

    return 0;
}