#include<bits/stdc++.h>
#include<iostream> 
#include<string.h>
#include <sstream> 
using namespace std;

class AlertMessage
{
    public:
    void RaiseAlert(string& message)
    {
        cout<<message<<endl;
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
    {    string message;
       if(humidity>90)
       {     
           message="ERROR!!humidity is high";
           alert->RaiseAlert(message);
       }
       else if(humidity>70)
       {

       message="WARNING!!humidity is high";
           alert->RaiseAlert(message);}

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
       {
           string message="ERROR!!tempreature is low";
           alert->RaiseAlert(message);
       }
       else
       {
           string message="WARNING!!humidity is low";
           alert->RaiseAlert(message);
       }
   }
    void AlertForHighTempreature(float tempreature)
    {
         if(tempreature>40)
         {
             string message="ERROR!!tempreature is very high";
           alert->RaiseAlert(message);
         }
       else
       {
           string message="WARNING!!Tempreature is high";
           alert->RaiseAlert(message);
       }
    }
};

void extractValuesFromString(string line) 
{ 
    stringstream ss(line); 
	float tempreature,humidity;     
     vector<float>v;
    string temp; 
    float IsAFloatValue; 
    while (!ss.eof()) { 
  
        ss >> temp; 
           
        if (stringstream(temp) >> IsAFloatValue) 
           {
                v.push_back(IsAFloatValue);
           }
        
        temp = ""; }
         tempreature=v[0];
         humidity=v[1];
         
       CheckForWarningAndAlert obj(tempreature,humidity);
} 

 int main()
{    
   while(1)
     {
          string line;
    while(getline(cin,line))
    {   
           extractValuesFromString(line);
    }
    }
    
    return 0;
}
