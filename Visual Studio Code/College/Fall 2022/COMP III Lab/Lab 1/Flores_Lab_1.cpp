#include <iostream>

using namespace std;

int main (int argc, char * argv[]) {
    double interest_num = 1;
    double loan_num = 0;
    double time_num = 0;
    double total_loan = 0;
    double monthly_payment = 0;
    double divider = 100;
    double converter = 12;


    do {
        cout << "Please enter the annuel interest rate as a percentage (e.g. 15 or 15%) (enter 0 to quit): ";
        cin >> interest_num;
        if (interest_num == 0) {
            break;
        }

        cout << "Please enter the amount you would like to recieve: ";
        cin >> loan_num;

        cout << "Please enter the loan period in months: ";
        cin >> time_num;

        double percent = interest_num / divider;

        double period = time_num / converter;

        double temp1 = (percent * period);
        double temp2 = 1 - temp1;
        total_loan = loan_num / temp2;
        monthly_payment = total_loan / time_num;

        cout << "The total amount of your loan (including interest at " << interest_num << "% per annum) is: " << total_loan << endl;
        cout << "Your monthly payment for " << time_num << " months will be: " << monthly_payment << endl;

    } while (interest_num != 0);

    return 0;
}