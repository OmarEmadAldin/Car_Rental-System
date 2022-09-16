#include <iostream>
#include <vector>
#include <fstream>
#include <fstream>
#include <iomanip>
using namespace std;
class Cars
{
private:
    string CarModel;
    string LiscencePlate;
    string owner;
    string renter;

public:
Cars(string c, string l, string o, string r){
CarModel=c;
LiscencePlate=l;
owner=o;
renter=r;}
Cars();
string get_model(){
    return CarModel;}

string get_LP(){
    return LiscencePlate;}

string get_owner(){
    return owner;}

string get_renter(){
    return renter;}

    void display_car_data(){

cout<< CarModel << "\n" << LiscencePlate << "\n" << owner << "\n" << renter << "\n";
    }

};

     void fill_my_vector(vector <Cars>& c1){
     string carmodel,lp,ownerr,renterr;
     ifstream car_data;
     car_data.open("E:\\ASU\\C++\\VS Coding\\Cars'Data.csv");
     if (car_data.fail())
          cout<< "Error Opening File";

    while (car_data.good()){
         getline (car_data,carmodel,',');
         getline (car_data,lp,',');
         getline (car_data,ownerr,',');
         getline (car_data,renterr,'\n');

         Cars newCars (carmodel,lp,ownerr,renterr);
         c1.push_back(newCars); }

        car_data.close();
     }

void available_car_for_rent(Cars){
    if (r=" ")
    cout<<
}
int main() {

return 0 ;
}
