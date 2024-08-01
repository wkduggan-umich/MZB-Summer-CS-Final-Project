#include <vector>
#include <string>
#include <iostream>
using namespace std;
/* 
    =======================================================================================
                        DO NOT INCLUDE THIS FILE. INCLUDE "CSV_Code.hpp"
    =======================================================================================
*/

//Converts a data table of strings to integers
//Input: A 2-D vector of strings
//Output: A 2-D vector of integers
vector<vector<int> > convert_data_to_int(vector<vector<string> > data);

//Converts a data column of strings to integers
//Input: A vector of strings and an integer representing the column to convert
//Output: A vector of integers
vector<int> convert_column_to_int(vector<vector<string> > data, int column);

//Converts a data table of strings to integers
//Input: A 2-D vector of strings
//Output: A 2-D vector of integers
vector<vector<double> > convert_data_to_double(vector<vector<string> > data);

//Converts a data column of strings to integers
//Input: A vector of strings and an integer representing the column to convert
//Output: A vector of integers
vector<double> convert_column_to_double(vector<vector<string> > data, int column);

//Splits a row of CSV data into a vector. Used by the CSV_Reader class
//Input: A string containing row data
//Output: A vector of strings containing row data
vector<string> split_by_commas(string row);

//A class to read in and store CSV data
//Data is loaded in from the CSV input when the object is created
class CSV_Reader{
    private: 
    //The CSV Data
    vector<vector<string> > Data;

    //The CSV Column Header Names
    vector<string> Column_Headers;

    //Loads the CSV data in from standard input
    void Load_Data();

    public:
    //A default constructor that will load in CSV data automatically
    CSV_Reader();
    
    //Returns the 2-D vector of strings representing the data
    vector<vector<string> > Get_Data();

    //Returns a vector of string containing the column headers
    vector<string> Get_Column_Headers();
};
