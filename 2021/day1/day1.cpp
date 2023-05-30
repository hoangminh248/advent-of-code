#include <bits/stdc++.h>

using namespace std;

int solvePart1 (){
    int countIncrease {0};  
    ifstream inputFile("D:/DEV/Project/AOC/2021/day1/input.txt");
    if (inputFile.fail())
	    cout << "Failed to open this file!" << endl;
    else{
        int previousNum {-1};
        int currentNum {-1};
        inputFile >> previousNum;
        inputFile >> currentNum;
        while (!inputFile.eof()){
            if (currentNum > previousNum) countIncrease ++;
            previousNum = currentNum;
            inputFile >> currentNum;
        }
    }
    return countIncrease;
}

int solvePart2 (){
    ifstream inputFile("D:/DEV/Project/AOC/2021/day1/input.txt");
    int countIncrease {0};
    if (inputFile.fail())
	    cout << "Failed to open this file!" << endl;
    else{
        int headNum {-1}; // first number of the previous sum
        int tailNum {-1}; // last number of the current sum  
        int middle1 {-1}; // first number in 2 middle elements between 2 sum
        int middle2 {-1}; // second number in 2 middle elements between 2 sum  
        inputFile >> headNum >>middle1 >> middle2 >> tailNum;
        while(!inputFile.eof()){
            if (tailNum > headNum) countIncrease ++;
            headNum = middle1;
            middle1 = middle2;
            middle2 = tailNum;
            inputFile >> tailNum;
        }
        headNum = middle1;
        if (tailNum > headNum) countIncrease ++; // check the 2 last sum
    }
    return countIncrease;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << solvePart2();
    return 0;
}