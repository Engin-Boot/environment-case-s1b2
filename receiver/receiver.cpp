#include<bits/stdc++.h>
#include<iostream> 
#include<string.h>
#include <sstream> 
using namespace std;


class CheckValues
{
   
   public:
   CheckValues(){}
   string CheckValuesForAlert(float value,string &ValueName,float HighValueForAlert,float HighValueForWarning,float LowValueForAlert,float LowValueForWarning)
  {
      string s="";
    if(value>HighValueForWarning)
      s=checkforhighvalues(value,ValueName,HighValueForAlert,HighValueForWarning);
    else
       s=checkforlowvalues(value,ValueName,LowValueForAlert,LowValueForWarning);
     return s;
  }
  string checkforlowvalues(float value,string &ValueName,float LowValueForAlert,float LowValueForWarning)
  {   string s="";
    if(value<LowValueForAlert)
	 {
	 	s="ALERT!!"+ValueName+" is "+"very low";
	 }
     else if(value<LowValueForWarning)
     {
     	s="Warning!!"+ValueName+" is "+"very low";
	 }
     return s;
  }
  string checkforhighvalues(float value,string &ValueName,float HighValueForAlert,float HighValueForWarning)
  {
     string s="";
     if(value>HighValueForAlert)
     {  
        s="ALERT!!"+ValueName+" is "+"very high";
	 }
	 else if(value>HighValueForWarning)
	 {
	 	s="Warning!!"+ValueName+" is "+"high";
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
         string humidityname="humidity",tempreaturename="tempreature";
     string messageForTem=check.CheckValuesForAlert(tempreature,tempreaturename,ErrorHighValueForTem
     ,WarningHighValueForTem,ErrorLowValueForTem,WarningLowValueFortem);
     string messageForHumi=check.CheckValuesForAlert(humidity,humidityname,ErrorHighValueForHumi
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
