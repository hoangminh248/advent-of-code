#include <iostream>
#include <string>
#include <fstream>
#include <stack>
using namespace std;

typedef struct crateStack{
    stack <char> crate;
}crateStack;

bool isLetter(char L){
    if(L>=65 && L<=90)
        return true;
    return false;
}
bool isNumber(char num){
    if (num >=48 && num<= 57)
        return true;
    return false;
}
crateStack crateArr[9]; 
char crate[8][9];
fstream fileInput("D:/DEV/Project/AOC/day5/input.txt");
    
void input(){
    char n[255];
    if (fileInput.fail())
	    cout << "Failed to open this file!" << endl;
    int line = 0 ;
    while(line<=7){
        fileInput.getline(n,255);
        string str = n;
        for(int i=1,j=0;j<9;i=i+4){
            if(isLetter(str[i]))
                crate[line][j]=str[i];
            j++;
        }
        line++;
    }
    for(int col = 0; col<9;col++){
        for(int row = 7 ;row>=0;row--)
            {
                if(isLetter(crate[row][col]))
                    crateArr[col].crate.push(crate[row][col]);
            }
    }
}

void solution(){
    int blocks ,give,take;
    
    while (!fileInput.eof())
    {
        string cratePack="";
        fileInput >> blocks >> give >> take;
        for (int i=0 ; i <blocks; i++){
            if (isLetter(crateArr[give-1].crate.top()))
            {
                cratePack += crateArr[give-1].crate.top();
                crateArr[give-1].crate.pop();
            }
        }
        for (int i = cratePack.length()-1; i>=0; i--){
            crateArr[take-1].crate.push(cratePack[i]);
        }
    }
    
}


int main (){
    input();
    solution();
    for(int col = 0; col<9;col++){
        while(!crateArr[col].crate.empty()){
            char r =crateArr[col].crate.top();
            crateArr[col].crate.pop();
            cout << r << " ";
        }
        cout<<endl;
    }
    return 0;
}