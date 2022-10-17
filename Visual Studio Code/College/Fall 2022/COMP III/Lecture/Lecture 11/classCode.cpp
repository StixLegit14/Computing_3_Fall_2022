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
Money operator+(const Money &left, const Money &right);

int main (int argc, char * argv[]) {

    Money m1(3, 50), m2(4, 51), m3;
    //creates temporary object ad will e gone after this line
    (m1 + m2).display();

    //creates temporary object ad will e gone after this line
    m3 = m1 + m2;
    m3.display();

    /*
    if (m3 = m1 + m2) {

    }
    */

   //creates temporary object ad will e gone after this line
   (m1 + m2).setCents(20);

    return 0;
}

int Money::toCents(void) const {
    return dollars * 100 + cents;
}

void Money::display(void) const {
    cout << "$" << toCents()/100.0 << endl;
}

Money operator+(const Money &left, const Money &right) {

    Money sum;
    int totCents = left.toCents() + right.toCents();
    //TODO: sum.dollars
    //sum.setDollars(totCents / 100);
    //TODO: sum.cents
    //sum.setCents(totCents % 100);
    //TODO: Another Way
    //sum = Money(totCents / 100, totCents % 100);
    //return sum;
    //TODO: Another way to return
    //return Money(totCents / 100, totCents % 100);
    //TODO: Constructor to do easy work
    return Money(totCents);
}