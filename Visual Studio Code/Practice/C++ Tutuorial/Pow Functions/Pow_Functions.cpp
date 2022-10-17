#include <iostream>
#include <cmath>

using std::cin;
using std::cout;
using std::endl;

int main() {

    //here we see that 10 is being raised to the second power and outputted
    //cout << pow(10, 2) << std::endl;

    int base, exponent;
    cout << "What is base?: ";
    cin >> base;
    cout << "What is exponent?: ";
    cin >> exponent;
    
    double solution = pow(base, exponent);
    cout << "Solution is: " << solution << endl;

    return 0;
}