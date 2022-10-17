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
Date: 09/11/22
Name: Matthew Flores
*/
/***********************************************
Author: Matthew Flores
Date: 09/14/22
Purpose: Read file and replace "dislike" with "love"
Sources of Help: None
Time Spent: 30-45 minutes
***********************************************/

#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;

int main (int argc, char * argv[]) {

    string after_str;

    //make file pointer
    ifstream fp;

    //open input.txt
    fp.open("input.txt");
    
    //check if opening file failed
    if (fp.fail()) {
        cout << "File failed to open!" << endl;
        exit(1);
    }

    cout << "The file 'input.txt' after modifications states the following: ";

    //while we are not at the end of file
    while (!fp.eof()) {
        //read in the file
        fp >> after_str;

        //check for the word "dislike"
        if (after_str == "dislike") {
            //replace with "like"
            after_str = "like";
        }

        //print it out with spaces
        cout << after_str << " ";
        
    }

    //close file
    fp.close();
    

    return 0;
}