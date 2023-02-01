#include <iostream>
#include <cmath>

using namespace std;

float f(float  x){
    return pow(x+3, 4) + 1;
}

float twoPoint(){
    float x1, x2, w1, w2;
    x1 = -1.0/sqrt(3);
    x2 = -x1;
    w1 = w2 = 1;

    return (w1 * f(x1) + w2 * f(x2));
}

float threePoint(){
    float x1, x2, x3, w1, w2, w3;
    x1 = -sqrt(3.0/5.0);
    x3 = -x1;
    x2 = 0;
    w1 = w3 = 5.0/9.0;
    w2 = 8.0/9.0;

    return (w1 * f(x1) + w2 * f(x2) + w3 * f(x3));

}

int main(){
    

    cout << "I [Two point]: " << twoPoint()<< "\nI [three point]: "<< threePoint();
    return 0;
}
