#include<bits/stdc++.h>
#include<iostream> 
#include<string.h>
#include <sstream> 
using namespace std;

class AlertMessage
{
    public:
    string RaiseAlert(string message,string valuename,string level)
    {
       string s;
       s=message+"!!"+valuename+" is "+level;
       return s;
    }
};
class CheckValues
{
   private:
   AlertMessage *alert;
   public:
   CheckValues(){}
   string CheckValuesForAlert(float value,string ValueName,float HighValueForAlert,float HighValueForWarning,float LowValueForAlert,float LowValueForWarning)
  {
   
     string s="";
     if(value>HighValueForAlert)
     {
        s=alert->RaiseAlert("Alert",ValueName,"Very high");
	 }
	 else if(value>HighValueForWarning)
	 {
	 	s=alert->RaiseAlert("Warning",ValueName,"high");
	 }
	 else if(value<LowValueForAlert)
	 {
	 	s=alert->RaiseAlert("Alert",ValueName,"very low");
	 }
     else if(value<LowValueForWarning)
     {
     	s=alert->RaiseAlert("Warning",ValueName,"low");
	 }
     return s;
  }
};

class PrintMessage
{   
    public:
      void PrintMessageOnConsole(string messageForTem,string messageForHumi)
        {
           cout<<messageForTem<<endl;
           cout<<messageForHumi<<endl;
        }
};

class CheckForWarningAndAlert
{     
 private:
    CheckValues check;
    PrintMessage *print;
    float ErrorHighValueForTem=40;
    float ErrorLowValueForTem=0;
    float WarningHighValueForTem=37;
    float WarningLowValueFortem=4;
    float ErrorHighValueForHumi=90;
    float WarningHighValueForHumi=70;
    public:
    CheckForWarningAndAlert(){}
     CheckForWarningAndAlert(float tempreature,float humidity)
     {
         
     string messageForTem=check.CheckValuesForAlert(tempreature,"tempreature",ErrorHighValueForTem
     ,WarningHighValueForTem,ErrorLowValueForTem,WarningLowValueFortem);
     string messageForHumi=check.CheckValuesForAlert(humidity,"humidity",ErrorHighValueForHumi
     ,WarningHighValueForHumi,0,0);
     print->PrintMessageOnConsole(messageForTem,messageForHumi);
     }
};

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
