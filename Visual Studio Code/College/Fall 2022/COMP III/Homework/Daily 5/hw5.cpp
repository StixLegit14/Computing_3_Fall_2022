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
Date: 10/06/22
Name: Matthew Flores
*/
/***********************************************
Author: Matthew Flores
Date: 10/06/22
Purpose: Write a class Rational and work with overloading a variety of functions.
Sources of Help: geeksforgeeks and programiz.
Time Spent: 3 hours
***********************************************/

#include <iostream>

using namespace std;

class Rational {
public:
    //constructors
    Rational();
    Rational(int);
    Rational(int, int);

    //setter and getter functions
    int getNumerator(void) const {return numerator;};
    int getDenominator(void) const {return denominator;};
    void setNumerator(int initnum) {numerator = initnum;};
    void setDenominator(int initden) {denominator = initden;};

private:
    //private members
    int numerator;
    int denominator;
};

//overloader function for operators
const Rational operator+(const Rational &obj1, const Rational &obj2); // obj1 + obj2
const Rational operator-(const Rational &obj1, const Rational &obj2); // obj1 - obj2
const Rational operator*(const Rational &obj1, const Rational &obj2); // obj1 * obj2
const Rational operator/(const Rational &obj1, const Rational &obj2); // obj1 / obj2
const bool operator==(const Rational &obj1, const Rational &obj2); // obj1 == obj2
const bool operator<=(const Rational &obj1, const Rational &obj2); // obj1 <= obj2
const bool operator>=(const Rational &obj1, const Rational &obj2); // obj1 >= obj2
const bool operator<(const Rational &obj1, const Rational &obj2); // obj1 < obj2
const bool operator>(const Rational &obj1, const Rational &obj2); // obj1 > obj2
const int operator%(const Rational &obj1, const Rational &obj2);
ostream& operator<<(ostream &outstream, Rational &right); // output operator
istream& operator>>(istream &outstream, Rational &right); // input operator

//simplify fraction
int simplifier(Rational &obj1);

int main (int argc, char * argv[]) {
    //make variable
    int returner = 0;

    //make objects of type Rational
    Rational t1, t2(2), t3(1, 2), r1, tmp, holder;

    //t1 will be 0/1 and output-> 0
    cout << "test1 started with case (0/1)... this evaluates to: " << t1;

    //t2 will be setNum/1 and output-> setNum
    cout << "test2 started with case (setNum/1) (let setNum = 2)... this evaluates to: " << t2;

    //t3 will be setNum1/setNum2 and output-> setNum1/setNum2
    cout << "test3 started with case (setNum1/setnum2) (let setNum1 = 1 and setNum2 = 2)... this evaluates to: " << t3;

    //get vales for r1
    cin >> r1;

    //if either the numerator and denominator are negative, save the number and make it positive and store it for use later
    if (r1.getNumerator() < 0) {
        holder.setNumerator(r1.getNumerator());
        r1.setNumerator(r1.getNumerator() * -1);
    } else if (r1.getDenominator() < 0) {
        holder.setDenominator(r1.getDenominator());
        r1.setDenominator(r1.getDenominator() * -1);
    }

    //check to see if you can simplify the fraction
    if (r1.getNumerator() > r1.getDenominator()) {
        //cout << "Numerator is greater than denominator!" << endl;
        tmp = r1;
        returner = simplifier(tmp);
        //cout << "returner is: " << returner << endl;

        tmp.setNumerator(returner);
        //cout << "tmp.getNumerator() is: " << tmp.getNumerator() << endl;

        //cout << "r1.getNumerator() before is: " << r1.getNumerator() << endl;
        r1.setNumerator(r1.getNumerator() / tmp.getNumerator());
        //cout << "r1.getNumerator() after is: " << r1.getNumerator() << endl;
        //cout << "r1.getDenominator() before is: " << r1.getDenominator() << endl;
        r1.setDenominator(r1.getDenominator() / tmp.getNumerator());
        //cout << "r1.getDenominator() after is: " << r1.getDenominator() << endl;
    } else if (r1.getNumerator() < r1.getDenominator()) {
        //cout << "Numerator is less than denominator!" << endl;
        tmp = r1;
        returner = simplifier(tmp);

        tmp.setNumerator(returner);

        r1.setNumerator(r1.getNumerator() / tmp.getNumerator());
        r1.setDenominator(r1.getDenominator() / tmp.getNumerator());

    } else if (r1.getNumerator() >= r1.getDenominator()) {
        //cout << "Numerator is greater than or equal too denominator!" << endl;
        tmp = r1;
        returner = simplifier(tmp);

        tmp.setNumerator(returner);

        r1.setNumerator(r1.getNumerator() / tmp.getNumerator());
        r1.setDenominator(r1.getDenominator() / tmp.getNumerator());
    } else if (r1.getNumerator() <= r1.getDenominator()) {
        //cout << "Numerator is less than or equal too denominator!" << endl;
        tmp = r1;
        returner = simplifier(tmp);

        tmp.setNumerator(returner);

        r1.setNumerator(r1.getNumerator() / tmp.getNumerator());
        r1.setDenominator(r1.getDenominator() / tmp.getNumerator());
    }

    //look to see if the numerator or denominator are negative and change it to have the correct sign placement
    if (holder.getNumerator() < 0) {
        r1.setNumerator(r1.getNumerator() * -1);
        //r1.setDenominator(r1.getDenominator() * -1);
    } else if (holder.getDenominator() < 0) {
        r1.setNumerator(r1.getNumerator() * -1);
    }

    //output r1
    cout << r1;


    return 0;
}

