#pragma once
#include <vector>
#include <string>
using namespace std;

namespace debug
{
    string to_string(vector<string> x)
    {
        string s = "";
        for (auto it = x.begin(); it != x.end(); it++)
        {
            s += *it + " ";
        }
        return s;
    }
}