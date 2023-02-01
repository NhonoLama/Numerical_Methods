#include <iostream>
#include <math.h>

/**
        derivative using approximation
        foward differential method
        f'(x) = f(approx) - f(x) / (approx - x)
        where approx > x
**/

int a, b, c, d;
static int i;

float f(float x)
{
    return a * (x * x * x) + b * (x * x) + c * x + d;
    // return  sinf(x) - 5 * x + 6;
}

float fd(float x)
{
    float approx = x + 0.001;
    float rslt = (f(approx) - f(x)) / (approx - x);
    return rslt;
}

void newton_rapson(float *x)
{

    float new_x = *x - f(*x) / fd(*x);

    float error = abs((new_x - *x) / new_x);

    // setting old value with new value
    *x = new_x;

    if (error >= 0.005f)
    {
        // feeding the new value again to func
        i++;
        newton_rapson(x);
    }
    return;
}

int main()
{

    float guess;
    std::cout << "Enter a, b, c, and d: ";
    std::cin >> a >> b >> c >> d;
    std::cout << "Enter a inital guess: ";
    std::cin >> guess;
    newton_rapson(&guess);
    std::cout << "root is: " << guess << "\n";
    std::cout << "Functional value: " << f(guess) << "\n";
    std::cout << "Iterations: " << i;
}
