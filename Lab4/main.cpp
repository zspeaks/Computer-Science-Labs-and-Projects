#include <iomanip>
#include <iostream>
#include "LegoSet.h"
//#include "extrafile.h"
#include "vector"
#include "fstream"
using namespace std;
LegoSet MostExpensive(vector<LegoSet> l);
LegoSet MostPieces(vector<LegoSet> l);
vector<LegoSet> SearchName(vector<LegoSet> l, const string& s);
vector<LegoSet> SearchTheme(vector<LegoSet> l, const string& s);
void PartInfo(const vector<LegoSet>& l);
vector<LegoSet> PriceInfo(vector<LegoSet> l);
LegoSet MostMinis(vector<LegoSet> l);
void BuyAll(const vector<LegoSet>& l);
void DispInfo(LegoSet s);
void DispReducedInfo(LegoSet s);
vector<LegoSet> LoadFile(const string& name);
vector<LegoSet> LoadFile(vector<LegoSet> prevSets,const string& name);


int main()
{
    cout << std::fixed << setprecision(2);
    cout << "Which file(s) to open?\n";
    cout << "1. lego1.csv" << endl;
    cout << "2. lego2.csv" << endl;
    cout << "3. lego3.csv" << endl;
    cout << "4. All 3 files" << endl;
    int option;
    cin >> option;

    /*======= Load data from file(s) =======*/


    vector<LegoSet> legos;
    if (option == 1){
        legos = LoadFile("lego1.csv");
    }
    else if (option == 2){
        legos = LoadFile("lego2.csv");
    }
    else if (option == 3){
        legos = LoadFile("lego3.csv");
    }
    else if (option == 4){
        legos = LoadFile("lego1.csv");
        legos = LoadFile(legos,"lego2.csv");
        legos = LoadFile(legos, "lego3.csv");
    }
    else {
        throw out_of_range("Error, selection was out of range");
    }
    /*======= Print out how many sets were loaded =======*/
    cout << "Total number of sets: " << legos.size() << endl;

    /*
    cout << "1. Most Expensive set" << endl;
    cout << "2. Largest piece count" << endl;
    cout << "3. Search for set name containing..." << endl;
    cout << "4. Search themes..." << endl;
    cout << "5. Part count information" << endl;
    cout << "6. Price information" << endl;
    cout << "7. Minifigure information" << endl;
    cout << "8. If you bought one of everything..." << endl;
    cout << "0. Exit" << endl;

    */
    int choice;
    cin >> choice;
    cin.get();  // Clear newline character for any later input
    cout << endl;

    /*======= Based on the choice, execute the appropriate task and show the results =======*/
    if (choice == 1){
        LegoSet expensiveLegos = MostExpensive(legos);
        cout << "The most expensive set is:" << endl;
        DispInfo(expensiveLegos);
    }
    else if (choice == 2){
        LegoSet mostLegos = MostPieces(legos);
        cout << "The set with the highest parts count:" << endl;
        DispInfo(mostLegos);
    }
    else if (choice == 3) {
        string userInput;
        //cout << "What would you like to search for?" << endl;
        getline(cin, userInput);
        vector<LegoSet> searchLegos = SearchName(legos, userInput);
        if (searchLegos.empty()) {
            cout << "No sets found matching that search term" << endl;
        }
        else {
            cout << "Sets matching \"" << userInput << "\":" << endl;
            for (auto & searchLego : searchLegos) {
                DispReducedInfo(searchLego);
            }
        }
    }
    else if (choice == 4) {
        string userInput;
        //cout << "What would you like to search for?" << endl;
        getline(cin, userInput);
        vector<LegoSet> searchLegos = SearchTheme(legos, userInput);
        if (searchLegos.empty()) {
            cout << "No sets found matching that search term" << endl;
        }
        else {
            cout << "Sets matching \"" << userInput << "\":" << endl;
            for (auto & searchLego : searchLegos) {
                DispReducedInfo(searchLego);
            }
        }
    }
    else if (choice == 5){
        PartInfo(legos);
    }
    else if (choice == 6){
    vector<LegoSet> pricyLegos = PriceInfo(legos);
    cout << "Least expensive set:" << endl;
    DispInfo(pricyLegos[0]);
    cout << "Most expensive set:" << endl;
    DispInfo(pricyLegos[1]);
    }
    else if (choice == 7){
    LegoSet mostminis = MostMinis(legos);
    cout << "Set with the most minifigures: " << endl;
    DispInfo(mostminis);
    }
    else if (choice == 8){
        BuyAll(legos);
    }
    else if (choice == 0){
        // Do nothing and let program end
    }
    else {
        throw out_of_range("Error, selection was out of range");
    }
    return 0;
}

