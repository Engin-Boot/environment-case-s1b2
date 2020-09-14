#include<bits/stdc++.h>
#include<iostream> 
#include<string.h>
#include <sstream> 
using namespace std;

class AlertMessage
{
    public:
    void RaiseAlert(string message,string ValueName,string level)
    {
        cout<<message<<"!! "<<ValueName<<" is "<<level<<endl;
    }
};
class CheckForWarningAndAlert
{     
     private:
      AlertMessage *alert;
    public:
    CheckForWarningAndAlert(){}
    CheckForWarningAndAlert(float tempreature,float humidity)
     {
           
         AlertAndWarningForHumidity(humidity);
         AlertAndWarningForTempreature(tempreature);
     }
    void AlertAndWarningForHumidity(float humidity)
    {    
       if(humidity>90)
       {
           alert->RaiseAlert("ERROR","humidity","high");
       }
       else if(humidity>70)
       alert->RaiseAlert("WARNING","humidity","high");
    }
      void AlertAndWarningForTempreature(float tempreature)
   {    
          if(tempreature<4)
          AlertForLowTempreature(tempreature);
          else if(tempreature>37)
          AlertForHighTempreature(tempreature);
   }
   void  AlertForLowTempreature(float tempreature)
   {
       if(tempreature<0)
       alert->RaiseAlert("ERROR","Tempreature","very low");
       else
        alert->RaiseAlert("WARNING","Tempreature","low");
    }
    void AlertForHighTempreature(float tempreature)
    {
         if(tempreature>40)
       alert->RaiseAlert("ERROR","Tempreature","very high");
       else
        alert->RaiseAlert("WARNING","Tempreature","high");
    }
};
void getvalue(vector<string>tempstring,vector<float>v)
{      float tempreature,humidity;
     if(tempstring[0].compare("tempreature"))
        {tempreature=v[0];
        humidity=v[1];}
        else
         {
             humidity=v[0];
             tempreature=v[1];
         }
     CheckForWarningAndAlert AlertAndWarningForAll(tempreature,humidity);
}
void extractValuesFromString(string line) 
{ 
    stringstream ss(line);      
     vector<float>v;
     vector<string>tempstring;
    string temp; 
    float found; 
    while (!ss.eof()) { 
  
        ss >> temp; 
           
        if (stringstream(temp) >> found) 
           {
                v.push_back(found);
           }
          else
             {
                 tempstring.push_back(temp);
             }
        temp = ""; }
        getvalue(tempstring,v);
       
} 

 int main()
{    
     string line;
    while(getline(cin,line))
    {   
           extractValuesFromString(line);
    }
    return 0;
}
