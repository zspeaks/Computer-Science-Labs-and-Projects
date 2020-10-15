//
// Created by zacha on 9/18/2020.
//

#ifndef LABS2_SHOWROOM_H
#define LABS2_SHOWROOM_H

#include <string>
#include <vector>

using namespace std;


class Showroom {
private:
    string name;
    unsigned int capacity;
    vector<Vehicle> VehicleList;
    vector<Vehicle> GetVehicleList();
public:
    Showroom(string name = "Unnamed Showroom", unsigned int capacity = 0);
    void AddVehicle(Vehicle v);
    void ShowInventory();
    float GetInventoryValue();
    int InventorySize();
};



#endif //LABS2_SHOWROOM_H
