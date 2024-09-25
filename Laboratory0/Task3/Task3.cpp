#include <iostream>
#include <cmath>

using namespace std;

double GetPower(double base, int exponent)
{
    return pow(base, exponent);
}

void DemoGetPower(double base, int exponent)
{
    cout << base << " ^ " << exponent << " = " << GetPower(base, exponent) << endl;
}

void RoundToTens(int& value)
{
    int remainder = value % 10;
    if (remainder < 5)
    {
        value -= remainder;
    }
    else
    {
        value += 10 - remainder;
    }
}

void subTask1()
{
    cout << "2.0 ^ 4 = " << GetPower(2.0, 4) << endl;
    cout << "4.0 ^ 4 = " << GetPower(4.0, 4) << endl;
    cout << "-3.0 ^ 5 = " << GetPower(-2.0, 5) << endl << endl;

    DemoGetPower(2.0, 4);
    DemoGetPower(4.0, 4);
    DemoGetPower(-2.0, 5);
}

void subTask2()
{
    int a = 14;
    cout << "For " << a << " rounded value is ";
    RoundToTens(a);
    cout << a << endl;

    a = 191;
    cout << "For " << a << " rounded value is ";
    RoundToTens(a);
    cout << a << endl;

    a = 27;
    cout << "For " << a << " rounded value is ";
    RoundToTens(a);
    cout << a << endl;
}

int main()
{
    subTask2();
}
