#include <iostream>
#include <fstream>

#include "vector"
#include "extrafile.h"

using namespace std;

int main() {
    cout << "Which file(s) to open?\n";
    cout << "1. friendlyships.shp" << endl;
    cout << "2. enemyships.shp" << endl;
    cout << "3. Both files" << endl;
    int option;
    cin >> option;

    vector<Spaceship> shipList;
    if (option == 1 || option == 3){
        ifstream file ("friendlyships.shp", ios::in | ios::binary);
        int numShips;
        file.read((char*)&numShips, sizeof(numShips));
        for (int i = 0; i < numShips; ++i) {
            int nameLength;
            file.read((char*)&nameLength, sizeof(nameLength));
            vector<char> nameVec(nameLength);
            file.read(&nameVec[0], nameLength);

            string name(nameVec.begin(), nameVec.end() -1);

            int classLength;
            file.read((char*)&classLength, sizeof(classLength));
            vector<char> classVec(classLength);
            file.read(&classVec[0], classLength);
            string _class(classVec.begin(), classVec.end() -1);


            short shipLength;
            file.read((char*)&shipLength, sizeof(shipLength));

            int shieldCapacity;
            file.read((char*)&shieldCapacity, sizeof(shieldCapacity));

            float speed;
            file.read((char*)&speed, sizeof(speed));


            int totalWeapons;
            file.read((char*)&totalWeapons, sizeof(totalWeapons));

            vector<Weapon> inventory(totalWeapons);
            for (int j = 0; j < totalWeapons; ++j) {
                int weaponNameLength;
                file.read((char*)&weaponNameLength, sizeof(weaponNameLength));
                vector<char> weaponsVec(weaponNameLength);
                file.read(&weaponsVec[0], weaponNameLength);
                string weaponsName(weaponsVec.begin(), weaponsVec.end()-1);

                int power;
                file.read((char*)&power, sizeof(power));

                float consumption;
                file.read((char*)&consumption, sizeof(consumption));

                inventory[j].SetType(weaponsName);
                inventory[j].SetPower(consumption);
                inventory[j].SetScale(power);
            }
            shipList.emplace_back(name, _class, shipLength, shieldCapacity, speed, inventory);
        }
    }
    if (option == 2 || option == 3) {
        ifstream file("enemyships.shp", ios::in | ios::binary);
        int numShips;
        file.read((char *) &numShips, sizeof(numShips));
        for (int i = 0; i < numShips; ++i) {
            int nameLength;
            file.read((char *) &nameLength, sizeof(nameLength));
            vector<char> nameVec(nameLength);
            file.read(&nameVec[0], nameLength);
            string name(nameVec.begin(), nameVec.end()-1);

            int classLength;
            file.read((char *) &classLength, sizeof(classLength));
            vector<char> classVec(classLength);
            file.read(&classVec[0], classLength);
            string _class(classVec.begin(), classVec.end()-1);


            short shipLength;
            file.read((char *) &shipLength, sizeof(shipLength));

            int shieldCapacity;
            file.read((char *) &shieldCapacity, sizeof(shieldCapacity));

            float speed;
            file.read((char *) &speed, sizeof(speed));


            int totalWeapons;
            file.read((char *) &totalWeapons, sizeof(totalWeapons));

            vector<Weapon> inventory(totalWeapons);
            for (int j = 0; j < totalWeapons; ++j) {
                int weaponNameLength;
                file.read((char *) &weaponNameLength, sizeof(weaponNameLength));
                vector<char> weaponsVec(weaponNameLength);
                file.read(&weaponsVec[0], weaponNameLength);
                string weaponsName(weaponsVec.begin(), weaponsVec.end()-1);

                int power;
                file.read((char *) &power, sizeof(power));

                float consumption;
                file.read((char *) &consumption, sizeof(consumption));

                inventory[j].SetType(weaponsName);
                inventory[j].SetPower(consumption);
                inventory[j].SetScale(power);
            }
            shipList.emplace_back(name, _class, shipLength, shieldCapacity, speed, inventory);
        }
    }
    else{
        cout << "How did you get here?";
    }

    cout << "1. Print all ships" << endl;
    cout << "2. Starship with the strongest weapon" << endl;
    cout << "3. Strongest starship overall" << endl;
    cout << "4. Weakest ship (ignoring unarmed)" << endl;
    cout << "5. Unarmed ships" << endl;

    cin >> option;

    if (option == 1){
        for (long unsigned int i = 0; i < shipList.size(); ++i) {
            shipList[i].PrintShip();
        }
    }
    else if (option == 2){
        Spaceship max = shipList[0];
        for (long unsigned int i = 1; i < shipList.size(); ++i) {
            if (shipList[i].getMaxWeapon() > max.getMaxWeapon()){
                max = shipList[i];
            }
        }
        max.PrintShip();
    }
    else if (option == 3){
        Spaceship max = shipList[0];
        for (long unsigned int i = 1; i < shipList.size(); ++i) {
            if (shipList[i].getTotalWeapons() > max.getTotalWeapons()){
                max = shipList[i];
            }
        }
        max.PrintShip();
    }
    else if (option == 4){
        Spaceship min = shipList[0];
        for (long unsigned int i = 1; i < shipList.size(); ++i) {
            if (shipList[i].getTotalWeapons() < min.getTotalWeapons() && !(shipList[i].isUnarmed())){
                min = shipList[i];
            }
        }
        min.PrintShip();
    }
    else if (option == 5){
        for (long unsigned int i = 0; i < shipList.size(); ++i) {
            if (shipList[i].isUnarmed()){
                shipList[i].PrintShip();
            }
        }
    }
    else{
        cout << "How did you get here?";
    }

    return 0;
}