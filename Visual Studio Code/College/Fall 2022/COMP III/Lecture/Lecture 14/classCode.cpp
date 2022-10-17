//  C3_Lecture14, overload operator as friend/member

#include <iostream>
using namespace std;

class Money
{
public:
    Money():dollars(0), cents(0){}
    Money(int iDollars, int iCents):dollars(iDollars), cents(iCents){}
    Money(double moneyAmount);
    
    int getDollars(void) const {
        return dollars;
    }
    int getCents(void) const {
        return cents;
    }
    
    void setDollars(int newDollars) {
        dollars = newDollars;
    }
    void setCents(int newCents) {
        cents = newCents;
    }
    
    void display(void) const;
     int toCents(void) const;
    
    //const Money add(const Money &rightOp);
    //overload + operator as a member operator
    const Money operator+(const Money &rightOp);
    //const Money operator+(double rightOp);
    
    friend const Money& operator++(Money &op);//just declare the function is a friend of the class, not formal function declaration

private:
    int dollars;
    int cents;
};
//cost + tax
//const Money operator+(const Money &leftOp, const Money &rightOp);
//const Money operator+(const Money &leftOp, double moneyAmount);
const Money operator+(double leftOp, const Money &rightOp);
//+(cost, tax);
const Money operator-(const Money &leftOp, const Money &rightOp);
bool operator==(const Money& leftOp, const Money& rightOp);


//-m1
const Money operator-(const Money &op);

//++m1; prefix
const Money& operator++(Money &op);

//m1++; postfix
const Money operator++(Money &op, int);

//cout << m1;
//function call: <<(cout, m1);
ostream &operator<<(ostream &outStream, const Money &m);

//>>(cin, m1);
istream &operator>>(istream &inStream, Money &m);


int main(int argc, const char * argv[]) {
    Money m1(3, 59), m2(4, 50);
    //cout << "m1: ";
    cout << m1;
    
    //cout << endl;
    //cout << "Enter a money value, starting from $, e.g., $5.67:";
    //cin >> m1;
    //>>(cin, m1);
    
    cout << "m1: " << m1 << endl;
    cout << "m1 + m2: " << m1 + m2 << endl;
    //+(m1, m2)
    
    //m1.add(m2);
    //m1.+(m2);
    
    Money  cost(1, 50), total;
    total = cost + 35.5; //(1)
    total = 35.5 + cost; //(2)
    
    m2 = -m1;
    cout << "m2: " << m2 << endl;
    
    ++m1;
    
    m1++;
    
    //cout << "m2: ";
    //m2.display();
    
    //Money m3;
    /*
    m3 = m1 + m2;
    m3.display();
    //m1+m2 = m1;
    //(m1+m2).setDollars(98);
    
    Money m4;
    m4 = m1 - m2;
    m4.display();
    
    if (m1 == m2) {
        cout << "we have the same money amount" << endl;
    } else {
        cout << "we have the different money amount" << endl;
    }
     */
    return 0;
}

Money::Money(double moneyAmount)
{
    int totalCents = moneyAmount * 100;
    dollars = totalCents / 100;
    cents = totalCents % 100;
}


int Money::toCents(void) const {
    return dollars * 100 + cents;
}

void Money::display(void) const {
    cout << "$" << toCents()/100.0 << endl;
}

ostream &operator<<(ostream &outStream, const Money &m)
{
    outStream << "$" << m.toCents()/100.0;
    return outStream;
}

//input format should be: $3.59, $5

istream &operator>>(istream &inStream, Money &m)
{
    char c;
    inStream >> c;
    if (c != '$')
    {
        cout << "Wrong format! please start with $!";
        exit(1);
    }
    //read the value
    double moneyAmount;
    inStream >> moneyAmount;
    //update Money object m
    int totalCents = round(moneyAmount * 100);
    m = Money(totalCents / 100, totalCents % 100);
    
    //return istream object
    return inStream;
    
}
const Money operator+(const Money &leftOp, const Money &rightOp)
{
    int totalCents = leftOp.toCents() + rightOp.toCents();
    int dollars = totalCents / 100;
    int cents = totalCents % 100;
    
    Money sum(dollars, cents);
    
    return sum;
}
//overload + operator as a member operator
const Money Money::operator+(const Money &rightOp)
{
    int totalCents = toCents() + rightOp.toCents();
    return Money(totalCents / 100, totalCents % 100);
}

const Money operator-(const Money &leftOp, const Money &rightOp)
{
    int totalCents = leftOp.toCents() - rightOp.toCents();
    if (totalCents < 0)
        totalCents = -totalCents;
    
    int dollars = totalCents / 100;
    int cents = totalCents % 100;
    
    return Money(dollars, cents);
}

bool operator==(const Money& leftOp, const Money& rightOp)
{
    return (leftOp.toCents() == rightOp.toCents());
}

//overload negative sign -
const Money operator-(const Money &op)
{
    return Money(-op.getDollars(), -op.getCents());
}


//++m1; prefix
//+1 to dollars, +1 to cents
const Money& operator++(Money &op)
{
    //increment money object
    //op.setDollars(op.getDollars() + 1);
    //op.setCents(op.getCents() + 1);
    op.dollars ++;
    op.cents ++;
    //TODO: check if cents over 100, can add code in constructor
    
    //return the incremented value
    return op;
}

//m1++; postfix
const Money operator++(Money &op, int)
{
    //increment money object
    Money result(op);
    op.setDollars(op.getDollars() + 1);
    op.setCents(op.getCents() + 1);
    //return non-incremented value of op
    return result;
}