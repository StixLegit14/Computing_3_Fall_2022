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
Date: 10/11/22
Name: Matthew Flores
*/
/***********************************************
Author: Matthew Flores
Date: 10/11/22
Purpose: This assignment asks you to create a class called DynamicStringArray that includes
member functions that allow it to emulate the behavior of a vector of strings.
Sources of Help: geeksforgeeks and programiz.
Time Spent: 3 hours
***********************************************/

#include <iostream>
#include <cstring>

using namespace std;

/* @brief One problem with dynamic arrays is that once the array is created using the new operator the size
cannot be changed. For example, you might want to add or delete entries from the array similar to the
behavior of a vector. This assignment asks you to create a class called DynamicStringArray that includes
member functions that allow it to emulate the behavior of a vector of strings.
*/
class DynamicStringArray {
public:
    //A default constructor that sets the dynamic array to nullptr and sets size to 0.
    DynamicStringArray();

    //A function that returns size.
    int getSize(void);

    /*
    A function named addEntry that takes a string as input. The function should create a new
    dynamic array one element larger than dynamicArray, copy all elements from dynamicArray into
    the new array, add the new string onto the end of the new array, increment size, delete the old
    dynamicArray, and then set dynamicArray to the new array.
    */
    void addEntry(string);

    /*
    A function named deleteEntry that takes a string as input. The function should search
    dynamicArray for the string. If not found, it returns false. If found, it creates a new dynamic
    array one element smaller than dynamicArray. It should copy all elements except the input
    string into the new array, delete dynamicArray, decrement size, and return true.
    */
    void deleteEntry(string);

    /*
    A function named getEntry that takes an integer as input and returns a pointer that references 
    to the string at that index in dynamicArray. It should return nullptr if the index is out of
    dynamicArray’s bounds.
    */
    string getEntry(int);

    //A copy constructor that makes a copy of the input object’s dynamic array.
    DynamicStringArray(const DynamicStringArray& obj);

    //Overload the copy assignment operator so that the dynamic array is properly copied to the target object.
    DynamicStringArray& operator=(const DynamicStringArray& obj);

    //A destructor that frees up the memory allocated to the dynamic array
    ~DynamicStringArray();

private:
    //A private member variable called dynamicArray that references a dynamic array of type string
    string* dynamicArray;

    //A private member variable called size that holds the number of entries in the array.
    int size;
};

const bool operator==(const DynamicStringArray &obj1, const DynamicStringArray &obj2);
ostream& operator<<(ostream &outstream, DynamicStringArray &right);

int main (int argc, char * argv[]) {

    string ex1 = "Live", ex2 = "To", ex3 = "Sing", ex4 = "With", ex5 = "Me";

    DynamicStringArray myStrObj;

    myStrObj.addEntry(ex1);

    cout << "Size is: " << myStrObj.getSize() << endl;

    return 0;
}

DynamicStringArray::DynamicStringArray() {
    dynamicArray = nullptr;
    size = 0;
}

int DynamicStringArray::getSize(void) {
    return size;
}

void DynamicStringArray::addEntry(string tmpStr) {

    cout << "Made it!" << endl;

    //dynamicArray[0] = tmpStr;

    size += 1;
}

void DynamicStringArray::deleteEntry(string) {

}
/*
string DynamicStringArray::getEntry(int) {
    return dynamicArray;
}
*/

DynamicStringArray::DynamicStringArray(const DynamicStringArray& obj) {
    dynamicArray = new string;
    *dynamicArray = *obj.dynamicArray;
}
/*
DynamicStringArray& DynamicStringArray::operator=(const DynamicStringArray& obj) {
    delete this->dynamicArray;
    this->dynamicArray = new string;
    *dynamicArray = *obj.dynamicArray;
}
*/
DynamicStringArray::~DynamicStringArray() {
    //cout << "Destructor is active!" << endl;

    delete[] dynamicArray;
    dynamicArray = nullptr;

    //cout << "Destructor is finished!" << endl;
}

//checks if the passed in DynamicStringArray type is equal too one another
const bool operator==(const DynamicStringArray &obj1, const DynamicStringArray &obj2) {
   return obj1 == obj2;
}

//overloader for cout
ostream& operator<<(ostream &outstream, DynamicStringArray &right) {
    outstream << right.getSize() << endl;
    return outstream;
}