#include <iostream>
#include <cmath>
#define e 2.718

using namespace std;

float f(int x){
    return pow(e, -x);
}

float comSimpson(int l, int u, int n){
    float h = (u -l)/n;
    float I;
    int x = l;
    I = f(l);

    for(int i = 1; i < n; i++){
        x += h;
        if(i % 2 == 0){
            I += 2 * f(x);
        }
        else{
            I += 4 * f(x);
        }
    }
    I += f(u);

    return (h * I)/3.0;

}

int main(){
    int l, u, n;

    cout << "Enter lower bound: ";
    cin >> l;
    cout << "Enter upper bound: ";
    cin >> u;
    cout << "Enter the number of divisions: ";
    cin >> n;
    cout << "I: "<< comSimpson(l, u, n);

    return 0;
}