LegoSet MostExpensive(vector<LegoSet> l){
    LegoSet currentMax = l[0];
    for (auto & i : l) {
        if (i.GetSetPrice() > currentMax.GetSetPrice()){
            currentMax = i;
        }
    }
    return currentMax;
}

LegoSet MostPieces(vector<LegoSet> l){
    LegoSet currentMax = l[0];
    for (auto & i : l) {
        if (i.GetTotalParts() > currentMax.GetTotalParts()){
            currentMax = i;
        }
    }
    return currentMax;
}

vector<LegoSet> SearchName(vector<LegoSet> l, const string& s){
    vector<LegoSet> returnVec;
    for (auto & i : l) {
        if (i.GetSetName().find(s) != string::npos){
            returnVec.push_back(i);
        }
    }
    return returnVec;
}

vector<LegoSet> SearchTheme(vector<LegoSet> l, const string& s){
    vector<LegoSet> returnVec;
    for (auto & i : l) {
        if (i.GetSetTheme().find(s) != string::npos){
            returnVec.push_back(i);
        }
    }
    return returnVec;
}

void PartInfo(const vector<LegoSet>& l){
    unsigned int sum = 0;
    for (auto & i : l) {
        sum += i.GetTotalParts();
    }
    cout << "Average part count for " << l.size() << " sets: " << sum/l.size() << endl;
}
vector<LegoSet> PriceInfo(vector<LegoSet> l){
    LegoSet currentMax = l[0];
    double sum = 0;
    for (auto & i : l) {
        sum += i.GetSetPrice();
        if (i.GetSetPrice() > currentMax.GetSetPrice()){
            currentMax = i;
        }
    }
    LegoSet currentMin = l[0];
    for (auto & i : l) {
        if (i.GetSetPrice() < currentMin.GetSetPrice()){
            currentMin = i;
        }
    }
    cout <<  "Average price for " << l.size() << " sets: $" << sum/l.size() << endl;
    vector<LegoSet> returnVector = {currentMin, currentMax};
    return returnVector;
}

LegoSet MostMinis(vector<LegoSet> l){
    LegoSet currentMax = l[0];
    int sum = 0;
    for (auto & i : l) {
        sum += i.GetTotalMinifigs();
        if (i.GetTotalMinifigs() > currentMax.GetTotalMinifigs()){
            currentMax = i;
        }
    }
    cout <<  "Average number of minifigures: "  << sum/l.size() << endl;
    cout << endl;
    return currentMax;
}

void BuyAll(const vector<LegoSet>& l){
    double priceSum = 0;
    unsigned int pieceSum = 0;
    unsigned int miniSum = 0;
    for (auto & i : l) {
        miniSum += i.GetTotalMinifigs();
        priceSum += i.GetSetPrice();
        pieceSum += i.GetTotalParts();
    }

    cout << "If you bought one of everything..." << endl;
    cout << "It would cost: $" << priceSum << endl;
    cout << "You would have " << pieceSum << " pieces in your collection" << endl;
    cout << "You would have an army of " << miniSum <<" minifigures!" << endl;
}

