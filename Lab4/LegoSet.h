//
// Created by Zach on 10/24/2020.
//

#ifndef LAB4_LEGOSET_H
#define LAB4_LEGOSET_H
#include "string"


class LegoSet {
    std::string setNumber;
    std::string setTheme;
    std::string setName;
    unsigned int totalParts;
    unsigned int totalMinifigs;
    double setPrice;
public:
    //Constructors
    LegoSet();
    LegoSet(std::string setNum, std::string theme, std::string name,unsigned int minifigs, unsigned int parts, double price);



    //Getters
    std::string GetSetNumber();
    std::string GetSetTheme();
    std::string GetSetName();
    unsigned int GetTotalMinifigs() const;
    unsigned int GetTotalParts() const;
    double GetSetPrice() const;



};


#endif //LAB4_LEGOSET_H
