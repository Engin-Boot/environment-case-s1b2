#include<iostream>
#include <vector>
#include <string>
#include <fstream>
#include<sstream>
#include<stdexcept>
#include<exception>

using namespace std;

class CSVReader
{
    string fileName;
    string delimeter;
public:
  
   explicit CSVReader(const string& filename, const string& delim = ",") : fileName(filename), delimeter(delim) { }

    vector<vector <string> >openAndRead();
    vector<string> parseLine(stringstream & s);
  
};



vector<vector <string> > CSVReader::openAndRead()
{
    fstream file;
    vector<vector <string> > dataList;
    string line;
    vector<string> rowData;
    file.open(fileName, ios::in);
    try
    { 
        if (file) 
        {
              while (getline(file, line))
              {

                  stringstream str(line);
                  rowData.clear();
                  rowData =parseLine(str);
                  dataList.push_back(rowData);
                                                                          /* while (getline(str, data, ','))
                                                                             {
                                                                                      rowData.push_back(data);
                                                                            }*/
                                                                            
                                                                            

            }
           
        }
        else
        {
            {
                 throw runtime_error("Could not open file");
            }
        }
        
    }
    catch (std::exception &ex)
    {
       cout<<ex.what()<<endl;
       exit(0);
    }
        file.close();
   
   return dataList;
}

vector <string> CSVReader::parseLine(stringstream& s)
{
        string word;
		vector<string> row;
		while (getline(s, word, ',')) {
			row.push_back(word);
		}
		return row;
}