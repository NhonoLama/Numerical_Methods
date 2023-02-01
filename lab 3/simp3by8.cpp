#include <iostream>
#include <cmath>
#define e 2.718

using namespace std;

float f(int x){
    return pow(e, -x);
}

float simpson(int l, int u){
    float h = (u -l)/3.0;
    return 3 * h * (f(l) + 3* f(l + h) + 3 * f(l + 2*h) + f(u))/8.0;
}

int main(){
    int l, u;

    cout << "Enter lower bound: ";
    cin >> l;
    cout << "Enter upper bound: ";
    cin >> u;

    cout << "I: "<< simpson(l, u);

    return 0;
}
