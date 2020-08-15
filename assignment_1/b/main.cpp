#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;

void read_temperatures(double temperatures[], int length);

int main(int argc, char *argv[]) {

    int length = 8;

    int higher = 0;
    int between = 0;
    int lower = 0;

    double temperatures[length];
    read_temperatures(temperatures, length);

    for (const double &temp : temperatures) {

        if (temp < 10) {
            lower++;
        } else if (temp < 20 && temp > 10) {
            between++;
        } else {
            higher++;
        }

    }

    cout << lower << " below 10" << endl;
    cout << between << " between 10 and 20" << endl;
    cout << higher << " above 20" << endl;
}

void read_temperatures(double temperatures[], int length) {

    const char filename[] = "../temp.txt";
    ifstream file;
    file.open(filename);

    if (!file) {
        cout << "Error opening file..." << endl;
        exit(EXIT_FAILURE);
    }

    int counter = 0;
    double temp;
    while (file >> temp || counter < length) {
        temperatures[counter] = temp;
        counter++;
    }
    cout << "Closing file..." << endl;
    file.close();
}