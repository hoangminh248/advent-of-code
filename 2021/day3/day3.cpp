#include <bits/stdc++.h>

using namespace std;

int solvePart1 (){
    string row {""} ; 
    int amountOfBit0 [12] = {0,0,0,0,0,0,0,0,0,0,0,0}; // write for loop is more readable
    int gammaRate{0};
    int epsilonRate{0};
    int rows {0} ; // amount of rows of input 
    ifstream inputFile("D:/DEV/Project/AOC/2021/day3/input.txt");
    if (inputFile.fail())
	    cout << "Failed to open this file!" << endl;
    else{
        while (!inputFile.eof())
        {
            // Find amount of bits '0' array
            inputFile >> row;
            for (int i = 0 ; i < row.length(); i++){
                if(row[i]=='0') amountOfBit0[i]++;
            }
            rows ++;
        }
    }
    // Check the amount of bits '0' of every column and calcualte gammaRate, epsilonRate
    for (int i= 0; i < 12; i++){
        if (amountOfBit0[i]>rows/2){
            epsilonRate += pow(2,11-i);
        }else{
            gammaRate += pow(2,11-i);
        }
    }
    return gammaRate*epsilonRate;
}

int solvePart2(){
    string row {""} ;
    vector <string> input ; 
    int oxygen {0};
    int co2 {0};
    ifstream inputFile("D:/DEV/Project/AOC/2021/day3/input.txt");
    if (inputFile.fail())
	    cout << "Failed to open this file!" << endl;
    else{
        while (!inputFile.eof())
        {
            // insert input into INPUT VECTOR
            inputFile >> row;
            input.push_back(row);
        }
    }
    //Filter the Input Vector 
    int numBit0CurrentOfOxygen {0};
    int numBit0CurrentOfCO2 {0};
    char bitCriteriaOfOxygen {};
    char bitCriteriaOfCO2 {};
    int totalNumCurrentOfOxygen {0};
    int totalNumCurrentOfCO2 {0};
    bool checkTotalEqual1Oxygen {0};
    bool checkTotalEqual1CO2 {0};
    for (int col=0; col <12 ;col++){
        for (int i = 0; i < input.size();i++)
        {
            if(col == 0 ){
                totalNumCurrentOfOxygen = input.size();
                totalNumCurrentOfCO2 = input.size();
                if(input[i][0]== '0'){
                    numBit0CurrentOfOxygen ++;
                    numBit0CurrentOfCO2 ++;
                }     
            }else{
                if (input[i][input[i].length()-1] != 'O' && input[i][input[i].length()-1] != 'C'){
                    if (input[i][col-1] == bitCriteriaOfOxygen)
                        input[i] += 'O';
                    else    
                        input[i] += 'C';
                }
                if (input[i][input[i].length()-1] == 'O'){
                    if (input[i][col-1]==bitCriteriaOfOxygen ){
                        totalNumCurrentOfOxygen ++;
                        if(input[i][col]=='0')
                            numBit0CurrentOfOxygen++;
                    }else{
                        if(!checkTotalEqual1Oxygen){
                            input.erase(input.begin()+i);
                            i--;
                        }
                    }
                }else{
                    if (input[i][col-1]==bitCriteriaOfCO2 ){
                        totalNumCurrentOfCO2 ++;
                        if(input[i][col]=='0')
                            numBit0CurrentOfCO2++;
                    }else{
                        if(!checkTotalEqual1CO2){
                            input.erase(input.begin()+i);
                            i--;
                        }
                    }
                }
            }
        }
        if(numBit0CurrentOfOxygen > totalNumCurrentOfOxygen/2) bitCriteriaOfOxygen = '0';
        else bitCriteriaOfOxygen = '1';
        numBit0CurrentOfOxygen = 0;
        
         
        if(numBit0CurrentOfCO2 > totalNumCurrentOfCO2/2) bitCriteriaOfCO2 = '1';
        else bitCriteriaOfCO2 ='0';
        numBit0CurrentOfCO2 = 0;

        if(totalNumCurrentOfCO2 == 1) {
            checkTotalEqual1CO2 = 1;
        }
        if (totalNumCurrentOfOxygen == 1){
            checkTotalEqual1Oxygen = 1;
        }
        if(col==11){
            for (int i=0; i< input.size();i++){
                if(input[i][input[i].length()-1] == 'O' && input[i][col]!= bitCriteriaOfOxygen)
                    input.erase(input.begin()+i);
                if(input[i][input[i].length()-1] == 'C' && input[i][col]!= bitCriteriaOfCO2)
                    input.erase(input.begin()+i);
            }
        }
        totalNumCurrentOfCO2 = 0;
        totalNumCurrentOfOxygen = 0;
    }
    // Find oxygen and CO2 
    for (int i= 0; i < input.size() ;i++){
        if (input[i][input[i].length()-1] == 'O')
            for(int j=0; j < input[i].length()-1;j++)
                if(input[i][j]=='1') oxygen += pow(2,11-j);
        if (input[i][input[i].length()-1] == 'C')
            for(int j=0; j < input[i].length()-1;j++)
                if(input[i][j]=='1') co2 += pow(2,11-j);
    }

    return oxygen*co2 ;
}
    
int main(){
    //cout << solvePart1();
    cout << solvePart2 ();
    return 0;
}