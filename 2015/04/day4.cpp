#include <bits/stdc++.h>
#include <sstream>
#include <openssl/md5.h>

using namespace std;

MD5_CTX md5;

int solvePart1()
{
    ifstream inputFile("D:/AOC/2015/day4/input.txt");
    if (inputFile.fail())
        cout << "Failed to open this file!" << endl;
    else
    {
        unsigned char digest[16];
        ostringstream ss;
        const string data = "yzbqklnj";
        MD5_Init(&md5);
        MD5_Update(&md5, "yzbqklnj", sizeof(data));
        MD5_Final(digest, &md5);
        ss << hex << digest;
        string result = ss.str();
        cout << result << endl;
        for (int i = 0; i < 16; i++)
        {

        }
        while (!inputFile.eof())
        {
        }
    }
}
int solvePart2()
{
    ifstream inputFile("D:/AOC/2015/day4/input.txt");
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
    solvePart1();
    return 0;
}