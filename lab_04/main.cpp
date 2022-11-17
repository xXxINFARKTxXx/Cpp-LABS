#include <iostream>
#include "IntSet.h"
using namespace std;

int main() {
    int arr[] = { 1,2,3,4,5,6 };
    IntSet b = IntSet(6, arr);
    IntSet c = b;
    cout << "b = " << b << endl;
    cout << "c = " << c << endl;

    IntSet a = IntSet{ 1,2,3,4,5,6 };
    cout << "a = " << a << endl;
    a += 7;
    cout << "a = " << a << endl;
    a -= 7;
    cout << "a = " << a << endl;
    a -= 1;
    cout << "a = " << a << endl;
    cout << endl;

    IntSet set1{ 1,2,3 };
    IntSet set2{ 2,3,4 };
    cout << "set1 = " << set1 << endl;
    cout << "set2 = " << set2 << endl;
    cout << "set1 * set2 = " << set1 * set2 << endl;
    cout << "set1 + set2 = " << set1 + set2 << endl;
    cout << "set1 - set2 = " << set1 - set2 << endl;
    cout << "set2 - set1 = " << set2 - set1 << endl << endl;

    IntSet set3{ 1,2,3,4 };
    IntSet set4{ 3,4 };
    cout << "set3 = " << set3 << endl;
    cout << "set4 = " << set4 << endl;
    cout << "set3 < set4 = " << (set3 < set4) << endl;
    cout << "set3 > set4 = " << (set3 > set4) << endl;
    cout << "set3 <= set4 = " << (set3 <= set4) << endl;
    cout << "set3 >= set4 = " << (set3 >= set4) << endl;
    return 0;
}
