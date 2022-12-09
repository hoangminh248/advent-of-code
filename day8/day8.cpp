#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

int treeGrid[99][99];
int visibleTree = 99*2+97*2;
int maxCol = 99;
int maxRow = 99;
int maxScore = -1;

int ctoi (char x){
    return x -48;
}
void input(){
    //col : 99
    ifstream fileInput("D:/DEV/Project/AOC/day8/input.txt");
    if (fileInput.fail())
	    cout << "Failed to open this file!" << endl;
    char n[255];
    string str;
    for(int row= 0 ;row<maxRow;row++){
        fileInput.getline(n,255);
        str = n;
        for(int col=0; col <maxCol; col++){
            treeGrid[row][col]= ctoi(str[col]);
        }
    }
}
void solution1(){
    for(int row= 1 ;row<maxRow-1;row++){
        int mostHighLeft = treeGrid[row][0];
        for(int col=1; col <maxCol-1 ;col++){
            //check left
            if(treeGrid[row][col]>mostHighLeft){
                visibleTree++;
                mostHighLeft=treeGrid[row][col];
            }else{
                bool doneCheck=0;
                bool isVisible=1;
                while(!doneCheck){
                    //loop right
                    for(int i = maxCol-1; i>col;i--){
                        if(treeGrid[row][col]<=treeGrid[row][i])
                        {   
                            isVisible= 0 ;
                            break;
                        }
                    }   
                    if(isVisible){
                        visibleTree++;
                        doneCheck =1;
                        continue;
                    }
                    //loop top
                    isVisible=1;
                    for(int i =0 ; i < row;i++){
                        if(treeGrid[row][col]<=treeGrid[i][col]){
                            isVisible= 0 ;
                            break;
                        }
                    }
                    if(isVisible){
                        visibleTree++;
                        doneCheck =1;
                        continue;
                    }
                    //loop bottom
                    isVisible=1;
                    for(int i =maxRow-1 ; i > row;i--){
                        if(treeGrid[row][col]<=treeGrid[i][col]){
                            isVisible= 0 ;
                            break;
                        }
                    }
                    if(isVisible){
                        visibleTree++;
                        doneCheck =1;
                        continue;
                    }
                    doneCheck =1;
                }
            }
        }
    } 
}
void solution2(){
    for(int row= 1 ;row<maxRow-1;row++){
        for(int col=1; col <maxCol-1 ;col++){
            int totalScore = 1;
            int score =0;
            //loop left
            for (int i=col-1;i>=0;i--){
                if(treeGrid[row][col]>treeGrid[row][i])
                    score++;
                else
                {
                    score++;
                    break;
                }
            }
            totalScore *=score;
            score=0;
            //loop right
            for(int i=col+1;i<maxCol;i++){
                if(treeGrid[row][col]>treeGrid[row][i])
                    score++;
                else
                {
                    score++;
                    break;
                }
            }
            totalScore *=score;
            score=0;   
            //loop top
            for(int i =row-1 ; i >=0;i--){
                if(treeGrid[row][col]>treeGrid[i][col])
                    score++;
                else
                {
                    score++;
                    break;
                }
            }
            totalScore *=score;
            score=0;
            //loop bottom
            for(int i =row+1 ; i <maxRow;i++){
                if(treeGrid[row][col]>treeGrid[i][col])
                    score++;
                else
                {
                    score++;
                    break;
                }
            }
            totalScore *=score;
            if(totalScore > maxScore) maxScore = totalScore;
        }
    }
}
int main(){
    input();
    solution2();
    cout << maxScore;
    return 0;
}