#include <iostream>
#include <string>
#include <fstream>
using namespace std;

bool isDiff (string str){
    for(int i =0; i<str.length();i++)
    {
        for (int j = i+1 ; j < str.length();j++){
            if (str[i]==str[j])
                return false;
        }
    }
    return true;
}

int solution(){
    char n[5000];
    ifstream fileInput("D:/DEV/Project/AOC/day6/input.txt");
    if (fileInput.fail())
	    cout << "Failed to open this file!" << endl;
    else{
        string input;
        fileInput.getline(n,5000);
        input=n;
        string subStr = "";
        for (int i = 0; i<input.length();i++){
            subStr =input[i];
            for (int j = i+1,times=13; times>0;j++){
                subStr+=input[j];
                times--;
            }
            if(isDiff(subStr))
            {
                return i+14;
            }
        }
    }
}


int main(){
    cout << solution();
    return 0;
}