//
// Created by zacha on 9/18/2020.
//

#include "Vehicle.h"
#include "Showroom.h"
#include <iostream>
#include <iomanip>

using namespace std;

Showroom::Showroom(string _name, unsigned int _capacity) {
    name = _name;
    capacity = _capacity;

}

vector<Vehicle> Showroom::GetVehicleList() {
    return VehicleList;
}

void Showroom::AddVehicle(Vehicle v) {
    if(VehicleList.size() == capacity){
        cout << "Showroom is full! Cannot add " << v.GetYearMakeModel() << endl;
    }
    else{
        VehicleList.push_back(v);
    }

}

void Showroom::ShowInventory() {
    if(VehicleList.empty()){
        cout << name << " is empty!" << endl;
    }
    else{
        cout << "Vehicles in " << name << endl;
        for(int i = 0;i<VehicleList.size();i++){
            VehicleList[i].Display();
        }
    }
}

float Showroom::GetInventoryValue() {
    float totalPrice = 0;
    for(int i = 0;i<VehicleList.size();i++){
        totalPrice += VehicleList[i].GetPrice();
    }
    return totalPrice;
}

int Showroom::InventorySize() {
    return VehicleList.size();
}
