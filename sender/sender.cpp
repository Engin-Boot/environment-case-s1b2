#include <iostream>
#include <vector>
#include <algorithm>
#include "sender.h"
#include<chrono>
#include<thread>
#include "CSVReader.h"
using namespace std;

void printProcessedData(vector<vector <string> >& processedData)
{
   
    for (unsigned int i=0;i<processedData.size();i++)
    {
       
           if (checkProcessedRowDataIsAInvalidEntry(processedData,i))
           {
                this_thread::sleep_for(chrono::seconds(5) );
           }
           else
           {
               cout<<processedData[i][0]<<" "<<processedData[i][1]<<endl;
           }
    }
}
vector<vector <string> > readData(const string& filename)
{
    CSVReader reader(filename,",");
    vector<vector <string> > fetchedData = reader.openAndRead();
    return fetchedData;
}

int main()
{ 
 
  vector<vector<string>>fetchedData=readData("data.csv");
  vector<vector<string>> processedData = processInvalidEntries(fetchedData);
  printProcessedData(processedData);
   return 0;
}
