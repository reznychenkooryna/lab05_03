#include <iostream> 
#include <cmath> 

using namespace std;

double f(const double x);

int main()
{
    double tp, tk, z;
    int n;

    cout << "tp = "; cin >> tp;
    cout << "tk = "; cin >> tk;
    cout << "n  = "; cin >> n;

    double dg = (tk - tp) / n;

    double t = tp;

    while (t <= tk)
    {
        z = f(1 + 2 * t) + pow(f(f(1) + 2 * f(2 * t)), 2);
        cout << t << "  " << z << endl;
        t += dg;
    }

    return 0;
}

double f(const double x)
{
    if (abs(x) >= 1)
        return (pow(sin(x), 2) + sin(pow(x, 2))) / (1 + pow(cos(x), 2));
    else
    {
        double S = 0;
        int n = 0;
        double a = 1;
        S = a;
        do
        {
            n++;
            double R = pow(x, 4 * n + 1) / ((4 * n + 1) * (4 * n) * (4 * n - 1) * (4 * n - 2));
            a *= R;
            S += a;
        } while (n < 6);
        return S / (1 + x * x);
    }
}
