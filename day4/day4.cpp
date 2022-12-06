#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int score = 0 ;
/*Dif btw solution part 1 and part 2 is the isContain func below*/
bool isNumber(char num){
    if (num >=48 && num<= 57)
        return true;
    return false;
}
bool isContain (int arr[]){
    if(arr[2]>=arr[0]&&arr[2]<=arr[1])
        return true;
    if(arr[3]>=arr[0]&&arr[3]<=arr[1])
        return true;
    if(arr[0]>=arr[2]&&arr[0]<=arr[3])
        return true;
    if(arr[1]>=arr[2]&&arr[1]<=arr[3])
        return true;
    return false;
}
void solution(){
    char n [255];
    int arr[4];
    int num;
    ifstream fileInput("D:/DEV/Project/AOC/day4/input.txt");
    if (fileInput.fail())
	    cout << "Failed to open this file!" << endl;
    while(!fileInput.eof()){
        fileInput.getline(n,255);
        string str = n;
        string num="";
        for (int i = 0,j =0 ; i <str.length(); i++){
            if(isNumber(str[i])){
                num+=str[i];
            }else{
                arr[j]=stoi(num);
                num="";
                j++;
            }
        }
        arr[3]=stoi(num);
        if(isContain(arr))
            score++;
    }
}

int main (){
    solution();
    cout << score;
    return 0;
}