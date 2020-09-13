#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include<sstream>
#include<exception>
#include <algorithm>
#include "sender.h"
#include<chrono>
#include<stdexcept>
#include<thread>
#include<cmath>
using namespace std;

vector<vector <string> > CSVReader::readAndParse()
{
    fstream file;
    vector<vector <string> > dataList;
    string line ="";
    string data ="";
    
    try
    {
        file.open(fileName);
        if (!file) 
        {
            throw runtime_error("Could not open file");
        }

    }
    catch (std::exception &ex)
    {
       cout<<ex.what()<<endl;
       exit(0);

    }
    
     while (getline(file, line))
    {
       stringstream str(line);
       vector<string> rowData;
        while (getline(str, data, ','))
        {
            rowData.push_back(data);
        }
        dataList.push_back(rowData);

    }

    file.close();
   
   return dataList;
}
bool IsaNumber(string  columnData )
{
    int k = columnData.length();
    if(k==1&&columnData[0]=='.')
    {
        return false;
    }
   else
   {
    for (int i=0;i<columnData.length();i++)
    {
        if(isdigit (columnData[i])==false&&columnData[i]!='.')
        {
            return false;
        }

    }
   }
    return true;
}
vector<string> modifyInvalidData(vector<string>& data )
{
    vector<string> rowVector;
    if (IsaNumber(data[0])==true &&IsaNumber(data[1])==true)
    {
        rowVector.push_back(data[0]);
        rowVector.push_back(data[1]);
    }
    else
    {
        rowVector.push_back("0");
        rowVector.push_back("0");
    }
    
   return rowVector;
}

vector<vector <string> >processInvalidEntries(vector<vector <string> >& fetchedData)
{
    vector<vector <string> > processedEntries;
    for  (std::vector<string> getRow:fetchedData)
    {
         vector<string> rowData = modifyInvalidData(getRow);
         if (rowData.size()==2)
         {
              processedEntries.push_back(rowData);
         }
         else
         {
             cout<<"Data Missing"<<endl;
             exit(0);
         }
         
    }
    return processedEntries;
}
void printProcessedData(vector<vector <string> >& processedData)
{
    for (int i=0;i<processedData.size();i++)
    {
        
           if (processedData[i][0]=="0"&&processedData[i][1]=="0")
           {
                this_thread::sleep_for(chrono::seconds(10) );
           }
           else
           {
               cout<<"Temperature:"+processedData[i][0]<<","<<"Humidity:"+processedData[i][1]<<endl;
           }
           
         /* for(int j=0;j<processedData[i].size();j++)
          {
              cout<<processedData[i][j]<<",";
          }*/
           
        
      cout<<endl;
    this_thread::sleep_for(chrono::seconds(5) );
    }
}
void readData(const string& filename)
{
     CSVReader reader(filename,",");
     vector<vector <string> > fetchedData = reader.readAndParse();
     vector<vector <string> > processedData = processInvalidEntries(fetchedData);
     printProcessedData(processedData);
   
}

int main()
{
   readData("data.csv");
   return 0;
}