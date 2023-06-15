#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include "../funplus/String.h"
using namespace std;

namespace module
{
    class ConfigReader
    {
    public:
        string path;
        ConfigReader(string path = "config.cf")
        {
            this->path = path;
        }
        map<string, string> Read()
        {
            map<string, string> result;
            ifstream file(path);
            string line;
            while (getline(file, line))
            {
                vector<string> values = funplus::String::split(line, "=");
                result[values[0]] = values[1];
            }
            file.close();
            return result;
        }
    };
}