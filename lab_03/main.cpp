#include <iostream>
#include <set>
#include "Set.h"

#include "Point.h"

using namespace std;

template <typename T>
void print(const set<T> a) {
    for(auto it = a.begin(); it != a.end(); it++)
        cout << *it;
    cout << endl;
}

int main ()
{
//    set<int> a;
//    set<int> b{ 1,2,3,4 };
//    set<int> c = { 1,2,2,2,3 };
//    set<int> d = c;
//
////    print(a);
//    print(b);
//    print(c);
//    print(d);

    MySet<int> a;
    a = { 1,2,3,4,5 };
    delete a;
    return 0;
}