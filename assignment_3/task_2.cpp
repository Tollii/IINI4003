#include <iostream>

using namespace std;

int main() {
	Circle circle(5);

  double area = circle.get_area();
  cout << "Arealet er lik " << endl;

  double circumference = circle.get_circumference();
  cout << "Omkretsen er lik " << circumference << endl;
}
