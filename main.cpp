#include <iostream>
#include <windows.h>
#include <string>
#include <iomanip>
#include <cmath>
#include <exception>
#include <cstdint>

using namespace std;

//Task 1.1----------------------------------

template <typename T>
T div(T a, T b){
    if(b == 0){
        throw "DivisionByZero";
    }
    return a/b;
}
//Task 2.1----------------------------------

class Ex
{
public:
    double x;

    Ex(double n_x) : x(n_x){}
    ~Ex(){}
};

class Bar{
private:
    double y;

public:
    Bar(){
        y = 0;
    }
    ~Bar(){}

    void set_n(double a)
    {
        if(y + a <= 100)
        {
            y = a;

        } else throw Ex(y*a);
    }

};
//-------------------------------------------


int main()
{
//Task 1.1---------------------------------

    cout << "Enter a first number: ";
    double a;
    cin >> a;

    cout << "\n";
    cout << "Enter a second number: ";
    double b;
    cin >> b;

    try{
        double d = div(a, b);
        cout << a << " / " << b <<" is " << d << '\n';
    }
    catch(const char* exception){
        cerr << "Error: " << exception << endl;
    }

//Task 2.2-----------------------------------

    Bar bar;
    int x = 1;
    while(x != 0){
        cin >> x;
        try
        {
            bar.set_n(x);
        }
        catch(Ex &err)
        {
            cerr << "Exception: ay " << err.x <<std::endl;
        }
    }
    system ("Pause");
    return 0;
}
