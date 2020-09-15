#include<bits/stdc++.h>
#include<iostream> 
#include<string.h>
#include <sstream> 
#include "receiver.h"
using namespace std;
void extractValuesFromStringAndSendValuesForChecking(string line) 
{ 
    stringstream ss(line); 
        while(ss.good())
        {
         	string tempreaturestring,humiditystring;
         	getline(ss,tempreaturestring,' ');
         	getline(ss,humiditystring,'\n');
         	CheckForWarningAndAlert obj(stof(tempreaturestring),stof(humiditystring));
        } 
}
       
 int main()
{    
    
          string line="";
    while(getline(cin,line))
    {   
        extractValuesFromStringAndSendValuesForChecking(line);
    }
    return 0;
}
