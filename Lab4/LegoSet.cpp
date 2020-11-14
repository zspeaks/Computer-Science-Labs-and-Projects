//
// Created by Zach on 10/24/2020.
//

#include "LegoSet.h"


LegoSet::LegoSet(std::string setNum, std::string theme, std::string name,unsigned int minifigs, unsigned int parts,  double price) {
    setNumber = std::move(setNum);
    setTheme = std::move(theme);
    setName = std::move(name);
    totalMinifigs = minifigs;
    totalParts = parts;
    setPrice = price;
}
LegoSet::LegoSet() {
    setNumber = std::string("No Value");
    setTheme = std::string("No Value");
    setName = std::string("No Value");
    totalParts = 0;
    setPrice = -1;
    totalMinifigs = 0;
}



std::string LegoSet::GetSetNumber() {
    return std::string(setNumber);
}

std::string LegoSet::GetSetTheme() {
    return std::string(setTheme);
}

std::string LegoSet::GetSetName() {
    return std::string(setName);
}

unsigned int LegoSet::GetTotalMinifigs() const {
    return totalMinifigs;
}

unsigned int LegoSet::GetTotalParts() const {
    return totalParts;
}

double LegoSet::GetSetPrice() const {
    return setPrice;
}
