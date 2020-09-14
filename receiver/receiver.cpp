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

void extractValuesFromString(string line) 
{ 
    stringstream ss(line); 
        while(ss.good())
         {
         	string tempreaturestring,humiditystring;
         	getline(ss,tempreaturestring,' ');
         	getline(ss,humiditystring,'\n');
         	//cout<<tempreaturestring<<" "<<humiditystring;
        CheckForWarningAndAlert obj(stof(tempreaturestring),stof(humiditystring));
          } 
		 }
       

 int main()
{    
    
          string line="";
    while(getline(cin,line))
    {   
           extractValuesFromString(line);
    }
    return 0;
}
