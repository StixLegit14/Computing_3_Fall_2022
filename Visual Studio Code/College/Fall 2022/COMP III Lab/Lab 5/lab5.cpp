#include <iostream>

using namespace std;

// class with the means to deal with complex numbers (numbers containing imaginary numbers)
class ComplexNumber {
public:
    ComplexNumber():real(0), imaginary(0) {};
    ComplexNumber(double initReal, double initImaginary):real(initReal), imaginary(initImaginary) {};

    // Functions to set and retrieve the imaginary and real numbers
    void setReal(double initReal) {real = initReal;}
    double getReal(void) const {return real;}
    void setImaginary(double initImaginary) {imaginary = initImaginary;}
    double getImaginary(void) const {return imaginary;}

    // operators overloads for dealing with complex numbers
    friend ComplexNumber operator+(ComplexNumber &obj1, ComplexNumber &obj2);
    friend ComplexNumber operator-(ComplexNumber &obj1, ComplexNumber &obj2);
    friend ComplexNumber operator*(ComplexNumber &obj1, ComplexNumber &obj2);
    friend ComplexNumber operator/(ComplexNumber &obj1, ComplexNumber &obj2);

private:
    double real;
    double imaginary;
};

// operator overload declarations
ostream& operator<<(ostream &outstream, ComplexNumber &obj); // output operator
ComplexNumber operator+(ComplexNumber &obj1, ComplexNumber &obj2); // obj1 + obj2
ComplexNumber operator-(ComplexNumber &obj1, ComplexNumber &obj2); // obj1 - obj2
ComplexNumber operator*(ComplexNumber &obj1, ComplexNumber &obj2); // obj1 * obj2
ComplexNumber operator/(ComplexNumber &obj1, ComplexNumber &obj2); // obj1 / obj2

int main(int argc, char * argv[]) {
    // driver program
    ComplexNumber c1, c2(1, 2), c3(3, 4), t1, t2, f1, f2, o1;

    // testing get and set functions for real numbers
    cout << "Value of c1 (default constructor): " << endl;
    cout << "c1.getReal() == " << c1.getReal() << ", c1.getImaginary() == " << c1.getImaginary() << endl;

    // testing set and get functions for imaginary
    cout << "Value of c2 (value constructor): " << endl;
    cout << "c2.getReal() == " << c2.getReal() << ", c2.getImaginary() == " << c2.getImaginary() << endl;

    // testing '+' operator for addition 
    f1.setReal(c2.getReal() + c3.getReal());
    f1.setImaginary(c2.getImaginary() + c3.getImaginary());
    cout << "c2 + c3 " << "(" << c2 << " + " << c3 << ")" << " == " << f1 << endl;

    // testing '-' operator for subtraction
    f1.setReal(c2.getReal() - c3.getReal());
    f1.setImaginary(c2.getImaginary() - c3.getImaginary());
    cout << "c2 - c3 " << "(" << c2 << " - " << c3 << ")" << " == " << f1 << endl;

    // testing '*' operator for multiplication
    t1.setReal(c2.getReal() * c3.getReal());
    t1.setImaginary((c2.getImaginary() * c3.getImaginary() * -1));
    f1.setReal((t1.getReal() + t1.getImaginary()));
    f1.setImaginary((c2.getReal() * c3.getImaginary()) + (c2.getImaginary() * c3.getReal()));
    cout << "c2 * c3 " << "(" << c2 << " * " << c3 << ")" << " == " << f1 << endl;

    // testing '/' operator for division
    t1.setReal(((c2.getReal() * c3.getReal()) + (c2.getImaginary() * c3.getImaginary())));
    t2.setReal((c3.getReal() * c3.getReal()) + (c3.getImaginary() * c3.getImaginary()));
    f2.setReal(t1.getReal() / t2.getReal());
    t1.setImaginary(((c2.getImaginary() * c3.getReal()) - (c2.getReal() * c3.getImaginary())));
    t2.setImaginary((c3.getReal() * c3.getReal()) + (c3.getImaginary() * c3.getImaginary()));
    f2.setImaginary((t1.getImaginary() / t2.getImaginary()));
    cout << "c2 / c3 " << "(" << c2 << " / " << c3 << ")" << " == " << f2 << endl;

    // testing multi-functional probelm set
    o1.setReal(f1.getReal() + f2.getReal());
    o1.setImaginary(f1.getImaginary() + f2.getImaginary());
    cout << "(c2 / c3) + (c2 * c3) == " << o1 << endl;

    // testing for conjugate
    t1.setReal(c2.getReal());
    t1.setImaginary((c2.getImaginary() * -1));
    cout << "Conjugate of c2 (1+2i) == " << t1 << endl;
   
    // testing Output methods
    // indexed method
    cout << "Vector output using indexed for-loop: " << endl;
    int j = 2;
    int k = 0;
    for (int i = 0; i < 10; i++) {
        cout << c1 << endl;

        c1.setReal(c1.getReal() + (k + 1));
        c1.setImaginary(c1.getImaginary() + j);
    }

    c1.setReal(0);
    c1.setImaginary(0);

    // itorator method
    cout << "Vector output using an iterator in for-loop: " << endl;
    for (int i = 0; i < 10; i++) {
        cout << c1 << endl;

        c1.setReal(c1.getReal() + 1);
        c1.setImaginary(c1.getImaginary() + 2);
    }

    return 0;
}   // end of driver

// operator overloads definitions
// '<<' Output Operator
ostream& operator<<(ostream &outstream, ComplexNumber &obj) {
    outstream << obj.getReal() << "+" << obj.getImaginary() << "i";
    return outstream;
}

// '+' Addition
ComplexNumber operator+(ComplexNumber &obj1, ComplexNumber &obj2) {
    ComplexNumber newObj;

    newObj.real = obj1.real + obj2.real;

    newObj.imaginary = obj1.imaginary + obj2.imaginary;

    return newObj;
}

// '-' subtraction
ComplexNumber operator-(ComplexNumber &obj1, ComplexNumber &obj2) {
    ComplexNumber newObj;

    newObj.real = obj1.real - obj2.real;

    newObj.imaginary = obj1.imaginary - obj2.imaginary;

    return newObj;
}

// '*' multiplication
ComplexNumber operator*(ComplexNumber &obj1, ComplexNumber &obj2) {
    ComplexNumber newObj;

    newObj.real = obj1.real * obj2.real;

    newObj.imaginary = obj1.imaginary * obj2.imaginary;
 
    return newObj;
}

// '/' division
ComplexNumber operator/(ComplexNumber &obj1, ComplexNumber &obj2) {
    ComplexNumber newObj;

    newObj.real = obj1.real / obj2.real;

    newObj.imaginary = obj1.imaginary / obj2.imaginary;

    return newObj;
}

/*
COMP III Lab 5
Group 3
10/12/22

Matthew: Worked on the main program
Rohan: Set up the class and the conjugate
Cole: Worked on commenting the entire program
Ryan: Worked on all of the +, -, *, and / overload functions
*/