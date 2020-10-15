//
// Created by zacha on 9/18/2020.
//

#include <string>
#include <iostream>
#include "Vehicle.h"
using namespace std;



float Vehicle::GetPrice() {
    return price;
}

Vehicle::Vehicle() {
    make = "COP3503";
    model = "Rust Bucket";
    year = 1900;
    price = 0;
    mileage = 0;
}

void Vehicle::Display() {
    cout << year << " " << make << " " << model << " $" << price << " " << mileage << endl;
}

string Vehicle::GetYearMakeModel() {
    string yearMakeModelString = to_string(year) + " " + make + " " + model;
    return yearMakeModelString;
}

Vehicle::Vehicle(string _make, string _model, int _year, float _price, int _mileage) {
    make = _make;
    model = _model;
    year = _year;
    price = _price;
    mileage = _mileage;

}
