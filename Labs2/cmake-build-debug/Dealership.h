//
// Created by zacha on 9/18/2020.
//

#ifndef LABS2_DEALERSHIP_H
#define LABS2_DEALERSHIP_H

#include <string>
#include <vector>


using namespace std;

class Dealership {
private:
    string name;
    unsigned int capacity;
    vector<Showroom> ShowroomList;
    vector<Showroom> GetShowroomList();
public:
    Dealership(string name = "Generic Dealership", unsigned int capacity = 0);
    void AddShowroom(Showroom s);
    float GetAveragePrice();
    void ShowInventory();
};


#endif //LABS2_DEALERSHIP_H