void DispInfo(LegoSet s){
    cout << "Name: " << s.GetSetName() << endl;
    cout << "Number: " << s.GetSetNumber() << endl;
    cout << "Theme: " << s.GetSetTheme() << endl;
    cout << "Price: $" << s.GetSetPrice() << endl;
    cout << "Minifigures: " << s.GetTotalMinifigs() << endl;
    cout << "Piece count: " << s.GetTotalParts() << endl;
}

void DispReducedInfo(LegoSet s){
    cout << s.GetSetNumber() << " " << s.GetSetName() << " $" << s.GetSetPrice() << endl;
}

vector<LegoSet> LoadFile(const string& name){
    ifstream file;
    file.open(name);
    string line;
    vector<LegoSet> returnVec;
    unsigned int lineNumber = 0;
    while (getline(file,line)){
        unsigned int infoCount = 0;
        unsigned int placeCount = 0;
        if (lineNumber != 0){
            string setNumber;
            string theme;
            string setName;
            string minifigs;
            string pieces;
            string price;
            for (long unsigned int i = 0; i < line.size(); ++i) {
                if (line[i] == ',') {
                    string s;
                    if (placeCount == 0){
                        s = line.substr(placeCount, i - placeCount);
                    }
                    else{
                        s = line.substr(placeCount + 1, i - (placeCount + 1));
                    }
                    placeCount = i;
                    if (infoCount == 0) {
                        infoCount++;
                        setNumber = s;
                    } else if (infoCount == 1) {
                        infoCount++;
                        theme = s;
                    } else if (infoCount == 2) {
                        infoCount++;
                        setName = s;
                    } else if (infoCount == 3) {
                        infoCount++;
                        minifigs = s;
                    } else if (infoCount == 4) {
                        pieces = s;
                        s =line.substr(placeCount +1, line.size());
                        infoCount = 0;
                        price = s;
                    }  else {
                        cout << "How did you get here?" << endl;
                    }
                }
            }
            unsigned int parts = stoi(pieces);
            unsigned int minis = stoi(minifigs);
            double cost = stod(price);
            LegoSet newSet = LegoSet(setNumber, theme, setName, minis, parts, cost);
            returnVec.push_back(newSet);
        }
        lineNumber++;
    }
    return returnVec;
}

vector<LegoSet> LoadFile(vector<LegoSet> prevSets,const string& name){
    ifstream file;
    file.open(name);
    string line;
    unsigned int lineNumber = 0;
    while (getline(file,line)){
        unsigned int infoCount = 0;
        unsigned int placeCount = 0;
        if (lineNumber != 0){
            string setNumber;
            string theme;
            string setName;
            string minifigs;
            string pieces;
            string price;
            for (long unsigned int i = 0; i < line.size(); ++i) {
                if (line[i] == ',') {
                    string s;
                    if (placeCount == 0){
                        s = line.substr(placeCount, i - placeCount);
                    }
                    else{
                        s = line.substr(placeCount + 1, i - (placeCount + 1));
                    }
                    placeCount = i;
                    if (infoCount == 0) {
                        infoCount++;
                        setNumber = s;
                    } else if (infoCount == 1) {
                        infoCount++;
                        theme = s;
                    } else if (infoCount == 2) {
                        infoCount++;
                        setName = s;
                    } else if (infoCount == 3) {
                        infoCount++;
                        minifigs = s;
                    } else if (infoCount == 4) {
                        pieces = s;
                        s =line.substr(placeCount +1, line.size());
                        infoCount = 0;
                        price = s;
                    }  else {
                        cout << "How did you get here?" << endl;
                    }
                }
            }
            unsigned int parts = stoi(pieces);
            unsigned int minis = stoi(minifigs);
            double cost = stod(price);
            LegoSet newSet = LegoSet(setNumber, theme, setName, minis, parts, cost);
            prevSets.push_back(newSet);
        }
        lineNumber++;
    }
    return prevSets;
}


