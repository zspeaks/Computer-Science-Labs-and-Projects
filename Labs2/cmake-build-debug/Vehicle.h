//
// Created by zacha on 9/18/2020.
//

#ifndef LABS2_VEHICLE_H
#define LABS2_VEHICLE_H
#include <string>
using namespace std;

class Vehicle {
private:
    string make;
    string model;
    unsigned int year;
    unsigned int mileage;
    float price;

public:
    Vehicle();
    Vehicle(string _make, string _model, int _year, float _price, int _mileage);
    void Display();
    string GetYearMakeModel();
    float GetPrice();
    };


#endif //LABS2_VEHICLE_H
