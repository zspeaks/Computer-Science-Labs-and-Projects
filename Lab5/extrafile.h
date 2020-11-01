//
// Created by Zach on 10/30/2020.
//

#ifndef LAB5_EXTRAFILE_H
#define LAB5_EXTRAFILE_H
#include "string"
#include "vector"

using namespace std;

class Weapon {
    string type;
    int scale;
    float powerUse;
public:
    Weapon();
    Weapon(string _type, int _scale,float _powerUse);
    string GetType();
    int GetScale();
    float GetPower();
    void SetType(string s);
    void SetScale(int i);
    void SetPower(float f);
};




class Spaceship {
    string name;
    string shipClass;
    short length;
    int shieldCapacity;
    float speed;
    vector<Weapon> inventory;
public:
    Spaceship();
    Spaceship(string _name, string _shipClass, short _length, int _shieldCapacity, float _speed, vector<Weapon> _inventory);
    void SetName(string string1);
    void SetClass(string string1);
    void SetLength(short len);
    void SetShields(int cap);
    void SetSpeed(float f);
    void SetWeapons(vector<Weapon> inv);
    void PrintShip();

    int getMaxWeapon();

    int getTotalWeapons();

    bool isUnarmed();
};


#endif //LAB5_EXTRAFILE_H



