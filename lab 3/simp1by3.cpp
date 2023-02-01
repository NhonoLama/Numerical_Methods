#include <iostream>
#include <cmath>
#define e 2.718

using namespace std;

float f(int x){
    return pow(e, -x);
}

float simpson(int l, int u){
    float h = (u -l)/2.0;
    return h * (f(l) + 4 * f(l + h) + f(u))/3.0;
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
