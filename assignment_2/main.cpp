#include <iostream>

using namespace std;

int find_sum(const int *table, int length);


int main() {

    // 1a -------------------
    cout << "Oppgave 1a ---" << endl;

    int i = 3;
    int j = 5;
    int *p = &i; // i, 3
    int *q = &j; // j, 5

    cout << "j val: " << *q << endl;
    cout << "i val: " << *p << endl;
    cout << "i addr: " << q << endl;
    cout << "j addr: " << p << endl;

    // 1b --------------------
    cout << endl << "Oppgave 1b ---" << endl;
    *p = 7; // i = 7
    *q += 4; // j = 9
    *q = *p + 1; // j = 8
    p = q; // i

    cout << "p: " << *p << endl; // 8
    cout << "q: " << *q << endl; // 8


    // Oppgave 4 -------------
    cout << endl << "Oppgave 4 ---" << endl;

    int a = 5;
    int &b = a; // Ikke initialisert
    int *c;
    c = &b;
    a = b + *c; // 'a' er ikke en peker, trenger ikke '*'. 'b' er en referanse, trenger ikke dereferere den
    b = 2; // Kan ikke sette en peker til en primitiv datatype. Må peke til en annen variabel

    cout << "a " << a << endl;
    cout << "b " << b << endl;
    cout << "c " << c << endl;

    // Oppgave 5 --------------
    cout << endl << "Oppgave 5 ---" << endl;

    double number;
    double *pointer = &number; // 'pointer' peker til 'number' sin adresse
    double &ref = number; // 'ref' refererer til number

    number = 1.0;
    cout << "num " << number << endl; // 1.0

    ref = 2.0;
    cout << "num " << number << endl; // 2.0

    *pointer = 3.0;
    cout << "num " << number << endl; // 3.0



    // Opgave 6 -----------
    cout << endl << "Oppgave 6 ---" << endl;

    int length = 20;

    int table[length];

    for (size_t x = 0; x < length; x++) {
        table[x] = length - x;
    }


    int sum = find_sum(&table[0], 10); // 10 første
    cout << "Sum: " << sum << endl;

    sum = find_sum(&table[10], 5); // 5 neste
    cout << "Sum: " << sum << endl;

    sum = find_sum(&table[length - 5], 5); // 5 siste
    cout << "Sum: " << sum << endl;

    return 0;
}

/*
 * Oppgave 2
 *
 * Programmet vil prøve å skrive over minneadresser den ikke har blitt allokert.
 */

/*
 * Oppgave 3
 *
 * Brukeren kan skrive ord lenger enn 4 tegn.
 *
 * Loopen stopper aldri hvis tegnet i search_for ikke er i tabellen. Da leser loopen bare minneadressene videre
 */


int find_sum(const int *table, int length) {

    int sum = 0;
    for (size_t i = 0; i < length; i++) {
        sum += table[i];
    }

    return sum;
}