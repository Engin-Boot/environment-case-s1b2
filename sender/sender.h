#include<iostream>
#include <vector>
#include <string>
#include<list>
#include<iterator>
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





//***********************To check if the string is a float or not****************************
bool FirstIsASpecialCharacter(string& s)
{
    if(isdigit(s[0]))
    {
        return false;
    }
    return true;
}
bool IsNotADot(list<char>& receivedlist)
{
    auto itr = receivedlist.begin();
    char dot=*itr;
    bool k = true;
    if (dot=='.')
    {
       k=false;
    }
    return k;
}
bool hasSpecialCharacterInBetween(string& s)
{
    list<char> temp;
    for (unsigned int i=0;i<s.size();i++)
    {
        if(!isdigit(s[i]))
        {
            temp.push_back(s[i]);
        }
    }
    if (temp.size()>1)
    {
        return true;
    }
    else if(temp.size()==1)
    {
        return IsNotADot(temp);
    }
    return false;
   
}
bool IsaFloat(string & columnData )
{
   
    if(FirstIsASpecialCharacter(columnData))
    {
        return false;
    }
   else if (hasSpecialCharacterInBetween(columnData))
   {
       return false;
   }
    return true;
}

//******************Modifying invalid entries into specific format and retain valid entries as it is ********************//

vector<string> modifyInvalidData(vector<string>& data )
{
    vector<string> rowVector;
    if (IsaFloat(data[0])==true &&IsaFloat(data[1])==true)
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

//*************process the entries converting invalid entries to specific format*****************
vector<vector <string> >processTheEntries( vector<vector <string> >& fetchedData)
{
    vector<vector <string> > processedEntries;
    for  (vector<string> getRow:fetchedData)
    {
        
         vector<string> rowData = modifyInvalidData(getRow);
         processedEntries.push_back(rowData);
    }
    return processedEntries;
}