//basic constructor that sets the memeber variables to 0/1
Rational::Rational() {
    numerator = 0;
    denominator = 1;
}

//constructor that notices if one number is entered, make it set over one wholeNumber/1
Rational::Rational(int wholeNumber) {
    numerator = wholeNumber;
    denominator = 1;
}

//constructor that allows two set numbers to be initnum/initden
Rational::Rational(int initnum, int initden) {
    numerator = initnum;
    denominator = initden;
}

//does basic addition for passed in rational type
const Rational operator+(const Rational &obj1, const Rational &obj2) {
    return obj1 + obj2;
}

//does basic subtraction for passed in rational type
const Rational operator-(const Rational &obj1, const Rational &obj2) {
    return obj1 - obj2;
}

//does basic multiplication for passed in rational type
const Rational operator*(const Rational &obj1, const Rational &obj2) {
    return (obj1 * obj2);
}

//does basic division for passed in rational type
const Rational operator/(const Rational &obj1, const Rational &obj2) {
    return (obj1 / obj2);
}

//checks if the passed in rational type is equal too one another
const bool operator==(const Rational &obj1, const Rational &obj2) {
   return obj1 == obj2;
}

//checks if the passed in rational type is greater than or equal too one another
const bool operator<=(const Rational &obj1, const Rational &obj2) {
    return obj1 <= obj2;
}

//checks if the passed in rational type is less than or equal too one another
const bool operator>=(const Rational &obj1, const Rational &obj2) {
    return obj1 >= obj2;
}

//checks if the passed in rational type is greater than one another
const bool operator<(const Rational &obj1, const Rational &obj2) {
    return obj1 < obj2;
}

//checks if the passed in rational type is less than one another
const bool operator>(const Rational &obj1, const Rational &obj2) {
    return obj1 > obj2;
}

//checks the modulus of a 2 passed in rational type
const int operator%(const Rational &obj1, const Rational &obj2) {
    return obj1 % obj2;
}

//overloader for cout
ostream& operator<<(ostream &outstream, Rational &right) {
    if (right.getDenominator() == 1) {
        outstream << right.getNumerator() << endl;
        return outstream;
    } else {
        outstream << right.getNumerator() << "/" << right.getDenominator() << endl;
        return outstream;
    }
}

//overleader for cin
istream& operator>>(istream &instream, Rational &right) {
    int numerator, denominator;

    cout << "Enter a number for numerator: ";
    instream >> numerator;
    right.setNumerator(numerator);

    cout << "Enter a number for denominator: ";
    instream >> denominator;
    right.setDenominator(denominator);

    return instream;
}

//simplifier that simplifies the fraction
int simplifier(Rational &obj1) {
    while ((obj1.getNumerator() != 0) && (obj1.getDenominator() != 0)) {
        if (obj1.getNumerator() >= obj1.getDenominator()) {

            //cout << "num for num >= den before: " << obj1.getNumerator() << endl;
            //cout << "den for num >= den before: " << obj1.getDenominator() << endl;
            obj1.setNumerator(obj1.getNumerator() % obj1.getDenominator());
            //cout << "num for num >= den after: " << obj1.getNumerator() << endl;
            //cout << "den for num >= den after: " << obj1.getDenominator() << endl;

        } else {

            //cout << "num for num < den before" << obj1.getNumerator() << endl;
            //cout << "den for num < den before" << obj1.getDenominator() << endl;
            obj1.setDenominator(obj1.getDenominator() % obj1.getNumerator());
            //cout << "num for num < den after" << obj1.getNumerator() << endl;
            //cout << "den for num < den after" << obj1.getDenominator() << endl;

        }
    }
    //cout << "num for num + den before" << obj1.getNumerator() << endl;
    //cout << "den for num + den before" << obj1.getDenominator() << endl;
    obj1.setNumerator(obj1.getNumerator() + obj1.getDenominator());
    //cout << "num for num + den after" << obj1.getNumerator() << endl;
    //cout << "den for num + den after" << obj1.getDenominator() << endl;
    return obj1.getNumerator();
}