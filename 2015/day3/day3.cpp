#include <bits/stdc++.h>

using namespace std;

pair<int, int> location(0, 0); //(x,y)
pair<int, int> location_Robot(0, 0);
string key;
char direction;
double count = 0;
unordered_map<string, int> house;

void handleInput(pair<int, int> &location, char direction);

int solvePart1()
{
    ifstream inputFile("D:/AOC/2015/day3/input.txt");
    if (inputFile.fail())
        cout << "Failed to open this file!" << endl;
    else
    {
        house.insert(make_pair("00", 1));
        while (!inputFile.eof())
        {
            inputFile >> direction;
            handleInput(location, direction);
            key = to_string(location.first) + to_string(location.second);
            if (house.find(key) == house.end())
            {
                house.insert(make_pair(key, 1));
            }
        }
    }
    return house.size();
}
int solvePart2()
{
    ifstream inputFile("D:/AOC/2015/day3/input.txt");
    if (inputFile.fail())
        cout << "Failed to open this file!" << endl;
    else
    {
        house.insert(make_pair("00", 1));
        while (!inputFile.eof())
        {
            inputFile >> direction;
            handleInput(location, direction);
            key = to_string(location.first) + to_string(location.second);
            if (house.find(key) == house.end())
            {
                house.insert(make_pair(key, 1));
            }
            if (!inputFile.eof())
            {
                inputFile >> direction;
                handleInput(location_Robot, direction);
                key = to_string(location_Robot.first) + to_string(location_Robot.second);
                if (house.find(key) == house.end())
                {
                    house.insert(make_pair(key, 1));
                }
            }
        }
    }
    return house.size();
}

int main()
{
    // cout << solvePart1();
    cout << solvePart2();
    return 0;
}

void handleInput(pair<int, int> &location, char direction)
{
    switch (direction)
    {
    case '^':
        location.second += 1;
        break;
    case 'v':
        location.second -= 1;
        break;
    case '<':
        location.first -= 1;
        break;
    case '>':
        location.first += 1;
        break;
    }
}