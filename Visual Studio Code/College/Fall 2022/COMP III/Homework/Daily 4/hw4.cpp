/*
Computing III -- COMP.2010 Honor Statement
The practice of good ethical behavior is essential for maintaining
good order in the classroom, providing an enriching learning
experience for students, and as training as a practicing computing
professional upon graduation. This practice is manifested in the
University’s Academic Integrity policy. Students are expected to
strictly avoid academic dishonesty and adhere to the Academic
Integrity policy as outlined in the course catalog. Violations will
be dealt with as outlined therein.
All programming assignments in this class are to be done by the
student alone. No outside help is permitted except the instructor and
approved tutors.
I certify that the work submitted with this assignment is mine and was
generated in a manner consistent with this document, the course
academic policy on the course website on Blackboard, and the UMass
Lowell academic code.
Date: 09/26/22
Name: Matthew Flores
*/
/***********************************************
Author: Matthew Flores
Date: 09/26/22
Purpose: Write a zip code class that encodes and decodes five-digit bar codes used by the US Postal Service on envelopes.
Sources of Help: geeksforgeeks, programiz, Christain A., Jacob B., Matthew L.
Time Spent: 6 hours
***********************************************/
#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>

using namespace std;

class ZipCode {
public:
    //constructor for type int and string
    ZipCode(int);
    ZipCode(string);

    //getter functions for the zip and bar code
    int getZipCode(void);
    string getBarCode(void);

private:
    //member function for the class
    int conversion(string);
    int givenzipCode;
    string givenbarCode;
};

int main(int argc, char * argv[]) {
    ZipCode zip(99504),
    zip2("100101010011100001100110001"),
    zip3(12345),
    zip4(67890);
    
    cout << zip.getZipCode() << "'s bar code is '"
    << zip.getBarCode() << "'" << endl;
    cout << zip2.getZipCode() << "'s bar code is '"
    << zip2.getBarCode() << "'" << endl;
    cout << zip3.getZipCode() << "'s bar code is '"
    << zip3.getBarCode() << "'" << endl;
    cout << zip4.getZipCode() << "'s bar code is '"
    << zip4.getBarCode() << "'" << endl;
    
    cout << endl;
    
    // Test a range of values by first constructing a zip code
    // with an integer, then retrieving the bar code and using
    // that to construct another ZipCode.

    int zip_int = 0;
    for (int i = 0; i < 25; i++)
    {
        // Make an aribrary 5-digit zip code integer, and use it
        // to construct a ZipCode
        int five_digit_zip = (zip_int * zip_int) % 100000;
        ZipCode z1(five_digit_zip);
        
        // Construct a second ZipCode from the first's bar code
        string z1_barcode = z1.getBarCode();
        ZipCode z2(z1_barcode);
        
        cout.width(3);
        cout << (i + 1) << ": ";
        cout.width(5);
        cout << z2.getZipCode() << " has code '"
        << z1_barcode << "'";
        
        if ((z1_barcode == z2.getBarCode()) &&
            (z1.getZipCode() == z2.getZipCode()) &&
            (z2.getZipCode() == five_digit_zip))
        {
            cout << " [OK]" << endl;
        }
        else
        {
            cout << " [ERR]" << endl;
        }
        
        // Increment the test value arbitrarily
        zip_int += (233 + zip_int % 7);
    }
    cout << endl;
    
    // Test some error conditions. This test assumes that
    // ZipCode will simply set its value to a flag that indicates
    // an error, and will not exit the program.
    int BAD_ZIP_COUNT = 2;
    string bad_zips[][2] = {
        { "100101010011100001100110000", "bad start/end character" },
        { "100101010011100001100110021", "bad digit" },
    };
    for (int i = 0; i < BAD_ZIP_COUNT; i++)
    {
        cout << "Testing: " << bad_zips[i][1] << " " << bad_zips[i][0] << endl;
        ZipCode test(bad_zips[i][0]);
        cout << endl;
    }
    cout << "Enter a character to quit." << endl;
    char c;
    cin >> c;
    return 0;
}

/// this function is of type ZipCode class and it sets the givenzipCode to the passed in number 
/// you pass in num
ZipCode::ZipCode(int num) {
    //num will be passed to givenzipCode
    givenzipCode = num;
}

/// this function is of type ZipCode class and it sets the givenzipCode to the passed in string 
/// you pass in str 
ZipCode::ZipCode(string str) {
    //initalize tmp variable and set it equal to conversion(str)
    int tmp = conversion(str);
    //set givenzipCode equal to tmp
    givenzipCode = tmp;
}

/// this function is of type ZipCode class and it returns givenzipCode in the class
/// this function has no parameters
/// this returns givenzipCode
int ZipCode::getZipCode(void) {
    //retuen givenzipCode
    return givenzipCode;
}

