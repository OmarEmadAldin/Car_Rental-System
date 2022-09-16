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
    void module(string licenseP) {
        string m ;
        m.assign(licenseP) ; // to assign the data of one string in another one
        string real_model ,real_license_plate, real_owner , real_renter , lolo , id , another_real_renter ;
        ifstream car_data; // to get the data from the CSV file
     car_data.open("E:\\ASU\\C++\\VS Coding\\Cars'Data.csv");
        for (int i =0 ; i<8 ; i++){
                vector<Cars> cc [i];
            getline(car_data, real_model, ',') ;
            getline(car_data, real_license_plate, ',') ;
            getline(car_data, real_owner, ',') ;
            getline(car_data, real_renter, ',') ;
            if (real_license_plate == m){
            cout << "the owner" << real_owner ;
            if (real_renter == " "){
            cout << "there's no renter " << "\n" <<"enter the name of the renter "<<endl;
            getline(cin , lolo);
                for (int j =0 ; j < 8 ; j++) {
                    vector <Cars> ccc[j] ;
                    getline(car_data, real_model, ',') ;
                    getline(car_data, real_license_plate, ',') ;
                    getline(car_data, real_owner, ',') ;
                    getline(car_data, another_real_renter, ',') ;
                    if (another_real_renter == lolo) cout <<"enter another name"<< endl ;
                    else cout <<"the new renter of the car is" << lolo << endl ;
                }
            cout << "enter the id" <<endl ;
            cin >> id;
            }
            if (real_renter!=" ") {
                cout <<"the renter"<<real_renter ;
                cout <<"you can't rent the car " << endl ;
            }
            }
        }
    }

    void avail() {
     string cd, lp1 , ow ,rr;
     ifstream car_data;
     car_data.open("E:\\ASU\\C++\\VS Coding\\Cars'Data.csv");
     for (int i =0 ; i>8 ; i++ ){
         vector <Cars> c2[i] ;
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
    void not_avail() {
     string cd, lp1 , ow ,rr;
     ifstream car_data;
     car_data.open("E:\\ASU\\C++\\VS Coding\\Cars'Data.csv");
     for (int i =0 ; i>8 ; i++ ){
            vector <Cars>& c2[i] ;
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




