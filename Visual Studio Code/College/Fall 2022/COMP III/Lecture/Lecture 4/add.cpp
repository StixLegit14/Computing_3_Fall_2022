#include <iostream>

void add(int &, int &, int &, int &);
void add(double &, double &, double &, double &);

using namespace std;

int main(int argc, char * argv[]) {
    int i_num1 = 1;
    int i_num2 = 2;
    int i_num3 = 3;
    int i_sum;
    double d_num1 = 1.1;
    double d_num2 = 2.2;
    double d_num3 = 3.3;
    double d_sum;

    add(i_num1, i_num2, i_num3, i_sum);
    add(d_num1, d_num2, d_num3, d_sum);

    cout << "Integer addition comes out too: " << i_sum << endl;
    cout << "Double addition comes out too: " << d_sum << endl;

    return 0;
}

void add(int &input1, int &input2, int &input3, int &sum) {

    sum = input1 + input2 + input3;

}

void add(double &input1, double &input2, double &input3, double &sum) {

    sum = input1 + input2 + input3;

}