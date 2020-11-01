//
// Created by Zach on 10/30/2020.
//

#include "extrafile.h"
#include <iostream>
Weapon::Weapon(string _type, int _scale, float _powerUse) {
    type = _type;
    scale = _scale;
    powerUse = _powerUse;
}

Weapon::Weapon() {
    type = "N/A";
    scale = 0;
    powerUse = 0;
}

int Weapon::GetScale() {
    return scale;
}

float Weapon::GetPower() {
    return powerUse;
}

string Weapon::GetType() {
    return type;
}

void Weapon::SetPower(float f) {
    powerUse = f;

}

void Weapon::SetScale(int i) {
    scale = i;
}

void Weapon::SetType(string s) {
    type = s;
}

Spaceship::Spaceship(string _name, string _shipClass, short _length, int _shieldCapacity, float _speed,
                     vector<Weapon> _inventory) {
    name = _name;
    shipClass = _shipClass;
    length = _length;
    shieldCapacity = _shieldCapacity;
    speed = _speed;
    inventory = _inventory;

}

Spaceship::Spaceship() {
    name = "N/A";
    shipClass = "N/A";
    length = 0;
    shieldCapacity = 0;
    speed = 0;
    vector<Weapon> nullInv(0);
    inventory = nullInv;
}

void Spaceship::PrintShip() {
    std::cout << "Name: " << name << std::endl;
    std::cout << "Class: " << shipClass << std::endl;
    std::cout << "Length: " << length << std::endl;
    std::cout << "Shield capacity: " << shieldCapacity << std::endl;
    std::cout << "Maximum Warp: " << speed << std::endl;
    std::cout << "Armaments: " << std::endl;
    if (this->isUnarmed()){
        std::cout << "Unarmed" << std::endl;
    }
    else{
        for (long unsigned int i = 0; i < inventory.size(); ++i) {
            cout << inventory[i].GetType() << ", " << inventory[i].GetScale() << ", " << inventory[i].GetPower() << std::endl;
        }
        cout << "Total firepower: " << this->getTotalWeapons() << endl;
    }
}

int Spaceship::getMaxWeapon() {
    int max = 0;
    for (long unsigned int i = 0; i < inventory.size(); i++) {
        if (inventory[i].GetScale() > max){
            max = inventory[i].GetScale();
        }

    }
    cout << max << endl;
    return max;
}


int Spaceship::getTotalWeapons() {
    int sum = 0;
    for (long unsigned int i = 0; i < inventory.size(); ++i) {
        sum+=inventory[i].GetScale();
    }
    return sum;
}

bool Spaceship::isUnarmed() {
    if (this->getTotalWeapons() == 0){
        return true;
    }
    else return false;
}

void Spaceship::SetName(string string1) {
    name = string1;
}

void Spaceship::SetClass(string string1) {
    shipClass = string1;
}

void Spaceship::SetLength(short len) {
    length = len;
}

void Spaceship::SetShields(int cap) {
    shieldCapacity = cap;
}

void Spaceship::SetSpeed(float f) {
    speed = f;
}

void Spaceship::SetWeapons(vector<Weapon> inv) {
    inventory = inv;
}

