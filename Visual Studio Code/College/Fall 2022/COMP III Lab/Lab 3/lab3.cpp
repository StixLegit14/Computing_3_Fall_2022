#include <iostream>
//used for the input valedation
#include <limits>

//class of type Mass
class Mass{
public:
    //default constructor
    Mass();

    //setter functions 
    void setMassAvoirdupoisPounds(double newInput) {avoirdupoisPounds = newInput;};
    void setMassTroyPounds(double newInput) {troyPounds = newInput;};
    void setMassMetricGrams(double newInput) {metricGrams = newInput;};

    //getter funtions
    double getMassAvoirdupoisPounds(void) const {return avoirdupoisPounds;};
    double getMassTroyPounds(void) const {return troyPounds;};
    double getMassMetricGrams(void) const {return metricGrams;};

    //conversion function
    void convert(double newInput, int sorter);

private:
    //variables to help with conversions
    double drams;
    double avoirdupoisPounds;
    double troyPounds;
    double metricGrams;

};

using namespace std;

int main (int argc, char * argv[]) {

    //basic variables to help with the while loop and code
    bool exiter = false;
    int userInput = -1;
    double baseConvert;
    //object of type Mass to help with the function call
    Mass caller;

    //start of the do-while to make a infinite loop until 0 is entered
    do {
        //input validation
        do {
            cout << "Please enter 1 to use Avoirdupois pounds, 2 to use Troy pounds, 3 to use grams, or 0 to exit: " << endl;
            cin >> userInput;
            if (cin.fail() || userInput > 3 || userInput < 0) {
                cout << "That's not a number greater 0 or less than 3! Please try again..." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                userInput = -1;
            }
        } while (userInput > 3 || userInput < 0);

        //now go a certain direction based on what userInput is
        switch(userInput) {
            //if 0 is entered.. end the loop and program
            case 0:
                cout << "Thanks for using the mass conversion program!" << endl;
                exiter = true;
                break;
            //if 1 is entered, you are starting with avoirdupois pounds and going to troy and grams
            case 1:
                cout << "Please enter a mass in Avoirdupois pounds: " << endl;
                cin >> baseConvert;
                //call convert function
                caller.convert(baseConvert, userInput);
                break;
            //if 2 is entered, you are starting with troy pounds and going to avoirdupois and grams
            case 2:
                cout << "Please enter a mass in Troy pounds: " << endl;
                cin >> baseConvert;
                //call convert function
                caller.convert(baseConvert, userInput);
                break;
            //if 3 is entered, you are starting with mass grams and going to avoirdupois and troy
            case 3:
                cout << "Please enter a mass in grams: " << endl;
                cin >> baseConvert;
                //call convert function
                caller.convert(baseConvert, userInput);
                break;
        }

        //reset baseConvert to zero to avoid any errors
        baseConvert = 0;

    } while(!exiter);

    return 0;
}

//definition for default constructor in Mass class
Mass::Mass () {
    //set all values to zero
    avoirdupoisPounds = 0;
    troyPounds = 0;
    metricGrams = 0;
    drams = 0;
}

//definition for convert function in Mass class
void Mass::convert(double newInput, int sorter) {

    //if sorter is 1, you are starting with avoirdupois pounds and going to troy and grams
    if (sorter == 1) {
        double tmpInput = newInput;
        double tmpInput1 = newInput;
        double tmp = newInput;
        double tmp1 = newInput;

        //set Avoirdupois to userInput
        setMassAvoirdupoisPounds(newInput);

        //print
        cout << "Mass in Avoirdupois pounds is: " << getMassAvoirdupoisPounds() << endl;

        //get drams and them apply drams to tmp
        drams = tmpInput / 0.00390625;
        tmp = (drams * 0.01041666666);

        //set Troy pounds
        setMassTroyPounds(tmp);

        //print
        cout << "Mass in Troy pounds is: " << getMassTroyPounds() << endl;

        //get drams and them apply drams to tmp1
        drams = tmpInput1 / 0.00390625;
        tmp1 = (drams * 1.7718451953125);

        //set Grams pounds
        setMassMetricGrams(tmp1);

        //print
        cout << "Mass in grams is: " << getMassMetricGrams() << endl;
    }
    //if sorter is 2, you are starting with troy pounds and going to avoirdupois and grams
    if (sorter == 2) {
        double tmpInput = newInput;
        double tmpInput1 = newInput;
        double tmp = newInput;
        double tmp1 = newInput;

        //set Troy to userInput
        setMassTroyPounds(newInput);

        //get drams and them apply drams to tmp
        drams = newInput / 0.01041666666;
        tmp = (drams * 0.00390625);

        //set Avoirdupois Pounds
        setMassAvoirdupoisPounds(tmp);

        //print
        cout << "Mass in Avoirdupois pounds is: " << getMassAvoirdupoisPounds() << endl;

        //print
        cout << "Mass in Troy pounds is: " << getMassTroyPounds() << endl;

        //get drams and them apply drams to tmp1
        drams = newInput / 0.01041666666;
        tmp1 = (drams * 1.7718451953125);

        //set Grams pounds
        setMassMetricGrams(tmp1);

        //print
        cout << "Mass in grams is: " << getMassMetricGrams() << endl;
    }
    //if sorter is 3, you are starting with mass grams and going to avoirdupois and troy
    if (sorter == 3) {
        double tmpInput = newInput;
        double tmpInput1 = newInput;
        double tmp = newInput;
        double tmp1 = newInput;

        //set grams to userInput
        setMassMetricGrams(newInput);

        //get drams and them apply drams to tmp
        drams = newInput / 1.7718451953125;
        tmp = (drams * 0.00390625);

        //set Avoirdupois pounds
        setMassAvoirdupoisPounds(tmp);

        //print
        cout << "Mass in Avoirdupois pounds is: " << getMassAvoirdupoisPounds() << endl;

        //get drams and them apply drams to tmp1
        drams = newInput / 1.7718451953125;
        tmp1 = (drams * 0.01041666666);

        //set Troy pounds
        setMassTroyPounds(tmp1);

        //print
        cout << "Mass in grams is: " << getMassTroyPounds() << endl;

        //print
        cout << "Mass in grams is: " << getMassMetricGrams() << endl;
    }

}

/*
Matthew:
Created function definitions and comments

Andrew:
Worked on the error checking and inputs, and checked for invalid input

Ullysses:
Created the class Mass and the functions inside

Austin:
Ceated main function to work on debugging
*/