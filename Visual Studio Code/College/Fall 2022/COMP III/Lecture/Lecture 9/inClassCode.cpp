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

    string getName(void) const;
    NewDate getDate(void) const;
    bool getDayOff(void) const;

    void setName(string newName);
    void setDate(NewDate newDate);
    void setDayOff(bool newDayOff);

private:
    string name;
    NewDate date;
    bool dayOff;
};

void checkDayOff(const Holiday &aHoliday);

int main (int argc, char * argv[]) {

    //Holiday newYearDay;

    Holiday flagDay("Flag Day", 6, 14, true);

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

string Holiday::getName(void) const {
    return name;
}

NewDate Holiday::getDate(void) const {
    return date;
}

bool Holiday::getDayOff(void) const {
    return dayOff;
}

void Holiday::setName(string newName) {
    name = newName;
}

void Holiday::setDate(NewDate newDate) {
    date = newDate;
}

void Holiday::setDayOff(bool newDayOff) {
    dayOff = newDayOff;
}

void checkDayOff(const Holiday &aHoliday) {
    cout << aHoliday.getName() << ": ";
    if (aHoliday.getDayOff()) {
        cout << "have day off" << endl;
    } else {
        cout << "no day off" << endl;
    }
}

/*
Holiday::Holiday(string iName, NewDate iDate, bool idayOff) {
    name = iName;
    date = iDate;
    dayOff = idayOff;
}

Holiday::Holiday(string iName, int Month, int iDay, bool idayOff) {

}
*/