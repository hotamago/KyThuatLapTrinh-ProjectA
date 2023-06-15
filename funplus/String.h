#pragma once
#include <vector>
#include <string>
#include <iostream>
using namespace std;

namespace funplus
{
    namespace String
    {
        vector<string> split(
            const string &s,
            const string delimiter = " ",
            const bool removeEmpty = true)
        {
            vector<string> result;
            size_t last = 0;
            size_t next = 0;
            while ((next = s.find(delimiter, last)) != string::npos)
            {
                string token = s.substr(last, next - last);
                if (!removeEmpty || token != "")
                {
                    result.push_back(token);
                }
                last = next + 1;
            }
            string token = s.substr(last);
            if (!removeEmpty || token != "")
            {
                result.push_back(token);
            }
            return result;
        }

        vector<string> split(
            const string &s,
            const char delimiter,
            const bool removeEmpty = true)
        {
            string delimiter_s = "";
            delimiter_s += delimiter;
            return split(s, delimiter_s, removeEmpty);
        }
    }
}