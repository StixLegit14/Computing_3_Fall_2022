#include <iostream>
#include <iomanip>
#include <cmath>
#include <limits>

using namespace std;

void getMeasurments(int &, double &);
void convertMeasurments(int, double, int &, double &);
void returnMeasurments(int, double, int, double);

int main (int argc, char * argv[]) {
    int pounds = -1;
    double ounces = 0.00;
    int kilograms;
    double grams;

    getMeasurments(pounds, ounces);
    convertMeasurments(pounds, ounces, kilograms, grams);
    returnMeasurments(pounds, ounces, kilograms, grams);

    return 0;
}

void getMeasurments(int &pounds, double &ounces) {
    do {
        cout << "Please enter measurements for pounds: ";
        cin >> pounds;
        if (pounds <= 0) {
            cout << "That's not a number greater than or equal to 0! Please try again..." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            pounds = -1;
        }
    } while (pounds < 0);
    
    do {
        cout << "Please enter measurements for ounces: ";
        cin >> ounces;
        if (ounces >= 16) {
            cout << "That's not a number greater than or equal to 0, and less than 16! Please try again..." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            ounces = 0.00;
        }
    } while (ounces < 0.00);

}

void convertMeasurments(int pounds, double ounces, int &kilograms, double &grams) {
    double tempP = static_cast<double>(pounds);
    double tempO = ounces;
    int itempK;
    double tempK;
    double tempG;

    tempP = (tempP + tempO);

    tempK = (tempP * 0.45359237);
    itempK = tempK;
    cout << itempK;
    
    tempG = tempK;
    grams = (kilograms - grams) * 1000;
}

void returnMeasurments(int pounds, double ounces, int kilograms, double grams) {
    cout << "The user entered " << floor(pounds) << " and " << ounces << endl;
    cout << "The conversion to metric is: " << floor(kilograms) << " kilograms and " << setprecision(8) << grams << " grams!" << endl;
}