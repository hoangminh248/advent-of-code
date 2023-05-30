#include <bits/stdc++.h>

using namespace std;

int solvePart1 (){
    ifstream inputFile("D:/AOC/2015/day1/input.txt");
    if (inputFile.fail())
	    cerr << "Failed to open this file!" << endl;
    else{
        int floor = 0;
        char s;
        while (!inputFile.eof())
        {
            inputFile >> s;
            if ( s == '(')
                floor++;
            else
                floor--;
        }
        return floor-1;
    }
}
int solvePart2(){
    ifstream inputFile("D:/AOC/2015/day1/input.txt");
    if (inputFile.fail())
	    cerr << "Failed to open this file!" << endl;
    else{
        int floor = 0, index = 1;
        char s;
        while (!inputFile.eof())
        {
            inputFile >> s;
            if (s == '(')
                floor++;
            else
                floor--;
            if (floor == -1)
                return index;
            index++;
        }
    }
    return -1;
}
    
int main()
{
    cout << solvePart1();
    cout << solvePart2();
    return 0;
}