#include <iostream>

using namespace std;

template<class S>
class Pair {
public:

private:
    int myClassInt;
};

void mySwap(int &num1, int &num2);
void mySwap(double &num1, double &num2);
void display(int *num1);

//template prefix
template<class T>
void templateSwap(T &num1, T &num2);

template<class U>
void classTemplateSwap(U *num1, U *num2);

typedef int* ArrayPointer;

//template prefix with template call
//template<class T> void templateSwap(T &num1, T &num2);

int main(int argc, char * argv[]) {

    int num1 = 35, num2 = 25;
    //mySwap(num1, num2);
    templateSwap(num1, num2);
    cout << "Num1: " << num1 << " and Num2: " << num2 << endl;

    double num3 = 55, num4 = 45;
    //mySwap(num3, num4);
    templateSwap(num3, num4);
    cout << "Num3: " << num3 << " and Num4: " << num4 << endl;
/*
    int num5 = 65;
    double num6 = 75;
    //mySwap(num3, num4);
    templateSwap(num5, num6);
    cout << "Num5: " << num5 << " and Num6: " << num6 << endl;
*/

    ArrayPointer a, b, c;

    a = new int[3];
    b = new int[3];

    for (int i = 0; i < 3; i++) {
        a[i] = i;
        b[i] = i + 100;
    }

    c = a;

    cout << endl << "a is: ";
    display(a);

    cout << endl << "b is: ";
    display(b);

    cout << endl << "c is: ";
    display(c);

    templateSwap(a, b);

    cout << endl << "a is: ";
    display(a);

    cout << endl << "b is: ";
    display(b);

    cout << endl << "c is: ";
    display(c);

    return 0;
}

void mySwap(int &num1, int &num2) {
    int temp = num1;
    num1 = num2;
    num2 = temp;
}

void mySwap(double &num1, double &num2){
    double temp = num1;
    num1 = num2;
    num2 = temp;
}

template<class T>
void templateSwap(T &num1, T &num2) {
    T holder = num1;
    num1 = num2;
    num2 = holder;
}

template<class U>
void classTemplateSwap(U &num1, U &num2) {
    U *holder = num1;
    num1 = num2;
    num2 = holder;
}

void display(int *arr) {
    for (int i = 0; i < 3; i++) {
        if (i == 2) {
            cout <<  arr[i];
            break;
        }
        cout <<  arr[i] << ", ";
    }
    cout << endl;
}