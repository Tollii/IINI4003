#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {

	const int length = 5;

	int higher = 0;
	int lower = 0;
	int between = 0;

	for (size_t i = 0; i < length; i++) {

		double temperature;
		cout << "Enter temperature #" << i + 1<< ": "; cin >> temperature;

		if (temperature < 10) {
			lower++;
		} else if (temperature > 20 && temperature < 10) {
			between++;
		} else {
			higher++;
		}
	}

	cout << lower << " above 10" << endl;
	cout << between << " between 10 and 20" << endl;
	cout << higher << " above 20" << endl;

}
