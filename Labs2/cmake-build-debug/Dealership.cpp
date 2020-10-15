//
// Created by zacha on 9/18/2020.
//

#include "Vehicle.h"
#include "Showroom.h"
#include "Dealership.h"
#include <iostream>
#include <iomanip>
using namespace std;

vector<Showroom> Dealership::GetShowroomList() {
    return ShowroomList;
}

Dealership::Dealership(string _name, unsigned int _capacity) {
    name = _name;
    capacity = _capacity;
}

void Dealership::AddShowroom(Showroom s) {
    if(GetShowroomList().size() == capacity){
        cout << "Dealership is full, can't add another showroom!" << endl;
    }
    else{
        ShowroomList.push_back(s);
    }
}

float Dealership::GetAveragePrice() {
    float totalPrice = 0;
    int totalVehicles = 0;
    float averagePrice;
    for(int i=0;i<GetShowroomList().size();i++){
        totalPrice+= GetShowroomList()[i].GetInventoryValue();
        totalVehicles+= GetShowroomList()[i].InventorySize();
    }
    if(totalVehicles == 0){
        return 0.0;
    }
    else{
        averagePrice = totalPrice / totalVehicles;
        return averagePrice;
    }
    
}

void Dealership::ShowInventory() {
    if(GetShowroomList().empty()){
        cout << name << " is empty!" << endl;
    }
    else{
        for(int i=0;i<GetShowroomList().size();i++){
            GetShowroomList()[i].ShowInventory();
            cout << endl;
        }
    }
    cout << "Average car price: $" << GetAveragePrice();

}
