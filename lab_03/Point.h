#ifndef LAB_03_POINT_H
#define LAB_03_POINT_H

#include <cmath>
#include <limits>
#include <iostream>

static bool areDoublesEqual(double a, double b){
    return fabs(a - b) < std::numeric_limits<double>::epsilon();
}

struct Point{
public:
    int x;
    int y;

    friend bool operator ==(Point const &p1, Point const &p2){
        return p1.x == p2.x && p1.y == p2.y;
    }

    friend bool operator <(Point const &p1, Point const &p2) {
        return areDoublesEqual( p1.getAngle(), p2.getAngle() ) ?
            p1.getModule() < p2.getModule() : p1.getAngle() < p2.getAngle();
    }
    
    friend bool operator >(Point const &p1, Point const &p2){
        return areDoublesEqual( p1.getAngle(), p2.getAngle() ) ?
               p1.getModule() > p2.getModule() : p1.getAngle() > p2.getAngle();
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

    int getQuarter() const{
        return this->x >= 0 ? ( this->y >= 0 ? 1: 2 ) : ( this->y >= 0 ? 4: 3 );
    };

    double getModule() const{
        return sqrt(this->x * this->x + this->y * this->y);
    }

    double getAngle() const {
        if(!this->getModule()) return 0;
        Point p1 = {0, 1};
        return acos( p1 * (*this) / (p1.getModule() * (*this).getModule()) );
    }

};

#endif //LAB_03_POINT_H