/// this function is of type ZipCode class and it returns the retVal
/// this has no parameters
/// this returns the string I created in this code
string ZipCode::getBarCode(void) {
    //set all variables needed for function
    int i = 0, tmp = givenzipCode, tmp1 = 0, tmpArr[5];
    string retStr = "1";
    
    //set tmp1 to tmp
    tmp1 = tmp;
    //if tmp1 / 10,000 < 1
    if(tmp1/10000 < 1) {
        //retStr = retStr + 11000
        retStr +="11000";
    }
    //if tmp1 / 1000 < 1
    if(tmp1/1000 < 1) {
        //retStr = retStr + 11000
        retStr += "11000";
    }
    //if tmp1 / 100 < 1
    if(tmp1/100 < 1) {
        //retStr = retStr + 11000
        retStr += "11000";
    }
    //if tmp1 / 10 < 1
    if(tmp1/10 < 1) {
        //retStr = retStr + 11000
        retStr += "11000";
    }
    //if tmp1 == 0
    if(tmp1 == 0) {
        //retStr = retStr + 11000 + 1
        retStr += "11000";
        retStr += "1";
        return retStr;
    }

    //while tmp1 / 10 > 0... tmp1 = tmp1 / 10
    do {
        tmp1 /= 10;
    } while ((tmp1/10) > 0);

    //tmpArr[i + 1] = tmp1
    tmpArr[i++] = tmp1;
    
    //tmp1 = tmp
    tmp1 = tmp;

    //while tmp1 / 10 > 10... tmp1 = tmp1 / 10
    do {
        tmp1 /= 10;
    } while ((tmp1/10) > 10);

    //tmpArr[i + 1] = tmp1 - (tmpArr[0] * 10)
    tmpArr[i++] = tmp1 - (tmpArr[0] * 10);

    //tmp1 = tmp
    tmp1 = tmp;

    //while tmp1 / 10 > 0... tmp1 = tmp1 / 10
    do {
        tmp1 /= 10;
    } while((tmp1/10) > 100);

    //tmpArr[i + 1] = tmp1 - (tmpArr[1] * 10) + (tmpArr[0] * 100)
    tmpArr[i++] = tmp1 - ((tmpArr[1]*10) + (tmpArr[0]*100));

    //tmp1 = tmp
    tmp1=tmp;

    //while tmp1 / 10 > 0... tmp1 = tmp1 / 10
    do {
        tmp1 /= 10;
    } while((tmp1/10) > 1000);

    //tmpArr[i + 1] = tmp1 - (tmpArr[0] * 1000) + (tmpArr[1] * 100) + (tmpArr[2] * 10)
    tmpArr[i++] = tmp1 - ((tmpArr[0]*1000) + (tmpArr[1]*100) + (tmpArr[2]*10));

    //tmp1 = tmp
    tmp1=tmp;

    //while tmp1 / 10 > 10,000... tmp1 = tmp1 / 10
    do {
        tmp1 /= 10;
    } while((tmp1 / 10) > 10000);
     //tmpArr[i + 1] = tmp1 - (tmpArr[0] * 10000) + (tmpArr[1] * 1000) + (tmpArr[2] * 100) + (tmpArr[3] * 10)
    tmpArr[i++] = tmp1 - ((tmpArr[0]*10000)+(tmpArr[1]*1000)+(tmpArr[2]*100)+(tmpArr[3]*10));

    //while i < 5
    for(i = 0; i < 5; i++) {
        switch(tmpArr[i]) {
            //while tmpArr[i] = 0
            case 0:
                //if tmpArr[i] == 0 retStr = retStr + "11000"
                retStr += "11000";
                break;
            case 1:
                //if tmpArr[i] == 1 retStr = retStr + "00011"
                retStr +="00011";
                break;
            case 2:
                //if tmpArr[i] == 2 retStr = retStr + "00101"
                retStr += "00101";
                break;
            case 3:
                //if tmpArr[i] == 3 retStr = retStr + "00110"
                retStr += "00110";
                break;
            case 4:
                //if tmpArr[i] == 4 retStr = retStr + "01001"
                retStr += "01001";
                break;
            case 5:
                //if tmpArr[i] == 5 retStr = retStr + "01010"
                retStr += "01010";
                break;
            case 6:
                //if tmpArr[i] == 6 retStr = retStr + "01100"
                retStr += "01100";
                break;
            case 7:
                //if tmpArr[i] == 7 retStr = retStr + "10001"
                retStr += "10001";
                break;
            case 8:
                //if tmpArr[i] == 8 retStr = retStr + "10010"
                retStr += "10010";
                break;
            case 9:
                //if tmpArr[i] == 9 retStr = retStr + "10100"
                retStr += "10100";
                break;
        }
    }
    //retStr = retStr + "1"
    retStr = retStr + "1";
    //return retStr
    return retStr;
}

/// this function is of type ZipCode class and it converts from bar to zip
/// this has a passed in parameter of str
/// we return a integer, which is a zipCode we are looing for
int ZipCode::conversion(string str) {
    //set all of your variables you will be using
    int i = 1, retVal = 0, power = 4, increment = 0, myCase = 0, sum = 0;
    
    //while i <= 25
    while (i <= 25) {
        //sum will be zero
        sum = 0;
        //while incrementor is loss than or equal to 4
        while (increment <= 4) {
            //if string[i] is equal to '1'
            if (str[i]=='1') {
                //you want to look for myCase and see if you can pinpoint the corret #
                switch(increment) {
                    case 0:
                        //if increment == 0 myCase = 7
                        myCase = 7;
                        break;
                    case 1:
                        //if increment == 1 myCase = 4
                        myCase = 4;
                        break;
                    case 2:
                        //if increment == 2 myCase = 2
                        myCase = 2;
                        break;
                    case 3:
                        //if increment == 3 myCase = 1
                        myCase = 1;
                        break;
                    case 4:
                        //if increment == 4 myCase = 0
                        myCase = 0;
                        break;
                    default:
                        //if increment == any other #, then myCase = 0
                        myCase = 0;
                }
                //sum = sum + myCase
                sum += myCase;
                
                //check if sum is less than or equal too 10
                if (sum >= 10) {
                    //if so you will reset myCase and sum
                    myCase = 0;
                    sum = 0;
                }
            }
            //increment i and incrementor by 1
            i++;
            increment++;
        }
        //retVal = (sum * 10^(to the x power))
        retVal += (sum * pow(10, power));
        //reset increment and sum to 0 and decrease power
        increment = 0;
        sum = 0;
        power--;
    }
    //them return retVal
    return retVal;
}