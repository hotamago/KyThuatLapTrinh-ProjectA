#pragma once
#include <iostream>
#include "../funplus/String.h"
using namespace std;

namespace entity
{
    class Point
    {
    public:
        double x, y;
        Point(double x, double y)
        {
            this->x = x;
            this->y = y;
        }
        Point(string xy)
        {
            vector<string> xySplit = funplus::String::split(xy, ",");
            this->x = atof(xySplit[0].c_str());
            this->y = atof(xySplit[1].c_str());
        }
        bool equals(Point *p)
        {
            return (this->x == p->x && this->y == p->y);
        }
        friend ostream &operator<<(std::ostream &out, Point &p)
        {
            out << p.x << "," << p.y;
            return out;
        }
    };
}