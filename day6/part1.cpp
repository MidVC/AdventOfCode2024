/**
 * Advent of Code 2024 - Day [6]
 * Solution by: MidC
 * Repository: https://github.com/MidVC/AdventOfCode2024
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
#include <cmath>

using namespace std;

int main() {
    vector<string> map;
    string line;
    while (getline(cin, line)) {
        map.push_back(line);
    }

    // find starting position
    int x, y;
    for (int i = 0; i < map.size(); ++i) {
        for (int j = 0; j < line.size(); ++j) {
            if (map[i][j] == '^') {
                x = j; y = i; break;
            }
        }
    }
    char direction = 'u';
    map[y][x] = 'X';
    // move
    while (x > 0 && x < line.size()-1 && y > 0 && y < map.size()-1) {
        if (direction == 'u') {
            if (map[y-1][x] == '#') {
                x += 1;
                direction = 'r';
            }
            else y -= 1;
            map[y][x] = 'X';
        }
        else if (direction == 'r') {
            if (map[y][x+1] == '#') {
                y += 1;
                direction = 'd';
            }
            else x += 1;
            map[y][x] = 'X';
        }
        else if (direction == 'd') {
            if (map[y+1][x] == '#') {
                x -= 1;
                direction = 'l';
            }
            else y += 1;
            map[y][x] = 'X';
        }
        else {
            if (map[y][x-1] == '#') {
                y -= 1;
                direction = 'u';
            }
            else x -= 1;
            map[y][x] = 'X';
        }
    }

    // find all positions
    int count = 0;
    for (int i = 0; i < map.size(); ++i) {
        for (int j = 0; j < line.size(); ++j) {
            if (map[i][j] == 'X') count++;
            cout << map[i][j];
        }
        cout << endl;
    }

    cout << count << endl;
    
}
