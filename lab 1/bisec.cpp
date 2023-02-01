// should include initial guess

#include <iostream>
#include <iomanip>

using namespace std;

float x_lower, x_upper, x_mid_new, x_mid_old;
int a, b, c, d;
static int i;

/*___defination of function___*/
float f(float x)
{
    return a * (x * x * x) + b * (x * x) + c * x + d;
}

void make_limit()
{
    if (f(x_mid_new) > 0)
    {
        x_upper = x_mid_new;
    }
    else
    {
        x_lower = x_mid_new;
    }
}

float find_error()
{
    float error = (x_mid_new - x_mid_old) / x_mid_new;
    if (error < 0)
    {
        error *= -1;
    }
    return error;
}
//___main bisection method
void bisection()
{

    float error = 1;

    while (error >= 0.005f)
    {
        i++;
        x_mid_old = x_mid_new;
        x_mid_new = (x_lower + x_upper) / 2.0;

        error = find_error();
        make_limit();
    }

    return;
}

int main()
{

    cout << "Enter the values of a, b, c and d: ";
    cin >> a >> b >> c >> d;

    // inital guess such that f(x1) and f(x2) are of opposite signs:
    do
    {
        cout << "Enter initial guess: ";
        cin >> x_lower >> x_upper;
    } while (f(x_lower) * f(x_upper) > 0);

    bisection();
    cout << "Root is: " << x_mid_new << "\n";
    cout << "Functional value: " << f(x_mid_new) << "\n";
    cout << "Iterations: " << i;

    return 0;
}
