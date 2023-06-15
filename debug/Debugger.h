#pragma once
#include <string>
#include <iostream>
using namespace std;

namespace debug
{
    class Debugger
    {
    public:
        int cntCheckPoint = 0;
        Debugger()
        {
        }
        void checkpoint(string name = "checkpoint")
        {
            std::cerr << "Debug (" << name << "): " << this->cntCheckPoint << endl;
            this->cntCheckPoint++;
        }
    };
}