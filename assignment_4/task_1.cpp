#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    vector<double> vec { 1.1, 2.2, 3.3, 4.4, 5.5 };

    cout << "Front: " << vec.front() << endl;
    cout << "Back: " << vec.back() << endl;

    vec.emplace(vec.begin() + 1, 0.1);

    cout << "Front after emplace: " << vec.front() << endl;
    cout << "Front after emplace: " << vec.front() << endl;


    cout << "Front after emplace: " << vec.front() << endl;

    double find_val = 2.2;
    auto res = find(vec.begin(), vec.end(), find_val);
    if (res != vec.end()) {
        cout << find_val << " is in the vector" << endl;
    } else {
        cout << find_val << " is not in the vector" << endl;
    }

    cout << "\nAll elements in array: " << endl;
    for (double e : vec) {
        cout << e << endl;
    }

    return 0;
}
