#include "CSV_Helpers.hpp"
/* 
    =======================================================================================
                            INCLUDE THIS FILE. NOT "CSV_Helpers.hpp"
    =======================================================================================
*/

vector<vector<string> > CSV_Reader::Get_Data(){
    return Data;
}

vector<string> CSV_Reader::Get_Column_Headers(){
    return Column_Headers;
}

vector<vector<int> > convert_data_to_int(vector<vector<string> > data){
    vector<vector<int> > int_data = vector<vector<int> >(data.size());
    for(int r = 0; r < data.size(); ++r){
        int_data[r] = vector<int>(data[r].size(), -1);
        for(int c = 0; c < data[r].size(); ++c){
            int_data[r][c] = stoi(data[r][c]);
        }
    }
    return int_data;
}

vector<int> convert_column_to_int(vector<vector<string> > data, int column){
    vector<int> int_data = vector<int>(data.size(), -1);
    for(int r = 0; r < data.size(); ++r){
        int_data[r] = stoi(data[r][column]);
    }
    return int_data;
}

vector<vector<double> > convert_data_to_double(vector<vector<string> > data){
    vector<vector<double> > double_data = vector<vector<double> >(data.size());
    for(int r = 0; r < data.size(); ++r){
        double_data[r] = vector<double>(data[r].size(), -1);
        for(int c = 0; c < data[r].size(); ++c){
            double_data[r][c] = stod(data[r][c]);
        }
    }
    return double_data;
}

vector<double> convert_column_to_double(vector<vector<string> > data, int column){
    vector<double> double_data = vector<double>(data.size(), -1);
    for(int r = 0; r < data.size(); ++r){
        double_data[r] = stod(data[r][column]);
    }
    return double_data;
}


CSV_Reader::CSV_Reader(){
    Load_Data();
}

void CSV_Reader::Load_Data(){
    string row;

    getline(cin, row);

    Column_Headers = split_by_commas(row);

    while(getline(cin, row)){
        Data.push_back(split_by_commas(row));
    }
}

vector<string> split_by_commas(string row){
    vector<string> row_data;
    int current_length = 0;
    int data_start = 0;
    for(int i = 0; i < row.length(); ++i){
        if(row[i] == ','){
            string data = row.substr(data_start, current_length);
            row_data.push_back(data);
            data_start = i + 1;
            current_length = 0;
        } else {
            ++current_length;
        }
    }
    string data = row.substr(data_start, current_length);
    row_data.push_back(data);
    return row_data;
}
