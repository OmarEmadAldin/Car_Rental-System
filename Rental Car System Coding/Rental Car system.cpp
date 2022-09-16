#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <algorithm>

using namespace std;

     class Cars {
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

void set_renter(string a_renter){
        renter = a_renter;
    }

void display_car_data(){
        cout << CarModel << "," << LiscencePlate << "," << owner << "," << renter << "\n";
  } // used to display all the data of the object car
};

     class Renter {
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
        license_num=l; }
Renter();
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
    
    void set_id(string id) {national_id = id; }
    void set_name(string namee) {name= namee; }
    void set_age(string agee) {age=agee; }
    void set_gender(string genderr) { gender= genderr; }
    void set_lis(string lis) { license_num = lis; }
    
void display_renter_data(){
        cout << national_id << "," << name << "," << age << "," << gender <<"," <<license_num  <<  "\n"; }
};

void fill_my_renter_vector(vector <Renter> &r1);
void fill_my_cars_vector(vector <Cars>& c1);
void add_cars_data (vector <Cars>& c2);
void add_renter_data (vector <Renter> &r) ; 
void available(vector <Cars>& c3);
void not_available(vector <Cars>& c4) ;
void delete_cars (vector <Cars>& c);
void delete_renter (vector <Renter> &r1);
int module(vector <Cars> c, vector <Renter> r );

    int main(){
         vector <Cars> mycars;
         vector <Renter> myrenters;
            fill_my_cars_vector(mycars);
            fill_my_renter_vector(myrenters);

      	cout << "\n\n\t  PLEASE SELECT FROM THE MENU  ";
		cout << "\n\n\t Please choose one of the below options:   \n";
		cout << "--------------------------------------\n";
		cout << "1.Add a car \n";
		cout << "2.Delete a car  \n";
		cout << "3.Add a renter \n";
        cout << "4.Delete renter's data  \n";
		cout << "5.Show Avaliable Cars  \n";
		cout << "6.Show not Avaliable Cars \n";
		cout << "7.Assign a Renter  \n";
		cout << "8.exit \n";
        int choose;
        cin >> choose;

        switch (choose)
        {
        case 1:
          add_cars_data(mycars);
            break;
        case 2:
           delete_cars (mycars);
           break;
        case 3:
            add_renter_data(myrenters);
            break;
        case 4:
            delete_renter(myrenters) ;
            break;
        case 5:
           available(mycars);
           break;
        case 6:
           not_available(mycars);
            break;
        case 7:
           module(mycars,myrenters);
           break;

        default:
        cout << "Good Bye \n";
           exit;
            break;
        }

     return 0;
}

void fill_my_renter_vector(vector <Renter> &r1){
    r1.clear();
     string n_id,name,age,gender,lis_n;
     ifstream renter_data;
     renter_data.open("E:\\ASU\\C++\\VS Coding\\Renters' data.csv");
        if (renter_data.fail())
            cout<< "Error Opening File";
        // to see if there's any problems while opening the CSV file
    while (renter_data.good()){
         getline (renter_data,n_id,','); // used the delimitation to get specific data
         getline (renter_data,name,',');
         getline (renter_data,age,',');
         getline (renter_data,gender,',');
         getline (renter_data,lis_n,'\n');

         Renter newrenter (n_id,name,age,gender,lis_n);
         r1.push_back(newrenter);  // we pass an object to the vector as that's vector of objects
         }

        renter_data.close();
     }

