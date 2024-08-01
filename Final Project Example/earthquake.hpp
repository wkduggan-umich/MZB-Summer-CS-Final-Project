//Include the CSV Helpers
#include "CSV_Code.hpp"

//A struct to hold all of the data row's data
struct data_row{
    string date;
    int year;
    int month;
    int day;

    double latitude;
    double longitude;

    double magnitude;
};

class earthquake_data{
    public: 
    //A vector of data_row structure of the earthquake data
    vector<data_row> earthquakes;

    //A constructor to take in the string data and convert it to data_row objects
    earthquake_data(vector<vector<string> > data);

    //Get the largest earthquake for each year
    vector<pair<int, double> > largest_by_year();

    //Get the average earthquake magnitude for each year
    vector<pair<int, double> > average_by_year();

    //Get the five largest earthquakes
    vector<data_row> five_largest();
};

earthquake_data::earthquake_data(vector<vector<string> > data){
    earthquakes.reserve(data.size());

    for(int row = 0; row < data.size(); ++row){
        data_row dr;

        dr.date = data[row][0];
        dr.month = stoi(dr.date.substr(0, 2));
        dr.day = stoi(dr.date.substr(3, 2));
        dr.year = stoi(dr.date.substr(6, 4));

        dr.latitude = stod(data[row][1]);
        dr.longitude = stod(data[row][2]);

        dr.magnitude = stod(data[row][3]);

        earthquakes.push_back(dr);
    }
}

vector<pair<int, double> > earthquake_data::largest_by_year(){
    vector<pair<int, double> > largest_by_year;
    int year = earthquakes[0].year;
    double max = 0;
    for(int row = 0; row < earthquakes.size(); ++row){
        if(year != earthquakes[row].year){
            largest_by_year.push_back(pair<int,double>(year, max));
            year = earthquakes[row].year;
            max = earthquakes[row].magnitude;
        } else {
            if(earthquakes[row].magnitude > max){
                max = earthquakes[row].magnitude;
            }
        }
    }
    largest_by_year.push_back(pair<int,double>(year, max));
    return largest_by_year;
}

vector<pair<int, double> > earthquake_data::average_by_year(){
    vector<pair<int, double> > largest_by_year;
    int year = earthquakes[0].year;
    int number = 0;
    double sum = 0;
    for(int row = 0; row < earthquakes.size(); ++row){
        if(year != earthquakes[row].year){
            double average = sum / number;
            largest_by_year.push_back(pair<int,double>(year, average));
            year = earthquakes[row].year;
            number = 1;
            sum = earthquakes[row].magnitude;
        } else {
            number++;
            sum += earthquakes[row].magnitude;
        }
    }
    double average = sum / number;
    largest_by_year.push_back(pair<int,double>(year, average));
    return largest_by_year;
}

vector<data_row> earthquake_data::five_largest(){
    vector<data_row> largest;
    double min_in_largest = 10;
    int min_index = 0;
    for(int row = 0; row < earthquakes.size(); ++row){
        if(largest.size() < 5)
        {
            largest.push_back(earthquakes[row]);
            if(earthquakes[row].magnitude < min_in_largest)
            {
                min_in_largest = earthquakes[row].magnitude;
                min_index = row;
            }
        }
        else 
        {
            if(earthquakes[row].magnitude > min_in_largest)
            {
                largest[min_index] = earthquakes[row];
                min_index = 0;
                min_in_largest = 10;
                for(int i = 0; i < largest.size(); ++i)
                {
                    if(largest[i].magnitude < min_in_largest)
                    {
                        min_index = i;
                        min_in_largest = largest[i].magnitude;
                    }
                }
            }
        }
    }
    return largest;
}