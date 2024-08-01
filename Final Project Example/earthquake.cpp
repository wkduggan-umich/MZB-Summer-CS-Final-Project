#include "earthquake.hpp"

int main(){
    //Create the CSV object and read in the data
    CSV_Reader csv_reader;

    //Load the data into a 2-D string vector
    vector<vector<string> > data_in = csv_reader.Get_Data();

    //Create the earthquake_data class and load in the data
    earthquake_data data(data_in);

    //Get the largest by year data
    vector<pair<int, double> > largest_by_year = data.largest_by_year();

    //Print the average by year data as comma seperated
    cout << "----------------------------------------------------------------------------\n";
    cout << "\t\t\t\tLargest By Year:\n";
    cout << "----------------------------------------------------------------------------\n";
    cout << "Year,Magnitude\n";
    for(int i = 0; i < largest_by_year.size(); ++i){
        cout << largest_by_year[i].first << "," << largest_by_year[i].second << "\n";
    }

    //Get the average by year data
    vector<pair<int, double> > average_by_year = data.average_by_year();

    //Print the average by year data as comma seperated
    cout << "----------------------------------------------------------------------------\n";
    cout << "\t\t\t\tAverage By Year:\n";
    cout << "----------------------------------------------------------------------------\n";
    cout << "Year,Magnitude\n";
    for(int i = 0; i < average_by_year.size(); ++i){
        cout << average_by_year[i].first << "," << average_by_year[i].second << "\n";
    }

    //Get the five largest earthquakes
    vector<data_row> five_largest = data.five_largest();

    //Print the average by year data as comma seperated
    cout << "----------------------------------------------------------------------------\n";
    cout << "\t\t\t\tFive Largest:\n";
    cout << "----------------------------------------------------------------------------\n";
    cout << "Year,Latitude,Longitude,Magnitude\n";
    for(int i = 0; i < five_largest.size(); ++i){
        cout << five_largest[i].year << "," << five_largest[i].latitude 
            << "," << five_largest[i].longitude << "," << five_largest[i].magnitude << "\n";
    }
}