#include <iostream>
#include <cmath>
#define e 2.718
using namespace std;

float f(float x){
    return pow(e, -x/2.0);
}

float comTrapezoidal(int l, int u, int n){
    float I, h, x = l;

    h = (u - l)/pow(2, n);
    I = f(x);
    for(int i = 1; i <= pow(2, n) - 1; i++){
        x += h;
        I += (2 * f(x));
    }    
    I += f(u);
    return (h * I)/2.0;
}

float romberg(int row, int col, int l, int u){
    float val;
    if(col == 0){
        val = comTrapezoidal(l, u, row);
    }
    else{
        val =  (pow(4, col) * romberg(row, col -1 , l, u) - romberg(row -1, col -1, l, u))/(pow(4, col) - 1);
    }
    return val;
}

int main(){

    int l, u, row, col;
    cout << "Enter lower bound: ";
    cin >> l;
    cout << "Enter upper bound: ";
    cin >> u;
    cout << "Enter row, col: ";
    cin >> row >> col;

    cout << "R(" << row << ", " << col << ")= "<< round(romberg(row, col, l, u));
    return 0;
}
