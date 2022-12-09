#include <iostream>
#include <string>
#include <fstream>
#include<math.h>
#include <vector>
using namespace std;

vector <pair <int,int>> positionsT;
vector <pair <int,int>> positions9;
pair <int,int> T (0,0);
pair <int,int> H (0,0);
pair <int,int> snake[10];

bool isContained(vector <pair <int,int>> V, pair <int,int> X){
    for (int i = 0 ; i < V.size(); i++){
        if(X.first == V[i].first&&X.second == V[i].second)
            return true;
    }
    return false;
}
string TypeDistance(pair<int,int>* T,pair<int,int>*H){
    double distance = sqrt(pow((T->first-H->first),2)+pow((T->second-H->second),2)); 
    if(distance>sqrt(2))
    {
        if(distance == 2) return "Line";
        else{
            if(H->first > T->first && H->second > T->second) return "Cross 9";
            else if(H->first > T->first && H->second < T->second) return "Cross 3";
            else if(H->first < T->first && H->second > T->second) return "Cross 7";
            else return "Cross 1";
        }
    }else
        return "Touch";
}
void moveOneStep(char direction,pair<int,int>* X){
    if(direction == 'R')
        X->first++;
    else if(direction =='L')
        X->first--;
    else if(direction =='U')
        X->second++;
    else
        X->second--;
}
void moveDiagonal(int direction,pair<int,int>* X){
    if(direction == 1)
    {
        moveOneStep('L',X);
        moveOneStep('D',X);
    }
    else if(direction ==3)
    {
        moveOneStep('R',X);
        moveOneStep('D',X);
    }
    else if(direction ==7)
    {
        moveOneStep('L',X);
        moveOneStep('U',X);
    }
    else
    {
        moveOneStep('R',X);
        moveOneStep('U',X);
    }
} 
void moveTtotouchH(pair<int,int>* T,pair<int,int>* H){
    if (TypeDistance(T,H)=="Touch"){} //do nothing
    else if(TypeDistance(T,H)=="Line") {
        //find the proper direction to move T
        if(H->first > T->first) moveOneStep('R',T);
        else if(H->first < T->first) moveOneStep('L' ,T);
        else if (H->second > T->second) moveOneStep('U',T);
        else moveOneStep('D',T);
    }
    else{
        if(TypeDistance(T,H)=="Cross 9") moveDiagonal(9,T);
        else if(TypeDistance(T,H)=="Cross 7")moveDiagonal(7,T);
        else if(TypeDistance(T,H)=="Cross 3")moveDiagonal(3,T);
        else moveDiagonal(1,T);
    }
}
void solution1(){
    char n[255];
    string input;
    ifstream fileInput("D:/DEV/Project/AOC/day9/input.txt");
    if (fileInput.fail())
	    cout << "Failed to open this file!" << endl;
    while(!fileInput.eof()){
        fileInput.getline(n,255);
        input=n;
        char direction = input[0];
        int steps = stoi(input.substr(2));
        while(steps>0){
            moveOneStep(direction,&H);
            moveTtotouchH(&T,&H);
            if(!isContained(positionsT,T)) positionsT.push_back(T);
            steps--;
        }
    }
}
void solution2(){
    char n[255];
    string input;
    ifstream fileInput("D:/DEV/Project/AOC/day9/input.txt");
    if (fileInput.fail())
	    cout << "Failed to open this file!" << endl;
    while(!fileInput.eof()){
        fileInput.getline(n,255);
        input=n;
        char direction = input[0];
        int steps = stoi(input.substr(2));
        while(steps>0){
            moveOneStep(direction,&snake[0]);
            for(int i= 1; i < 10; i++){
                moveTtotouchH(&snake[i],&snake[i-1]);
            }
            if(!isContained(positions9,snake[9])) positions9.push_back(snake[9]);
            steps--;
        }
    }
}

int main(){
    //initial snake
    for (int i = 0 ; i < 10;i++){
        snake[i] =make_pair(0,0);
    }
    solution2();
    cout << positions9.size() << endl;
    return 0;
}