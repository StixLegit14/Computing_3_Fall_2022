#include <iostream>

using namespace std;

class NewDate {         //Class
public:                 //Access specifier
    //constructors
    NewDate();//default constructors
    NewDate(int initMonth, int initDay, int initYear);
    NewDate(int initMonth, int initDay);

    //mutator/setter function
    void SetMonth(int newValue);
    void SetDay(int newValue);
    void SetYear(int newValue);

    //accessor/getter function
    int getMonth(void);
    int getDay(void);
    int getYear(void);

    //Attribute function call
    void display(void); 
//private:              //Access specifier
    int month;          //Attribute int variable
    int day;            //Attribute int variable
    int year;           //Attribute int variable

};

int main(int argc, char * argv[]) {

    NewDate today(9, 19, 2022);

    //calling a default constructor
    NewDate lastDaySchool;

    cout << "Today's date is: ";
    today.display();

    cout << "Last day of school's date is: ";
    lastDaySchool.display();


    return 0;
}

NewDate::NewDate() {
    month = 1;
    day = 1;
    year = 2022;
}

NewDate::NewDate(int initMonth, int initDay, int initYear) {
    month = initMonth;
    day = initDay;
    year = initYear;
}

NewDate::NewDate(int initMonth, int initDay) {
    month = initMonth;
    day = initDay;
    year = 2022;
}

void NewDate::display(void) {
    cout << month << "-" << day << "-" << year << endl;
}