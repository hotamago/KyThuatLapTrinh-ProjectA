#pragma once
#include <string>
#include "Point.h"
#include <iostream>
using namespace std;

namespace entity
{
    class Shape
    {
    public:
        Point *start;
        Point *end;
        double d;
        std::string name;
        Shape(Point *start, Point *end, double d, std::string name)
        {
            this->start = start;
            this->end = end;
            this->d = d;
            this->name = name;
        }
        bool equals(Shape *s)
        {
            return (this->start->equals(s->start) && this->end->equals(s->end));
        }
        friend ostream &operator<<(std::ostream &out, Shape &s)
        {
            out << *s.start << " " << *s.end;
            return out;
        }
    };
}