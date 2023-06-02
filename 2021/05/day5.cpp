#include <bits/stdc++.h>

using namespace std;

struct Point {
    int x,y;
};
struct Line{
    Point h; // head
    Point t; // tail
};

bool isVertical (Line L){
    if (L.h.x == L.t.x)
        return 1;
    return 0;
}
bool isHorizontal (Line L){
    if (L.h.y == L.t.y)
        return 1;
    return 0 ;
}
bool isOnSameLine(Line L1, Line L2){
    if(isVertical(L1) && isVertical(L2))
        return 1;
    else if (isHorizontal(L1)&& isHorizontal(L2))
        return 1;
    return 0;
}
int overlapPoint (Line L1, Line L2){
    if(isOnSameLine(L1,L2)){
        
    }else{
        return 0;
    }
}

int solvePart1 (){
    int overlapPoints {0};
    vector <Line> input ;
    ifstream inputFile("D:/DEV/Project/AOC/2021/day5/input.txt");
    if (inputFile.fail())
	    cout << "Failed to open this file!" << endl;
    else{
        while (!inputFile.eof())
        {
            Point P1 ,P2;
            Line L;
            inputFile >> P1.x >> P1.y >> P2.x >> P2.y;
            L.h =P1;
            L.t = P2;
            input.push_back (L);
        }
    }
    for (int i =0; i < input.size();i++){
        for (int j=i+1; j <input.size(); j++){
            if(input[i])
        }
    }
    return 0;
}
int solvePart2(){
    ifstream inputFile("D:/DEV/Project/AOC/2021/day5/input.txt");
    if (inputFile.fail())
	    cout << "Failed to open this file!" << endl;
    else{
        while (!inputFile.eof())
        {
        
        }
    }
}
    
int main()
{
    solvePart1();
    return 0;
}