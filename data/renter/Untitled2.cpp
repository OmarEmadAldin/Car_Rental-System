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

Cars(string c, string l, string o, string r ){
CarModel=c;
LiscencePlate=l;
owner=o;
renter=r;
}
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


    void avail(vector <Cars>& c2) {
     string cd, lp1 , ow ,rr;
     ifstream car_data;
     car_data.open("E:\\ASU\\C++\\VS Coding\\Cars'Data.csv");
     for (int i =0 ; i>8 ; i++ ){
            getline(car_data, cd, ',') ;
            getline(car_data, lp1, ',') ;
            getline(car_data, ow, ',') ;
            getline(car_data, rr, ',') ;

        if(rr == " ") {
                cout <<"the data of the that has no renter" <<endl ;
                cout << cd <<lp1 << ow <<endl;
                }
     }
    }
    void not_avail(vector <Cars>& c2) {
     string cd, lp1 , ow ,rr;
     ifstream car_data;
     car_data.open("E:\\ASU\\C++\\VS Coding\\Cars'Data.csv");
     for (int i =0 ; i>8 ; i++ ){
            getline(car_data, cd, ',') ;
            getline(car_data, lp1, ',') ;
            getline(car_data, ow, ',') ;
            getline(car_data, rr, ',') ;
          if(rr != " ") {
                cout <<"the data of the that has renter" <<endl ;
                cout << rr <<endl;
                }
     }
}

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
int main()
 {

     return 0 ;
 }


