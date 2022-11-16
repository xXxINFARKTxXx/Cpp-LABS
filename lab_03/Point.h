#pragma once

#include <iostream>

struct Point{
public:
    int x;
    int y;

    friend bool operator ==(Point const &p1, Point const &p2){
        return p1.x == p2.x && p1.y == p2.y;
    }

    friend bool operator <(Point const &p1, Point const &p2) {
        return p1.x == p2.x ? p1.y < p2.y : p1.x < p2.x;
    }
    
    friend bool operator >(Point const &p1, Point const &p2){
        return p1.x == p2.x ? p1.y > p2.y : p1.x > p2.x;
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

