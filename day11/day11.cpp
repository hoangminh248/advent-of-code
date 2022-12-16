#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

long long common=1;

class Monkey {
    public:
    vector <long long> items;
    char op;
    string opNum;
    int times=0,throwTrue,throwFalse;
    long long test;

    long long Operation(long long item){
        long long x;
        if (opNum == "old"){
            x=item;
        }else{
            x=stoll(this->opNum);
        }
        if(this->op == '+')
            return item+x;
        else if(this->op=='*')
            return item*x;
    }
    int throwItem(long long item){
        if(item%this->test==0)
            return throwTrue;
        return throwFalse;
    }
};
Monkey monkeys[8];
bool isNum (char a){
    if (a >=48 && a <= 57)
        return true;
    return false;
}
void parseInput(){
    char n[255];
    string input;
    ifstream fileInput("D:/DEV/Project/AOC/day11/input.txt");
    if (fileInput.fail())
	    cout << "Failed to open this file!" << endl;
    for (int pos= 0 ; pos < 8; pos++){
        // Items
        fileInput.getline(n,255);
        string input = n , num ="";
        for (int i  = 15; i < input.length(); i++){
            if (input[i]==','){
                monkeys[pos].items.push_back(stoll(num));
                num="";
            }
            else if(isNum(input[i])){
                num+=input[i];
            }
        }
        monkeys[pos].items.push_back(stoll(num));
        // Operation
        fileInput.getline(n,255);
        input = n; num = "";
        monkeys[pos].op=input[21];
        for (int i  = 23; i < input.length(); i++){
            num+= input[i];
        }
        monkeys[pos].opNum=num;
        // Test
        fileInput.getline(n,255);
        input = n; num = "";
        for (int i  = 19; i < input.length(); i++){
            num+= input[i];
        }
        monkeys[pos].test=stoll(num);
        //Throw
        fileInput.getline(n,255);
        input = n; num = "";
        num += input[25];
        monkeys[pos].throwTrue=stoi(num);
        fileInput.getline(n,255);
        input = n; num = "";
        num += input[26];
        monkeys[pos].throwFalse=stoi(num);
    }
}
long long reduce (long long x){
    if(x >= common)
        return common + x%common; 
    return x;
}
void solution1(){   
    for (int i = 0 ; i < 10000; i++){
        for (int pos = 0 ; pos < 8;pos++){
            int length = monkeys[pos].items.size();
            monkeys[pos].times+=length;
            for (int item = 0 ; item < length; item++){
                long long afterOp = monkeys[pos].Operation(monkeys[pos].items[item]);
                long long bored = reduce(afterOp);
                int recipient = monkeys[pos].throwItem(bored);
                monkeys[recipient].items.push_back(bored);
            }
            monkeys[pos].items.clear();
        }
    }
}
int main (){
    parseInput();
    for (int i =0; i < 8; i++){
        common*=monkeys[i].test;
    }
    solution1();
    
    for (int i = 0 ; i <8 ; i++){
        cout << monkeys[i].times;
        cout << endl;
    }
    return 0;
}