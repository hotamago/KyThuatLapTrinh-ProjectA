#pragma once
#include <string>
#include <iostream>
#include "Shape.h"
using namespace std;

namespace entity
{
    class Edge
    {
    public:
        string name;
        string from, to;
        Shape *shape;
        Edge(string name, string from, string to, Shape *shape)
        {
            this->name = name;
            this->from = from;
            this->to = to;
            this->shape = shape;
        }

        friend ostream &operator<<(std::ostream &out, Edge &e)
        {
            out << e.name << " " << e.from << " " << e.to << " " << *e.shape;
            return out;
        }

        bool checkNiceEdge()
        {
            if (this->from == this->to)
            {
                return false;
            }
            return true;
        }
    };
}