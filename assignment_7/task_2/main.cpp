#include <iostream>
#include "set.hpp"

using namespace std;

int main() {


    Set a({5,8,3,8,0,3,5,7,1,11,88});
    Set b({1,1,5,7,9,3,7,9,3,2,3,2});
    Set c({1,2,3,4,5,6});
    Set d({7,5,9,4,8,6});
    Set e({4,5,6,7,8,9});
    Set f({1,2,3,4,5,6});
    Set g({7,5,9,4,8,6});
    Set h;

    cout << "b - " << b << endl;
    b += 9;
    b += 6;
    cout << "b += 9 and b += 6: " << b << endl;

    cout << endl;

    cout << "c - " << c << endl;
    cout << "d - " << d << endl;
    c += d;
    cout << "c += d: " << c << endl;

    cout << endl;

    cout << "d - " << d << endl;
    cout << "e - " << e << endl;
    if (e == d)
        cout << "e == d: true" << endl;
    else
        cout << "e == d: false" << endl;

    cout << endl;

    cout << "a - " << a << endl;
    cout << "b - " << b << endl;
    b = a;
    cout << "b = a: " << b << endl;

    cout << endl;

    cout << "h - " << h << endl;
    cout << "f - " << f << endl;
    cout << "g - " << g << endl;
    h = f + g;
    cout << "h = f + g: " << h << endl;

    return 0;
}
