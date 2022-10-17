#include <iostream>

using namespace std;

class Money {
public:
    //Money();
    Money():dollars(0), cents(0) {}
    //Money(int iDollars, int iCents);
    Money(int iDollars, int iCents):dollars(iDollars), cents(iCents) {}
    Money (int totCents) {dollars = totCents / 100; cents = totCents % 100;}

    int getDollars(void) const {return dollars;};
    int getCents(void) const {return cents;};
    void setDollars(int newDollars) {dollars = newDollars;};
    void setCents(int newCents) {cents = newCents;};

    int toCents(void) const;
    void display(void) const;

private:
    int dollars;
    int cents;
};

//m1 + m2 => +(m1 + m2)
const Money operator+(const Money &left, const Money &right);
const Money operator-(const Money &left, const Money &right);
const bool operator==(const Money &left, const Money &right);
ostream& operator<<(ostream &outstream, const Money &right);
istream& operator>>(istream &outstream, Money &right);
const Money& operator++(Money &operand);
const Money operator++(Money &operand, int dummyVariable);

int main (int argc, char * argv[]) {

    Money m1(3, 50), m2(4, 51), m3;

    cout << "Enter a money, format ($4.56): " << endl;
    cin >> m1;

    cout << "m1: " << m1 << endl;

    m2 = ++m1;
    cout << "m2 is: " << m2;
    cout << "m1 is: " << m1 << endl;

    m2 = m1++;
    cout << "m2 is: " << m2;
    cout << "m1 is: " << m1 << endl;
    return 0;
}

int Money::toCents(void) const {
    return dollars * 100 + cents;
}

void Money::display(void) const {
    cout << "$" << toCents()/100.0 << endl;
}

const Money operator+(const Money &left, const Money &right) {

    Money sum;
    int totCents = left.toCents() + right.toCents();
    //Version 1
    //TODO: sum.dollars
    //sum.setDollars(totCents / 100);
    //TODO: sum.cents
    //sum.setCents(totCents % 100);

    //Version 2
    //TODO: Another Way
    //sum = Money(totCents / 100, totCents % 100);
    //return sum;

    //Version 1 Return
    //TODO: Another way to return
    //return Money(totCents / 100, totCents % 100);

    //TODO: Constructor to do easy work
    return Money(totCents);
}

const Money operator-(const Money &left, const Money &right) {
    Money sum;
    double totCents = left.toCents() - right.toCents();

    return Money(totCents);
}

const bool operator==(const Money &left, const Money &right) {
    return (left.toCents() == right.toCents());
}

ostream& operator<<(ostream &outstream, const Money &right) {

    outstream << "$" << right.toCents() / 100.0 << endl;

    return outstream;
}

istream& operator>>(istream &instream, Money &right) {
    char dollarSign;

    instream >> dollarSign;

    if (dollarSign != '$') {
        cout << "must enter a $" << endl;
    } else {
        //TODO: read the money value
        double dollarVal;
        instream >> dollarVal;
        
        //TODO: update right object
        int totalCents = dollarVal * 100;
        right.setDollars(totalCents / 100);
        right.setCents(totalCents % 100);
    }
    
    return instream;
}

const Money& operator++(Money &operand) {

    int totalCents = operand.toCents() + 101;

    operand.setDollars(totalCents / 100);
    operand.setCents(totalCents % 100);

    return operand;
}

const Money operator++(Money &operand, int dummyVariable) {

    Money tmp = operand;
    int totalCents = tmp.toCents() + 101;

    tmp.setDollars(totalCents/100);
    tmp.setCents(totalCents % 100);

    return tmp;
}