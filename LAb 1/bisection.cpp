//should include initial guess

#include <iostream>
#include <iomanip>

using namespace std;

float x_lower, x_upper, x_mid_new, x_mid_old;
int a, b, c, d;

/*___defination of function___*/
float f(float x){
    return a * (x*x*x) + b* (x*x) + c*x+ d;
}

void make_limit(){  
    if(f(x_mid_new) > 0){
        x_upper = x_mid_new;
    }
    else{
        x_lower = x_mid_new;
    }
}

float find_error(){
    float error = abs(x_mid_new - x_mid_old) /x_mid_new;
    return error;
}
//___main bisection method
void bisection(){

    float error = 1;

    while(error >= 0.005){       
        x_mid_old = x_mid_new;
        x_mid_new = (x_lower + x_upper) / 2.0;

        error = find_error();
        //display values
        cout << setw(15) << x_lower << setw(15) << f(x_lower) << setw(15) << x_upper << setw(15) << f(x_upper)
        <<setw(15)<<x_mid_new<<setw(15)<<f(x_mid_new)<< setw(15)<< error << "\n";
        
        make_limit();
    }

    return;

}

int main(){

    cout << "Enter the values of a, b, c and d: ";
    cin >> a >> b >> c >> d;
    
    // inital guess such that f(x1) and f(x2) are of opposite signs:
    do{
        cout << "Enter initial guess: ";
        cin >> x_lower >> x_upper;
    }while(f(x_lower) * f(x_upper) > 0);


    cout << setw(15) <<"xl"<< setw(15)<<"f(xl)"<<setw(15)<<"xu"<<setw(15)<<"f(xu)"<<setw(15)<<"xm"<<setw(15)<<"f(xm)"<<setw(15)<<"error" <<"\n";

    bisection();
    cout << setw(15) << "Root is: "<< x_mid_new <<"\n";
    return 0;
}
