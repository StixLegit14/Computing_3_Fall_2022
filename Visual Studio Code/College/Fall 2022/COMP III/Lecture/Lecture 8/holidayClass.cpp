#include <iostream>
#include <string>

using namespace std;

class NewDate {
public:
    void display(void); 
    NewDate(int iMonth, int iDay, int iYear);
private:
    int month;
    int day;
    int year; 
};

class Holiday {
public:
    //constructors
    Holiday(string iName, NewDate iDate, bool idayOff);
    Holiday(string iName, int Month, int iDay, bool idayOff);

private:
    string name;
    NewDate date;
    bool dayOff;
};

int main (int argc, char * argv[]) {

    NewDate today(10, 31, 2022);
    //cout << "Today is: ";
    //today.display();

    Holiday Halloween("Halloween is: ", today, true);

    return 0;
}

NewDate::NewDate(int iMonth, int iDay, int iYear) {
    month = iMonth;
    day = iDay;
    year = iYear;
}

void NewDate::display(void) {
    cout << month << "-" << day << "-" << year << endl;
}

/*
Holiday::Holiday(string iName, NewDate iDate, bool idayOff) {
    name = iName;
    date = iDate;
    dayOff = idayOff;

    cout << name << date << endl;
}

Holiday::Holiday(string iName, int Month, int iDay, bool idayOff) {

}
*/