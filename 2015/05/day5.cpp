#include <bits/stdc++.h>

using namespace std;

bool isVowel(char x);
bool isNiceString(string str);
bool isUglyString(char a, char b);
int solvePart1()
{
    string str;
    int count;
    ifstream inputFile("D:/AOC/2015/day5/input.txt");
    if (inputFile.fail())
        cout << "Failed to open this file!" << endl;
    else
    {
        while (!inputFile.eof())
        {
            getline(inputFile, str);
            if (isNiceString(str))
                count++;
        }
    }
    return count;
}
int solvePart2()
{
    ifstream inputFile("D:/AOC/2015/day5/input.txt");
    if (inputFile.fail())
        cout << "Failed to open this file!" << endl;
    else
    {
        while (!inputFile.eof())
        {
        }
    }
}

int main()
{
    // Start here
    cout << solvePart1();
    // cout << isNiceString("dvszwmarrgswjxmb");
    //  cout << isUglyString('r', 'b');
    return 0;
}

bool isVowel(char x)
{
    switch (x)
    {
    case 'a':
        return 1;
        break;
    case 'e':
        return 1;
        break;
    case 'i':
        return 1;
        break;
    case 'o':
        return 1;
        break;
    case 'u':
        return 1;
        break;
    }
    return 0;
}
bool isUglyString(char a, char b)
{
    if (a == 'a' && b == 'b')
        return 1;
    else if (a == 'c' && b == 'd')
        return 1;
    else if (a == 'p' && b == 'q')
        return 1;
    else if (a == 'x' && b == 'y')
        return 1;
    return 0;
}
bool isNiceString(string str)
{
    int count_vowel = 0;
    int count_double = 0;

    for (int i = 1; i < str.length(); i++)
    {
        char a = str[i - 1];
        char b = str[i];
        // check ugly sub string
        if (isUglyString(a, b))
            return 0;
        // check double string
        if (a == b)
            count_double++;
        if (isVowel(a))
            count_vowel++;
    }
    // check last character of string if it is vowel
    if (isVowel(str[str.length() - 1]))
        count_vowel++;
    if (count_vowel >= 3 && count_double)
        return 1;
    return 0;
}