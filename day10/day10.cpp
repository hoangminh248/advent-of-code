#include <bits/stdc++.h>
using namespace std;

int circle = 0;
int X= 1 ;
int signalStrength=0;
char CRT[6][40];


pair <int,char> parseInput(string input){
    pair <int,char> rs;
    if(input[0]=='a'){
        rs.second='a';
        rs.first= stoi(input.substr(5));
    }else{
        rs.second='n';
        rs.first=0;
    }
    return rs;
}
void updateSignal(){
    if (circle==20||circle==60||circle==100||circle==140||circle==180||circle==220){
        signalStrength+=(X*circle);
    }
}
void drawCRT(){
    if(circle%40>=X-1 && circle%40<=X+1){
        CRT[circle/40][circle%40]='#';
    }else{
        CRT[circle/40][circle%40]='.';
    }
}
void solution1(){
    char n[255];
    string input;
    ifstream fileInput("D:/DEV/Project/AOC/day10/input.txt");
    if (fileInput.fail())
	    cout << "Failed to open this file!" << endl;
    while(!fileInput.eof()){
        fileInput.getline(n,255);
        input = n;
        if(parseInput(input).second=='a'){
            for(int i = 0 ; i<2;i++){
                circle++;
                updateSignal();
            }
        }else{
            circle++;
            updateSignal();
        }
        X+=parseInput(input).first;
    }
}
void solution2(){
    char n[255];
    string input;
    ifstream fileInput("D:/DEV/Project/AOC/day10/input.txt");
    if (fileInput.fail())
	    cout << "Failed to open this file!" << endl;
    while(!fileInput.eof()){
        fileInput.getline(n,255);
        input = n;
        if(parseInput(input).second=='a'){
            for(int i = 0 ; i<2;i++){
                drawCRT();
                circle++;              
            }
        }else{
            drawCRT();
            circle++;
            
        }
        X+=parseInput(input).first;
    }
}

int main(){
    solution2();
    for (int i =0 ; i<6; i++){
        for (int j= 0 ; j<40; j++)
            cout << CRT[i][j];
        cout << endl;
    }
    return 0 ;
}