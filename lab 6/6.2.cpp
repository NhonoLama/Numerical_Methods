// Solve the equation 
// ?2f = 3x2y
// over the square domain 0 = x = 1.5 and 0 = y = 1.5 with f=0 on the boundary. Take (h=0.5)

#include <iostream>

using namespace std;

float f(float x, float y){
    return (3.0 * x* x * y);
}

void poisson(float x0, float xn, float y0, float yn, float h, float k){
    float f1, f2, f3, f4;
    f1 = f2 = f3 = f4 = 0;

    float error = 1, f1_old;

    while(error > 0.005f){
        f1_old = f1;
        f1 = (f4 + f2 - f(x0 + h, y0 + k))/4.0;
        f2 = (f1 + f3 - f(xn - h, y0 + k))/4.0;
        f3 = (f2 + f4 - f(xn - h, yn - k))/4.0;
        f4 = (f3 + f1 - f(x0 + h, yn - k))/4.0;

        error = (f1 - f1_old)/f1;
        if(error < 0){error *= -1;}

    }
    cout << "F1: "<< f1<< "\n";
    cout << "F2: "<< f2<< "\n";
    cout << "F3: "<< f3<< "\n";
    cout << "F4: "<< f4<< "\n";

}

int main(){
    float x0, y0,xn, yn, h, k;

    x0 = y0 = 0;
    xn = yn = 1.5;
    h = k = 0.5;

    poisson(x0, xn, y0, yn, h, k);

    return 0;
}
//Ans:
// F1: -0.421194
// F2: -0.749507
// F3: -1.07777
// F4: -0.562241
