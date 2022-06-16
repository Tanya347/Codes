#include <iostream>
using namespace std;

class Fraction
{
private:
    int num;
    int den;
    void simplify();

public:
    Fraction(int num, int den)
    {
        this->num = num;
        this->den = den;
    }

    void print()
    {
        cout << num << "/" << den << endl;
    }

    void add(Fraction const &);
    void multiply(Fraction const &);
};

// copy contructor is being called and value of main's f2 is being copied
// into the locally created object f2 of the function
// void Fraction ::add(Fraction f2)

// hence we pass a reference no new memory is created f2 will point to the original memory itself
// but to avoid any unwanted changes to f2 we make it constant
void Fraction ::add(Fraction const &f2)
{
    int lcm = den * f2.den;
    int x = lcm / den;
    int y = lcm / f2.den;
    int n = x * num + (y * f2.num);
    num = n;
    den = lcm;
    // we don't need to call an object here as it will implicitly take
    // the object that this points i.e f1
    simplify();
}

void Fraction ::simplify()
{
    int gcd = 1;
    int j = min(num, den);
    for (int i = 1; i <= j; i++)
    {
        if (num % i == 0 && den % i == 0)
            gcd = i;
    }
    num = num / gcd;
    den = den / gcd;
}

void Fraction ::multiply(Fraction const &f2)
{
    num = num * f2.num;
    den = den * f2.den;

    simplify();
}

int main()
{
    Fraction f1(10, 2);
    f1.print();
    Fraction f2(15, 4);
    f2.print();
    f1.add(f2);
    f1.print();
    f2.multiply(f1);
    f2.print();
}
