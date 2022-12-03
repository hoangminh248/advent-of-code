#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int solution (){
    int total = 0 ;
    int max = 0 ;
    int second = 0 ;
    int third = 0;
    char n [20] ;
    ifstream fileInput("D:/DEV/Project/AOC/input.txt");
    if (fileInput.fail())
	    cout << "Failed to open this file!" << endl;
    while(!fileInput.eof()){
        fileInput.getline(n,20);
        string input = n;
        if (input == ""){
            if(total > max) {
                third = second;
                second = max;
                max =total;
            }
            else if (total > second)
            {
                third = second;
                second = total;
            }
            else if (total > third){
                third = total;
            }
            total = 0;
        }
        else{
            total += stoi(input);
            if (total == 68886){
                total = 68886;
            }
        }
    }
    fileInput.close();
    cout << max << endl << second << endl << third << endl;
    return max+third+second;
}

int main () {
    cout << solution();
    return 0 ;
}