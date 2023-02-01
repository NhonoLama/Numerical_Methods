#include <iostream>
#include <cmath>
#define e 2.718

using namespace std;

float f(int x){
    return pow(e, -x);
}

float trapeziodal(int l, int u){
    return (u - l) * (f(l) + f(u)) / 2.0;
}

int main(){
    int l, u;

    cout << "Enter the lower and upper bound: ";
    cin >> l>> u;

    cout << "I: "<< trapeziodal(l, u);
    return 0;
}
