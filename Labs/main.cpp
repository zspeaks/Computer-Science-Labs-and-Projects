#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
/*
int main() {
    // Creates the title of the table
    std::string titleString;
    std::cout << "Enter a title for the data:" << std::endl;
    std::getline(std::cin, titleString);
    std::cout << "You entered: " << titleString << std::endl;
    // Column headers
    std::string columnOneString;
    std::string columnTwoString;
    std::cout << "Enter the column 1 header:" << std::endl;
    std::getline(std::cin, columnOneString);
    std::cout << "You entered: " << columnOneString << std::endl;
    std::cout << "Enter the column 2 header:" << std::endl;
    std::getline(std::cin, columnTwoString);
    std::cout << "You entered: " << columnTwoString << std::endl;
    // Loop for data point input
    std::string userFullInput;
    std::vector<std::string> userInputStrings;
    std::vector<int> userInputInts;
    std::string substring;
    std::string tempIntString;
    int splitIndex;
    int commaCount;
    do {
        std::cout << "Enter a data point (-1 to stop input):" << std::endl;
        std::getline(std::cin, userFullInput);
        if (userFullInput == "-1"){
            break;
        }
        else {
            commaCount = 0;
            for(int i = 0;i<userFullInput.size();i++){
                if(userFullInput[i] == ','){
                    commaCount++;
                    splitIndex = i;
                }
            }
            if(commaCount == 0){
                std::cout << "Error: No comma in string." << std::endl;
            }
            else if (commaCount > 1){
                std::cout << "Error: Too many commas in input." << std::endl;
            }
            else{
                try {
                    substring = userFullInput.substr(0,splitIndex);
                    tempIntString = userFullInput.substr(splitIndex+2,userFullInput.size());
                    userInputInts.push_back(std::stoi(tempIntString));
                    userInputStrings.push_back(substring);
                    std::cout << "Data string: " << substring << std::endl;
                    std::cout << "Data integer: " << tempIntString << std::endl;
                }
                catch (std::invalid_argument) {
                    std::cout << "Error: Comma not followed by an integer." << std::endl;
                }
            }
        }

    } while (userFullInput != "-1");
    // Prints table and histograms
    std::cout << std::endl;
    std::cout << std::setw(33) << titleString << std::endl;
    std::cout << std::setw(20) << std::left << columnOneString << "|";
    std::cout << std::setw(23) << std::right << columnTwoString << std::endl;
    std::cout << "--------------------------------------------" << std::endl;
    for(int i = 0;i<userInputStrings.size();i++){
        std::cout << std::setw(20) << std::left << userInputStrings[i] << "|";
        std::cout << std::setw(23) << std::right << userInputInts [i] << std::endl;
    }

    std::cout << std::endl;
    for(int i = 0;i<userInputStrings.size();i++){
        std::cout << std::setw(20) << userInputStrings[i] << " ";
        for(int j=0; j < userInputInts[i]; j++){
            std::cout << "*";
        }
        std::cout << std::endl;
    }

    return 0;
}
*/