void fill_my_cars_vector(vector <Cars> &c1){
    // same as fill my renter vector func
    c1.clear();
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

void add_cars_data (vector <Cars> &c2){

         string car_model;
         string license_no;
         string owner_name;
         string renter_name;
         ofstream car_data;
// we enter the data to the CSV file
        cout<< "Enter car model\n";
        cin >>car_model;
        cout<< "Enter license_no\n";
        cin>> license_no;
        cout<< "Enter owner\n";
        cin >> owner_name;
        char e;
        cout << " Is car Rented? (y/n) \n";
        cin >> e;
        if (e == 'y'){
        cout <<"Enter renter's name \n";
        cin >> renter_name;}
        else {
            renter_name = "NULL";
            }
            Cars newcar(car_model,license_no,owner_name,renter_name);
            c2.push_back(newcar);
            cout<<endl;
       car_data.open("E:\\ASU\\C++\\VS Coding\\Cars'Data.csv", fstream :: app);
       car_data << "\n" << car_model.c_str() << "," << license_no.c_str() << "," <<owner_name.c_str() <<"," << renter_name.c_str() ;

      car_data.close();

    }
void add_renter_data (vector <Renter> &r){
         string nationalid;
         string name1;
         string age1;
         string gender;
         string licensenum;
         ofstream renter_data;
// we enter the data to the CSV file
        cout<< "Enter National ID\n";
        cin >>nationalid;
        cout<< "Enter Name of the Renter\n";
        cin>> name1;
        cout<< "Enter the age\n";
        cin >> age1;
        cout<< "Enter the gender\n";
        cin >> gender;
        cout<< "Enter the Licence Num\n";
        cin >> licensenum;
        
            Renter newrenter (nationalid,name1,age1,gender,licensenum);
            r.push_back(newrenter);
            cout<<endl;
       renter_data.open("E:\\ASU\\C++\\VS Coding\\Renters' data.csv", fstream :: app);
       renter_data << "\n" << nationalid.c_str() << "," << name1.c_str() << "," <<age1.c_str() <<"," << gender.c_str() << "," << licensenum ;

      renter_data.close();

    }


void available(vector <Cars> &c3) {
         cout << " Avaliable cars are : \n" ;

    for (int i=0; i<c3.size() ; i++){
        if((c3[i].get_renter()) == "NULL" ) {
            cout << "Car :" << (c3[i].get_model()).c_str() << "," << (c3[i].get_LP()) <<"," << (c3[i].get_owner()).c_str() << endl ;
        } // checks if there's no renter
    }
}

void not_available(vector <Cars>& c4) {
    cout << "Not available Cars are : \n ";

          for (int i=0; i< c4.size() ; i++){
            if((c4[i].get_renter()) != "NULL"  ) {
                    cout  <<  "Car : " <<(c4[i].get_model()).c_str() << "," << (c4[i].get_LP())
                          <<"," << (c4[i].get_owner()).c_str() <<  " , is rented to: " << (c4[i].get_renter().c_str()) << endl ;
        }
    }
}

void delete_cars (vector <Cars> &c){
    int i=0 , x;
        for (i=0; i<c.size(); i++){
            cout << i << ": ";
            c[i].display_car_data();
            } // to shoe all the cars
    cout << "please enter the number of car you want to delete \n";
    cin >> x;
    c.erase(c.begin()+x); // to delete the specified object
    ofstream car_data;
    car_data.open("E:\\ASU\\C++\\VS Coding\\Cars'Data.csv", ios:: out);
        for (int i = 0 ; i<c.size(); i++){
                car_data << (c[i].get_model()).c_str() << "," << (c[i].get_LP()) <<","
                << (c[i].get_owner()).c_str() <<"," << (c[i].get_renter()).c_str() << "\n" ;
                }// to enter the after deleting the required one
         }
void delete_renter (vector <Renter> &r1){
    int i=0 , x;
        for (i=0; i<r1.size(); i++){
            cout << i << ": ";
            r1[i].display_renter_data();
            } 
    cout << "please enter the number of renter's data you want to delete \n";
    cin >> x;
    r1.erase(r1.begin()+x); // to delete the specified object
    ofstream renter_data;
    renter_data.open("E:\\ASU\\C++\\VS Coding\\Renters' data.csv", ios:: out);
        for (int i = 0 ; i<r1.size(); i++){
                renter_data << (r1[i].get_id()).c_str() << "," << (r1[i].get_name()) <<","
                            << (r1[i].get_age()).c_str() <<"," << (r1[i].get_gender()).c_str() <<","<< (r1[i].get_license()).c_str() << "\n" ;
                }
}

int module(vector <Cars> c, vector <Renter> r ) {
        string m,w_name , new_renter , National_id, w_age, w_gender, w_lp ,new_r ;
        int i_LP , index;
        bool exist = 0 , e1 = 0;
            cout << "enter the Liscence Plate \n";
            cin >> m; // denoted for license plate
                for (int i=0; i<c.size(); i++) {
                    if ((c[i].get_LP()) == m) {
                            e1 = 1;
                            index = i;
                    } // to compare the input license plate with the ones in the CSV file
              }
             if (!e1)  {
                                cout << "No avaiable car with this plate \n";
                                return 0;
                        }

                    if (e1) { /* if the license plate existed then we check if it has renter or not */
                        if((c[index].get_renter()) != "NULL") {
                                cout  <<  " the car is rented \n";
                                return 0;
                        }
                        

             cout << "please enter the National id of the renter \n";
             cin >> National_id;


                for (int j =0 ; j < r.size() ; j++) {
                    if (National_id == r[j].get_id())
                        exist =1;
                    } /* here we compare the national id to see if there's a renter with the same id or not*/

                 if (!exist){
                     cout << "please enter the renter's national id, name, age, gender, liscence number \n";
                     cin >> National_id >> w_name >> w_age >> w_gender >> w_lp;
                     ofstream new_rent;
                        if (new_rent.fail()) cout << "Error Opening \n";
                            new_rent.open("E:\\ASU\\C++\\VS Coding\\Renters' data.csv", fstream :: app);
                            new_rent <<"\n" << National_id << ","<< w_name <<"," << w_age <<","<< w_gender <<","<< w_lp;
                     /*the date of the new renter is now saved to the renter CSV file*/
                     }
                     fill_my_renter_vector(r);
                     }

                   

                  c[index].set_renter(w_name); // to assign the renter in the CSV file of cars
                  ofstream car_data;
                  car_data.open("E:\\ASU\\C++\\VS Coding\\Cars'Data.csv");
                      for (int i = 0 ;i<c.size(); i++){
                        car_data << (c[i].get_model()).c_str() << "," << (c[i].get_LP()) <<","
                                 << (c[i].get_owner()).c_str() <<"," << (c[i].get_renter()).c_str() << "\n" ;
            }
            if (!exist)
    cout << "this car with liscence plate : " << m << " is assigned to " << w_name;
    else if (exist){ 
    for (int i=0; i<r.size(); i++){
        if (National_id == r[i].get_id())  {cout << "this car with liscence plate : " << m << " is assigned to " << r[i].get_name();}
    
    } }
    return 0;
}
