#include <iostream>
#include <cmath>
#define e 2.718

using namespace std;

float f(int x){
    return pow(e, -x);
}

float simpson(int l, int u, int n){
    float h = (u -l)/n;
    float I = f(l) + f(u);
    int x = l;
    for(int i = 1; i < n; i++){
        x += h;
        if(i % 3 == 0){
            I += 2 * f(x);
        }
        else{
            I += 3 * f(x);
        }
    }
    return 3 *(h * I)/8.0;
    
}

int main(){
    int l, u, n;

    cout << "Enter lower bound: ";
    cin >> l;
    cout << "Enter upper bound: ";
    cin >> u;
    cout << "Enter the number of divisions: ";
    cin >> n;

    cout << "I: "<< simpson(l, u, n);

    return 0;
}
