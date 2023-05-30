#include <bits/stdc++.h>

using namespace std;

int solvePart1 (){
    string direction {};
    int magnitude {0};
    int depth {0};
    int horizontalPosition {0};
    ifstream inputFile("D:/DEV/Project/AOC/2021/day2/input.txt");
    if (inputFile.fail())
	    cout << "Failed to open this file!" << endl;
    else{
        while (!inputFile.eof())
        {
            inputFile >> direction >> magnitude;
            if (direction[0]=='f'){
                horizontalPosition += magnitude;
            }else if (direction[0] =='d'){
                depth += magnitude;
            }
            else{
                depth -=magnitude;
            }
        }
    }
    return depth * horizontalPosition;
}
int solvePart2(){
    string direction {};
    int magnitude {0};
    int depth {0};
    int horizontalPosition {0};
    int aim {0};
    ifstream inputFile("D:/DEV/Project/AOC/2021/day2/input.txt");
    if (inputFile.fail())
	    cout << "Failed to open this file!" << endl;
    else{
        while (!inputFile.eof())
        {
            inputFile >> direction >> magnitude;
            if (direction[0]=='f'){
                horizontalPosition += magnitude;
                depth += magnitude*aim;
            }else if (direction[0] =='d'){
                aim += magnitude;
            }
            else{
                aim -=magnitude;
            }
        }
    }
    return depth * horizontalPosition;
}
int main(){
    cout << solvePart2 ();
    return 0;
}