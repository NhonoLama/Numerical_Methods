// 0 1 5 1.6 10 3.8 15 8.2 20 15.4
// /x = 17

// 2 1.43 2.5 1.03 3 0.76 3.5 0.6 4 0.48 4.5 0.39
#include <iostream>

using namespace std;

float nb(float x[], float y[], float x1, float y1, int n)
{

    static float s = (x1 - x[n - 1]) / (x[1] - x[0]);
    static int step = 1;

    if (step < n)
    {

        for (int i = 1; i <= n - step; i++)
        {
            y[i - 1] = y[i] - y[i - 1];
        }

        y1 += s * y[n - step - 1];
        step++;
        s *= (s + 1) / float(step);

        return nb(x, y, x1, y1, n);
    }
    return y1;
}

int main()
{
    int n;
    cout << "Enter the number of test cases: ";
    cin >> n;

    float x[n], y[n], x1, y1;

    cout << "Enter x and y coordinates: ";
    for (int i = 0; i < n; i++)
    {
        cin >> x[i] >> y[i];
    }

    cout << "Enter the value : ";
    cin >> x1;

    y1 = y[n - 1];
    cout << "X: " << x1 << " Y: " << nb(x, y, x1, y1, n);

    return 0;
}
