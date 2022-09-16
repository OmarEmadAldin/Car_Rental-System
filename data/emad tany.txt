#include <iostream>
#include <vector>
#include <fstream>
#include <fstream>
#include <iomanip>
using namespace std;
class Renter
{
private:
    string national_id;
    string name;
    string age;
    string gender;
    string license_num;

public:
Renter(string n_i, string n, string a, string g , string l){
national_id=n_i;
name=n;
age=a;
gender=g;
license_num=l;
}
Cars();
string get_id(){
    return national_id;}

string get_name(){
    return name;}

string get_age(){
    return age;}

string get_gender(){
    return gender;}

string get_license(){
    return license_num;}

    void display_renter_data(){

cout<< national_id << "\n" << name << "\n" << age << "\n"
<< gender << "\n" << license_num << endl ;
    }

};

     void fill_my_renter_vector(vector <Renter>& r1){
     string s_national_id,s_name,s_age,s_gender , s_license_num;
     ifstream renter_data;
     renter_data.open("C:\\Users\\Hamed\\Desktop\\renters' data.csv");
     if (renter_data.fail())  cout<< "Error Opening File";
    while (renter_data.good()){
         getline (renter_data,s_national_id,',');
         getline (renter_data,s_name,',');
         getline (renter_data,s_age,',');
         getline (renter_data,s_gender,'\n');
         getline (renter_data,s_license_num,'\n');

         Renter new_renter (s_national_id,s_name,s_age,s_gender,s_license_num);
         r1.push_back(new_renter); }

        renter_data.close();
     }

     int main() {
     return 0;
     }
