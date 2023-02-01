//Write a program to calculate derivative from divided difference table 

#include <iostream>
#include <cmath>

using namespace std;

float ds(int n, float val, float x0, float h){
    // central difference
    float dx = 0.0001, fx1 = 1, fx0 = 1, div = 1;

    if(n <= 0){
        return 0;
    }

    //dy/dx = f(x + dx) - f(x - dx) / 2dx;
    for(int i = 0; i < n; i++){
        float s = (val - x0)/h;
        fx1 *= (s + dx) - i;
        fx0 *= (s - dx) - i;
        div *= (n - i);
    }
    // cout << (fx1 - fx0)/(2 * dx) <<"\n";
    return (fx1 - fx0)/(div *2 * dx);
}

float fowardDiff(int n, float x1, float x[], float y[]){
    
    float yval = 0;
    static int step = 1;

    while(step < n){
        for(int i = 1; i <= n - step; i++){
            y[i - 1] = y[i] - y[i - 1];
        }
        yval += y[0] * ds(step, x1, x[0], x[1] - x[0]);
        step++;
    }
    return yval/(x[1] - x[0]);
}

int main(){
    int n;
    cout << "Enter the number of test cases: ";
    cin >> n;

    float x[n], y[n], x1;

    cout << "Enter x and y coordinates: ";
    for (int i = 0; i < n; i++)
    {
        cin >> x[i] ;
    }

    for (int i = 0; i < n; i++)
    {
        cin >> y[i] ;
    }
    cout << "Enter the value : ";
    cin >> x1;

    cout << fowardDiff(n, x1, x, y);
    return 0;
}
