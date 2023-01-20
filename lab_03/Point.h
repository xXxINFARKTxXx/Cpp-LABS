#pragma once
#include <cmath>
#include <limits>

#define EPS (numeric_limits<double>::epsilon())

template <typename T>
struct Point{
public:
    T x;
    T y;

    friend bool operator ==(Point const &p1, Point const &p2){
        return fabs(p1.x - p2.x) < EPS && fabs(p1.y - p2.y) < EPS;
    }

    friend bool operator <(Point const &p1, Point const &p2) {
        return p1 == p2 ? p1.y < p2.y : p1.x < p2.x;
    }

    friend bool operator >(Point const &p1, Point const &p2){
        return p1 == p2 ? p1.y > p2.y : p1.x > p2.x;
    }

    friend bool operator <=(Point const &p1, Point const &p2){
        return p1 == p2 || p1 < p2;
    }

    friend bool operator >=(Point const &p1, Point const &p2){
        return p1 == p2 || p1 > p2;
    }

    friend int operator *(Point const &p1, Point const &p2){
        return p1.x * p2.x + p1.y * p2.y;
    }

    friend std::ostream& operator<< (std::ostream &out, const Point &p){
        out << "{" << p.x << ", " << p.y << "}";
        return out;
    }

private:
};

