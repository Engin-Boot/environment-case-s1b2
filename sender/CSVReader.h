#include<iostream>
#include <vector>
#include <string>
#include <fstream>
#include<sstream>

using namespace std;

class CSVReader
{
    string fileName;
    string delimeter;
public:
  
   explicit CSVReader(const string& filename, const string& delim = ",") : fileName(filename), delimeter(delim) { }

    vector<vector <string> >readAndParse();
  
};



vector<vector <string> > CSVReader::readAndParse()
{
    fstream file;
    vector<vector <string> > dataList;
    string line ="";
    string data ="";
    file.open(fileName);
     /*try{ if (!file) 
        {
            throw runtime_error("Could not open file");
        }
     }*/
   
 
   /* catch (std::exception &ex)
    {
       cout<<ex.what()<<endl;
       exit(0);
    }*/
    
    
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

