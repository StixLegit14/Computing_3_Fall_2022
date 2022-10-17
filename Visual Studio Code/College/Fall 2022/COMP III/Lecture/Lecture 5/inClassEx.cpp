#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;

const int MAX_NUM_DIE = 2;

int main (int argc, char * argv[]) {
    int num;
    int array[MAX_NUM_DIE];

    ifstream fp;
    fp.open("/Users/matthewflores/C++/COMP III/Lecture 5/file.txt");
    
    if (fp.fail()) {
        cout << "File failed to open!" << endl;
        exit(1);
    }

    fp >> num;

    cout << "There are: " << num << " dice!" << endl;

    /*
    for (int i = 0; i < 5; i++) {
        fp >> array[i];
        cout << "Dice value: " << array[i] << endl;
    }
    

    while (fp >> array[i]) {
        cout << "Dice value: " << array[i] << endl;
    }
    */
    fp.close();

    return 0;
}