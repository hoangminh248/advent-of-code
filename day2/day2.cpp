#include <iostream>
#include <string>
#include <fstream>
using namespace std;


// X : Rock , Y : Paper , Z : Scissors
int calculate_score (char opponent, char self){
    if (opponent == self){
        return 3  + (self-87) ;
    }else{
        switch(self){
            case 'X':
            {
                if(opponent-'X'==1)
                    return 1;
                else
                    return 7;
                break;
            }
            case 'Y':
            {
                if (opponent-'Y'==1)
                    return 2;
                else
                    return 8;
                break;
            }
            case 'Z':
            {
                if (opponent-'Z'==-2)
                    return 3;
                else
                    return 9;
                break;
            }
        }
    }
}

char properTurn(char opponent, char typeResult){
    if (typeResult == 'Y'){
        return opponent;
    }else if(typeResult=='X'){
        if (opponent=='X') return 'Z';
        else if (opponent=='Y') return 'X';
        else return 'Y';
    }else{
        if (opponent=='X') return 'Y';
        else if (opponent=='Y') return 'Z';
        else return 'X';
    }
}

int solution () {
    int score = 0;
    char n[4];
    ifstream fileInput("D:/DEV/Project/AOC/day2/input.txt");
    if (fileInput.fail())
	    cout << "Failed to open this file!" << endl;
    while(!fileInput.eof()){
        fileInput.getline(n,4);
        char opponent = n[0]+23;
        char self = properTurn(opponent,n[2]);
        score += calculate_score(opponent,self);
    }
    return score;
}


int main (){
    cout << solution();
    return 0 ;
}