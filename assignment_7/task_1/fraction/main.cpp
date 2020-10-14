#include "fraction.hpp"
#include <iostream>
#include <string>

using namespace std;

void print(const string &text, const Fraction &broek) {
  cout << text << broek.numerator << " / " << broek.denominator << endl;
}


int main() {
  Fraction a(1, 2);
  Fraction b(1, 2);
  Fraction c(1, 2);
// Fraction d = a / b;


  print("a = ", a);
  print("b = ", b);
  print("c = ", c);
// print("d = ", d);

//  b += a;
//  ++c;
//  d *= d;

  cout << endl;
  b = 1 + a;
  c = a + 1;

  print("b = ", b);
  print("c = ", c);

  b = 2 - a;
  c = a - 2;

  print("b = ", b);
  print("c = ", c);
//  print("d = ", d);
//
//  c = a + b - d * a;
//  c = -c;
//
//  print("c = ", c);
//
//  if (a + b != c + d)
//    cout << "a + b != c + d" << endl;
//  else
//    cout << " a + b == c + d" << endl;
//  while (b > a)
//    b -= a;
//  print("b = ", b);
//
}
