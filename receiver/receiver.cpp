#include<bits/stdc++.h>
#include<iostream> 
#include<string.h>
#include <sstream> 
using namespace std;


class CheckValues
{
   
   public:
   CheckValues(){}
   string CheckValuesForAlert(float value,string ValueName,float HighValueForAlert,float HighValueForWarning,float LowValueForAlert,float LowValueForWarning)
  {
   
     string s="",alert="ALERT",warning="WARNING",veryhigh="very high";
     string high="high",verylow="very low",low="low";
     if(value>HighValueForAlert)
     {  
        s="ALERT!!"+ValueName+" is "+"very high";
	 }
	 else if(value>HighValueForWarning)
	 {
	 	s="Warning!!"+ValueName+" is "+"high";
	 }
	 else if(value<LowValueForAlert)
	 {
	 	s="ALERT!!"+ValueName+" is "+"very low";
	 }
     else if(value<LowValueForWarning)
     {
     	s="Warning!!"+ValueName+" is "+"very low";
	 }
     return s;
  }
};

class PrintMessage
{   
    public:
      void PrintMessageOnConsole(string &messageForTem,string &messageForHumi)
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
