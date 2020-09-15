#define CATCH_CONFIG_MAIN

#include<iostream>
#include<vector>
#include "../AllFiles/catch.hpp"
#include "../sender/sender.h"

using namespace std;

TEST_CASE("test case for modify data")
{     vector<string>data1={"21.5","34"};
       vector<string>data2={"21@","23.78"};
       vector<string>data3={"21.5","34"};
       vector<string>data4={"Invalid","Invalid"};
    REQUIRE(modifyInvalidData(data1)==data3);
    REQUIRE(modifyInvalidData(data2)==data4);

}
TEST_CASE("for checkProcessedRowDataIsAInvalidEntry")
{   const vector<vector <string> >row={  {"21","78"},{"Invalid","Invalid"}};
  
   REQUIRE(checkProcessedRowDataIsAInvalidEntry (row,0)==false);
   REQUIRE(checkProcessedRowDataIsAInvalidEntry (row,1)==true);
}

TEST_CASE("for processInvalidEntries")
{   vector<vector <string> >fetchedData={{"67","45"},{"98.45","23"},{"89","@3"}};
    vector<vector <string> > expectedData= {{"67","45"},{"98.45","23"},{"Invalid","Invalid"}};
    REQUIRE(processInvalidEntries(fetchedData)==expectedData);
}
