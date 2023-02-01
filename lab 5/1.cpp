#include <iostream>

using namespace std;

float F(float x,float y){
    return x + y;
}

void Euler(float x0,float y0, float &x1, float &y1,  float h){
    y1 = 0;
    while(x0 < x1){
        y1 = y0 + h*F(x0, y0);
        y0 = y1;
        x0 += h;
    }
    cout << "Eulers: "<< y1<<"\n";

}

void Heuns(float x0, float y0, float &x1, float &y1, float h){
    y1 = 0;
    float m1, m2;
    while(x0 < x1){
        
        m1 = F(x0,y0);
        m2 = F(x0 + h, y0 + m1 * h);
        y1 = y0 + h*(m1 + m2)/2.0;
        x0 += h;
        y0 = y1; 
        
    }
    cout << "Heuns: "<< y1<<"\n";
}

void Rk(float x0, float y0, float &x1, float &y1, float h){
    y1 = 0;
    float m1, m2, m3, m4;
    while(x0 < x1){
        m1 = F(x0, y0);
        m2 = F(x0 + h/2.0, y0 + m1*h/2.0);
        m3 = F(x0 + h/2.0, y0 + m2*h/2.0);
        m4 = F(x0 + h, y0 + m3 * h);

        y1 = y0 + h*(m1 + 2*(m2 + m3) + m4)/6.0;
        x0 += h;
        y0 = y1;
    }
    cout << "RK: " << y1<<"\n";

}

int main(){
    float x,y, h1, h2, x0, y0;

    x = 0.4;
    h1 = 0.1;
    h2 = 0.2;
    x0 = 0;
    y0 = 1;
    
    cout << "When h = 0.1"<<"\n";
    Euler(x0, y0, x, y, h1);
    Heuns(x0, y0, x, y, h1);
    Rk(x0, y0, x, y, h1);

    cout << "\n"<< "When h = 0.2" <<"\n";
    Euler(x0, y0, x, y, h2);
    Heuns(x0, y0, x, y, h2);
    Rk(x0, y0, x, y, h2);
    return 0;
}
