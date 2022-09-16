#include <iostream>
#include <string>
#include<fstream>
#include<vector>

using namespace std;

class cars_data {
    private:
int carmodel =0;
string lisenceplate ="";
string owner="";
string renter="";

    public:

    cars_data();
    void add_file_values(){
    fstream car_data;
car_data.open("Cars' Data.csv");
if (car_data.fail())   cout << "Error the file doesn't exsist \n";

while(car_data.eof()){
getline (car_data,carmodel,',');
getline (car_data,lisenceplate,',');
getline (car_data,owner,',');
getline (car_data,renter,'/n');

    
};


