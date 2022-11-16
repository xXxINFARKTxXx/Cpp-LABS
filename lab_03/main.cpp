#include <iostream>
#include "MySet.h"
#include "Point.h"

using namespace std;

int main ()
{

    MySet<double> a{ 3.2,2.2,4.2,5.2,6.2 };
    MySet<double> b = new MySet(a);
    MySet<Point> points;
    Point pointArray[5];
    Point toRemove = {1,0};
    Point toAdd = {1,1};

    for(int i = 0, j = 0; i < 5; i++) {
        pointArray[i] = {i,j};
        points.insert(pointArray[i]);
        cout << pointArray[i] << ' ';
    }

    cout << endl;
    cout << points << endl;
    points.erase(toRemove);
    cout << points << endl;
    points.insert(toAdd);
    cout << points << endl;
    cout << a << endl;

    cout << b << endl;

    a.insert(3.8);
    cout << a << endl;

    a.erase(3.2);
    cout << a << endl;


    return 0;
}