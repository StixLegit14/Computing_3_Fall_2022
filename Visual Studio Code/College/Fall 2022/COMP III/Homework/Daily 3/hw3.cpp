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
Date: 09/19/22
Purpose: Create a class "Point" and modify it to move the point
Sources of Help: None
Time Spent: 30 min
***********************************************/

#include <iostream>

using namespace std;

class Point {
public:
    void setX(int valueX);
    void setY(int valueY);

    void shift(int shiftX, int shiftY);

    void turn90(void);

    int getX(void);
    int getY(void);
private:
    int x;
    int y;

};

int main (int argc, char * argv[]) {

    //Case 1
    //create object of class point
    Point c1;
    int c1X;
    int c1Y;

    //set memeber variables to 1 and 2
    c1.setX(1);
    c1.setY(2);

    //display
    cout << "The start destination for case 1 is: (" << c1.getX() << "," << c1.getY() << ")" << endl; 

    //call the function to rotate 90 degrees
    c1.turn90();

    //output new values for x and y
    cout << "The final destination for case 1 is: (" << c1.getX() << "," << c1.getY() << ")" << endl << endl;

    //Case 2
    //create another object of type point
    Point c2;
    int c2X;
    int c2Y;

    //set member variables to 3 and 4
    c2.setX(3);
    c2.setY(4);

    //output x and y
    cout << "The start destination for case 2 is: (" << c2.getX() << "," << c2.getY() << ")" << endl;

    //shift the points by 1 and 1
    c2.shift(1, 1);

    //display the new points to the screen
    cout << "The final destination for case 2 is: (" << c2.getX() << "," << c2.getY() << ")" << endl << endl;

    //Case 3
    //create yet another objct of type point
    Point c3;
    int c3X;
    int c3Y;

    //set x and y to 5 and -4 respectfully
    c3.setX(5);
    c3.setY(-4);

    //output x and y initial values
    cout << "The start destination for case 3 is: (" << c3.getX() << "," << c3.getY() << ")" << endl;

    //call another shift to change/shift the values
    c3.shift(-5, 4);

    //diplay the new values
    cout << "The final destination for case 3 is: (" << c3.getX() << "," << c3.getY() << ")" << endl << endl;

    //end program
    return 0;
}

//getter function for x
int Point::getX(void) {
    return x;
}

//getter function for y
int Point::getY(void) {
    return y;
}

//setter function for x
void Point::setX(int valueX) {
    x = valueX;
}

//setter function for y
void Point::setY(int valueY) {
    y = valueY;
}

//turn 90 degrees function
void Point::turn90(void) {
    //while you are in the first quadrent, and 
    for (int i = 0; i != 4; i++) {
        switch(i) {
            //if i == 0
            case 0:
                //set the x value to a negative(or positive if the original value was negative)... you entered a new quadrant
                x *= -1;
                //output
                cout << "Current point on iteration: " << i << " displays destination to be: (" << getX() << "," << getY() << ")" << endl;
                break;
            case 1:
                //set the y value to a negative(or positive if the original value was negative)... you entered a new quadrant
                y *= -1;
                //output
                cout << "Current point on iteration: " << i << " displays destination to be: (" << getX() << "," << getY() << ")" << endl;
                break;
            case 2:
                //set the x value to a positive(or negative if the original value was negative)... you entered a new quadrant
                x *= -1;
                //output
                cout << "Current point on iteration: " << i << " displays destination to be: (" << getX() << "," << getY() << ")" << endl;
                break;
            case 3:
                //set the y value to a positive(or negative if the original value was negative)... you entered a new quadrant
                y *= -1;
                //output
                cout << "Current point on iteration: " << i << " displays destination to be: (" << getX() << "," << getY() << ")" << endl;
                break;
        }
    }
}

//shift function
void Point::shift(int shiftX, int shiftY) {
    //add the given value shiftX to the member function x
    x += shiftX;
    //add the given value shiftY to the member function y
    y += shiftY;
}