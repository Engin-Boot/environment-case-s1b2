#include<iostream>
#include <vector>
#include <string>
using namespace std;
void readData(const string& path);
void printDataToConsole(vector<vector <string> >& );
class CSVReader
{
    string fileName;
    string delimeter;
public:
  
   explicit CSVReader(const string& filename, const string& delim = ",") : fileName(filename), delimeter(delim) { }

    vector<vector <string> >readAndParse();
  
};


