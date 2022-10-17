#include <iostream>

using namespace std;

class NewDate {         //Class
public:                 //Access specifier
    void display(void); //Attribute function call, dedicated to NewDate class 
    //accessor/getter function
    int getMonth(void);
    int getDay(void);
    int getYear(void);
    //mutator/setter function
    void setMonth(int newValue);
    void setDay(int newValue);
    void setYear(int newValue);
private:                //Access specifier
    int month;          //Attribute int variable
    int day;            //Attribute int variable
    int year;           //Attribute int variable

};

int main(int argc, char * argv[]) {

    //create object of type NewDate
    //NewDate today = {9, 16, 2022};
    NewDate today;
    today.setMonth(9);
    today.setDay(6);
    today.setYear(2022);
    //today.getMonth();

    //create object of type NewDate
    NewDate lastDaySchool;
    //access attributes of NewDate 
    /*
    lastDaySchool.month = 12;
    lastDaySchool.day = 12;
    lastDaySchool.year = 2022;
    */

    cout << "Today's date is: ";
    today.display();

    //cout << "Last day of school's date is: ";
    //lastDaySchool.display();

    return 0;
}

void NewDate::display(void) {
    cout << month << "-" << day << "-" << year << endl;
}

int NewDate::getMonth(void) {
    return month;
}

void NewDate::setMonth(int newValue) {
    month = newValue;
}

void NewDate::setDay(int newValue) {
    day = newValue;
}

void NewDate::setYear(int newValue) {
    year = newValue;
}
