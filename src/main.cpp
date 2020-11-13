#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <bitset>

#include "SunSpecModbus.h"

using namespace std;

int main()
{
    map <string,string> configs;
    configs["key"] = "1850954613";
    configs["did"]="1";
    configs["path"]=SUNSPEC_MODELS_DIR;
    configs["ip"]="192.168.0.64";
    configs["port"]="502";
    SunSpecModbus ssmb(configs);

    map <string, string> point;
    point["GSconfig_ReFloat_Volts"] = "50";
    ssmb.WritePoint(64116, point);
    point = ssmb.ReadBlock(64116);
    ssmb.PrintBlock(point);
    return 0;
}
