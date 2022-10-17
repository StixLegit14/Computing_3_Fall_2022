#include <iostream>

using namespace std;

int NWD(int m1,int m2);

int main (int argc, char * argv[]) {

    int num = 12;
    int den = 6;
    int d = NWD(num,den);
    cout << num << endl;
    cout << den << endl;
    if (den == 1) {
        cout << num/d <<endl;
    } else {
        cout << num/d << '/' << den/d << endl;
    }
    
    return 0;

}

int NWD(int m1,int m2){
    while((m1!=0)&&(m2!=0)){
        if(m1>=m2) {
            m1=m1%m2;
        } else {
            m2=m2%m1;
        }
    }
    return m1+m2;
}