#include<iostream>
#include <vector>
#include <string>
using namespace std;
vector <vector <string> >readData(const string& path);
bool checkProcessedRowDataIsAInvalidEntry (const vector<vector <string> >& row,int i)
{
    if(row[i][0]=="Invalid"&&row[i][1]=="Invalid")
    {
        return true;
    }
    return false;
}
bool FirstIsASpecialCharacter(string& s)
{
    if(isdigit(s[0]))
    {
        return false;
    }
    return true;
}
bool stringIsNotAInteger(string& s)
{
    for (unsigned int i=0;i<s.size();i++)
    {
        if (!isdigit(s[i]))
         {
             return true;
         }

    }
    return false;
}
bool IsaInteger(string & columnData )
{
   
    if(FirstIsASpecialCharacter(columnData))
    {
        return false;
    }
   else if (stringIsNotAInteger(columnData))
   {
       return false;
   }
    return true;
}
vector<string> modifyInvalidData(vector<string>& data )
{
    vector<string> rowVector;
    if (IsaInteger(data[0])==true &&IsaInteger(data[1])==true)
    {
        rowVector.push_back(data[0]);
        rowVector.push_back(data[1]);
    }
    else
    {
        rowVector.push_back("Invalid");
        rowVector.push_back("Invalid");
    }
    
   return rowVector;
}
vector<vector <string> >processInvalidEntries(const vector<vector <string> >& fetchedData)
{
    vector<vector <string> > processedEntries;
    for  (vector<string> getRow:fetchedData)
    {
        
         vector<string> rowData = modifyInvalidData(getRow);
         processedEntries.push_back(rowData);
        
         
    }
    return processedEntries;
}



