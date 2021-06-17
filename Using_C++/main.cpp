#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>

using namespace std;


int calc_rows()   //function to calculate total number of rows
{
    int rows=0;
    ifstream file("mempool.csv");   //input file stream to read input from mempool file.
    string line;
    while (getline(file,line))      //rows++ on every encounter of newline after a string 
    rows++;

    return rows;          //function returns total rows 
}

int main()
{
  
  fstream fin,fout;      // file pointer each for input and output
  fin.open("sortedmempool.csv");      //mempool file sorted in descending order according to fee
  fout.open("block.txt", ios::out | ios::app);    // opens an existing file or creates a new file.

  string taxid;
  string fee;
  string weight;
  string parent_txids;

  int rows=calc_rows();  //calling function calc_rows();
  cout<<rows<<endl;

  int max_wt=4000000;     //maximum weight which is used
  int calculate=0;

  while(fin.good())  //The good() method used to check if the stream is good enough to work.
 {
     getline(fin,taxid,',');  // read every column data of a row and store it in a string variable
     getline(fin,fee,',');
     getline(fin,weight,',');
     getline(fin,parent_txids,'\n');

     int second=stoi(weight);    // convert string to integer for comparision

     if((calculate+second)<=max_wt)
     {
       fout<<taxid<<'\n';
       calculate=calculate+second;
     }

 }

  
 fin.close();
 fout.close();

}

