#include <bits/stdc++.h>

using namespace std;

#define MAX_INT INT_MAX

bool isFinded (int begin, int end, int X, vector <int> array){
    for (int i = begin ; i < end; i++){
        if (array[i]==X) return 1;
    }
    return 0;
}

int solvePart1 (){
    ifstream inputFile("D:/DEV/Project/AOC/2021/day4/input.txt");
    vector <int> input;
    int sumUnmarkedNum {0};
    int indexLastNumber {MAX_INT};
    if (inputFile.fail())
	    cout << "Failed to open this file!" << endl;
    else{
        int board[5][5];
        // insert set of number into vector input
        while (1){
            int temp {0};
            inputFile >> temp;   
            if(temp == -1) break;
            input.push_back(temp);
        }
        // find lastNumber , sumUnmarkedNum
        while (!inputFile.eof())            
        {
            int tempIndexLastNumber {4};
            int hasInInput {0};
            bool doneCheck {0} ;
            // insert matrix 5x5 into array BOARD
            for(int r=0; r< 5;r++)
                for(int c=0; c<5;c++)
                    inputFile >> board[r][c];
            // Find lastNumber of board and sum of unmarked number
            while(!doneCheck){
                tempIndexLastNumber ++;
                // iterate every rows
                for (int r=0; r<5 ; r++){
                    for (int c=0; c<5 ; c++){
                        if(board[r][c]==-1||isFinded(0,tempIndexLastNumber,board[r][c],input)){
                            hasInInput ++;
                            board[r][c]=-1;
                        }
                    }
                    if(hasInInput == 5){
                        doneCheck =1;
                        break;
                    }
                    hasInInput = 0;
                }
                // iterate every cols 
                if(!doneCheck)
                    for (int c=0; c<5 ; c++){
                        for (int r=0; r<5 ; r++){
                            if(board[r][c]==-1||isFinded(0,tempIndexLastNumber,board[r][c],input)){
                                hasInInput ++;
                                board[r][c]=-1;
                            }
                        }
                        if(hasInInput == 5){
                            doneCheck =1;
                            break;
                        }
                        hasInInput = 0;
                    }
            }
            if (tempIndexLastNumber < indexLastNumber) {
                indexLastNumber = tempIndexLastNumber;
                sumUnmarkedNum = 0;
                for(int r=0; r< 5;r++)
                    for(int c=0; c<5;c++)
                        if(board[r][c]!=-1)sumUnmarkedNum+=board[r][c];
            }
        }
    }
    return sumUnmarkedNum*input[indexLastNumber-1];
}
int solvePart2(){
    ifstream inputFile("D:/DEV/Project/AOC/2021/day4/input.txt");
    vector <int> input;
    int sumUnmarkedNum {0};
    int indexLastNumber {0};
    if (inputFile.fail())
	    cout << "Failed to open this file!" << endl;
    else{
        int board[5][5];
        // insert set of number into vector input
        while (1){
            int temp {0};
            inputFile >> temp;   
            if(temp == -1) break;
            input.push_back(temp);
        }
        // find lastNumber , sumUnmarkedNum
        while (!inputFile.eof())            
        {
            int tempIndexLastNumber {4};
            int hasInInput {0};
            bool doneCheck {0} ;
            // insert matrix 5x5 into array BOARD
            for(int r=0; r< 5;r++)
                for(int c=0; c<5;c++)
                    inputFile >> board[r][c];
            // Find lastNumber of board and sum of unmarked number
            while(!doneCheck){
                tempIndexLastNumber ++;
                // iterate every rows
                for (int r=0; r<5 ; r++){
                    for (int c=0; c<5 ; c++){
                        if(board[r][c]==-1||isFinded(0,tempIndexLastNumber,board[r][c],input)){
                            hasInInput ++;
                            board[r][c]=-1;
                        }
                    }
                    if(hasInInput == 5){
                        doneCheck =1;
                        break;
                    }
                    hasInInput = 0;
                }
                // iterate every cols 
                if(!doneCheck)
                    for (int c=0; c<5 ; c++){
                        for (int r=0; r<5 ; r++){
                            if(board[r][c]==-1||isFinded(0,tempIndexLastNumber,board[r][c],input)){
                                hasInInput ++;
                                board[r][c]=-1;
                            }
                        }
                        if(hasInInput == 5){
                            doneCheck =1;
                            break;
                        }
                        hasInInput = 0;
                    }
            }
            if (tempIndexLastNumber > indexLastNumber) {
                indexLastNumber = tempIndexLastNumber;
                sumUnmarkedNum = 0;
                for(int r=0; r< 5;r++)
                    for(int c=0; c<5;c++)
                        if(board[r][c]!=-1)sumUnmarkedNum+=board[r][c];
            }
        }
    }
    return sumUnmarkedNum*input[indexLastNumber-1];
}
    
int main()
{
    cout << solvePart2();
    return 0;
}