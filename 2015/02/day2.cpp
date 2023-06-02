#include <bits/stdc++.h>

using namespace std;

int *handleInput(string input)
{
    static int arr[3];
    string num = "";
    for (int i = 0, n = 0; i < input.length(); i++)
    {
        if (input[i] == 'x')
        {
            arr[n] = stoi(num);
            num = "";
            n++;
            continue;
        }
        num += input[i];
    }
    arr[2] = stoi(num);
    return arr;
}

int solvePart1()
{
    int sqrF = 0;
    ifstream inputFile("D:/AOC/2015/day2/input.txt");
    if (inputFile.fail())
        cout << "Failed to open this file!" << endl;
    else
    {
        string dimension;
        int *sizeCUBE;
        int sqrSIDE[3];
        while (!inputFile.eof())
        {
            int min = INT_MAX;
            getline(inputFile, dimension);
            sizeCUBE = handleInput(dimension);
            sqrSIDE[0] = 2 * sizeCUBE[0] * sizeCUBE[1];
            sqrSIDE[1] = 2 * sizeCUBE[1] * sizeCUBE[2];
            sqrSIDE[2] = 2 * sizeCUBE[0] * sizeCUBE[2];
            sqrF += sqrSIDE[0] + sqrSIDE[1] + sqrSIDE[2];
            for (int i = 0; i < 3; i++)
            {
                if (sqrSIDE[i] < min)
                    min = sqrSIDE[i];
            }
            sqrF += min/2;
        }
    }
    return sqrF;
}

int solvePart2()
{
    int sqrF = 0;
    ifstream inputFile("D:/AOC/2015/day2/input.txt");
    if (inputFile.fail())
        cout << "Failed to open this file!" << endl;
    else
    {
        string dimension;
        int *sizeCUBE;
        while (!inputFile.eof())
        {
            int max = INT_MIN;
            int maxIndex = 0;
            getline(inputFile, dimension);
            sizeCUBE = handleInput(dimension);
            sqrF += sizeCUBE[0] * sizeCUBE[1] * sizeCUBE[2];
            for (int i = 0; i < 3; i++)
            {
                if (sizeCUBE[i] > max){
                    max = sizeCUBE[i];
                    maxIndex = i;
                }
            }
            for (int i = 0; i < 3; i++)
            {
                if (i != maxIndex)
                    sqrF += sizeCUBE[i] * 2;
            }
        }
        return sqrF;
    }
}

int main()
{
    //cout << solvePart1();
    cout << solvePart2();
}