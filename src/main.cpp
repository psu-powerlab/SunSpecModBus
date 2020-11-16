#include <iostream>
#include <vector>
#include <string>
#include <bitset>

#include "SunSpecModbus.h"

using namespace std;

int main()
{
    SunSpecModbus ssmb(1, 1850954613, "192.168.0.64", 502);

    map <string, string> point;
    point["GSconfig_ReFloat_Volts"] = "50";
    ssmb.WritePoint(64116, point);
    point = ssmb.ReadBlock(64116);
    ssmb.PrintBlock(point);
    return 0;
}
