#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int priority (char target) {
    if (target <= 90){
        return target-38;
    }
    else
        return target-96;
}
char findCommonChar (string part1,string part2){
    for (int i=0; i < part1.length(); i++){
        for (int j = 0 ; j < part2.length();j++){
            if(part1[i]==part2[j])
            return part1[i];
        }
    }
}
char findCommonChar3 (string part1,string part2,string part3){
    for (int i=0; i < part1.length(); i++){
        for (int j = 0 ; j < part2.length();j++){
            if(part1[i]==part2[j])
            {
                for (int z =0 ; z< part3.length();z++){
                    if (part1[i]==part3[z])
                    return part1[i];
                }
            }
        }
    }
}
int solution_part1 (){
    char n[255];
    int score = 0 ;
    string  compartment1,compartment2;
    ifstream fileInput("D:/DEV/Project/AOC/day3/input.txt");
    if (fileInput.fail())
	    cout << "Failed to open this file!" << endl;
    while(!fileInput.eof()){
        fileInput.getline(n,255);
        string input = n;
        compartment1="";
        compartment2="";
        for (int i =0 ; i < input.length()/2; i++){
            compartment1 += input[i];
        } 
        for (int i = input.length()/2;i < input.length() ; i++){
            compartment2 += input[i];
        } 
        score += priority(findCommonChar(compartment1,compartment2));
    }
    return score;
}
int solution_part2 (){
    char n[255];
    int score = 0 ;
    string  pack1,pack2,pack3;
    ifstream fileInput("D:/DEV/Project/AOC/day3/input.txt");
    if (fileInput.fail())
	    cout << "Failed to open this file!" << endl;
    while(!fileInput.eof()){
        fileInput.getline(n,255);
        pack1=n;
        fileInput.getline(n,255);
        pack2=n;
        fileInput.getline(n,255);
        pack3=n;
        score += priority(findCommonChar3(pack1,pack2,pack3));
    }
    return score;
}
int main(){
    cout <<solution_part2();  
    return 0;
}