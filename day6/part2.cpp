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

struct Point {
    string positions;
    char c;
    bool used;
    Point (char ch): c{ch}, positions{""}, used{false} {}
};

void print(vector<string> &map) {
    for (auto s: map) cout << s << endl;
}



// bool inLoop(vector<vector<Point>> &map, int x, int y, char d) {
//     int originalX = x, originalY = y;
//     if (d == 'u') {
//         if (map[originalY][originalX-1].used) return false;
//         while (y >= 0 && map[y][x].c != '#') {
//             if (map[y][x].positions.find(d) != string::npos) {
//                 map[originalY][originalX-1].used = true; return true;
//             }
//             y--;
//         }
//     }
//     else if (d == 'r') {
//         if (map[originalY-1][originalX].used) return false;
//         while (x < map[0].size() && map[y][x].c != '#') {
//             if (map[y][x].positions.find(d) != string::npos) {
//                 map[originalY-1][originalX].used = true; return true;
//             }
//             x++;
//         }
//     }
//     else if (d == 'd') {
//         if (map[originalY][originalX+1].used) return false;
//         while (y < map.size() && map[y][x].c != '#') {
//             if (map[y][x].positions.find(d) != string::npos) {
//                 map[originalY][originalX+1].used = true; return true;
//             }
//             y++;
//         }
//     }
//     else if (d == 'l') {
//         if (map[originalY+1][originalX].used) return false;
//         while (x >= 0 && map[y][x].c != '#') {
//             if (map[y][x].positions.find(d) != string::npos) {
//                 map[originalY+1][originalX].used = true; return true;
//             }
//             x--;
//         }
//     }
//     return false;
// }

// try to run with an added obstacle
bool inLoop(vector<string> &map, int x, int y) {
    int count = 0;
    char direction = 'u';
    while (x > 0 && x < map[0].size()-1 && y > 0 && y < map.size()-1 && count < 40000) {
        if (direction == 'u') {
            if (map[y-1][x] == '#') {
                direction = 'r';
            }
            else y -= 1;
            // map[y][x] = '*';
            // print(map);
            // map[y][x] = 'X';
            count += 1;
        }
        else if (direction == 'r') {
            if (map[y][x+1] == '#') {
                direction = 'd';
            }
            else x += 1;
            // map[y][x] = '*';
            // print(map);
            // map[y][x] = 'X';
            count += 1;
        }
        else if (direction == 'd') {
            if (map[y+1][x] == '#') {
                direction = 'l';
            }
            else y += 1;
            // map[y][x] = '*';
            // print(map);
            // map[y][x] = 'X';
            count += 1;
        }
        else {
            if (map[y][x-1] == '#') {
                direction = 'u';
            }
            else x -= 1;
            // map[y][x] = '*';
            // print(map);
            // map[y][x] = 'X';
            count += 1;
        }
        // cout << endl;
    }

    if (count >= 40000) return true;
    else return false;
}

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
    int originalX = x, originalY = y;
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
            // cout << map[i][j];
            map[i][j] = '#';
            if (inLoop(map, originalX, originalY)) {
                // cout << j << ' ' << i << endl;
                count++;
            }
            map[i][j] == 'X';
        }
        // cout << endl;
    }

    cout << count << endl;

    // map[8][7] = '#';
    // inLoop(map, originalX, originalY);
    
    






    // vector<vector<Point>> map;
    // string line;
    // while (getline(cin, line)) {
    //     vector<Point> row;
    //     for (auto c: line) row.push_back(Point(c));
    //     map.push_back(row);
    // }

    // // find starting position
    // int x, y;
    // for (int i = 0; i < map.size(); ++i) {
    //     for (int j = 0; j < line.size(); ++j) {
    //         if (map[i][j].c == '^') {
    //             x = j; y = i; map[i][j].positions.push_back('u'); break;
    //         }
    //     }
    // }
    // char direction = 'u';
    // // move and count
    // int count = 0;
    // while (x > 0 && x < line.size()-1 && y > 0 && y < map.size()-1) {
    //     if (direction == 'u') {
    //         if (map[y-1][x].c == '#') {
    //             if (inLoop(map, x, y, 'd')) { cout << x << ' ' << y << endl; count++; }
    //             x += 1;
    //             direction = 'r';
    //             map[y][x].positions.push_back('r');
    //         }
    //         else {
    //             if (inLoop(map, x, y, 'r')) { cout << x << ' ' << y << endl; count++; }
    //             y -= 1;
    //             map[y][x].positions.push_back('u');
    //         }
    //     }
    //     else if (direction == 'r') {
    //         if (map[y][x+1].c == '#') {
    //             if (inLoop(map, x, y, 'l')) { cout << x << ' ' << y << endl; count++; }
    //             y += 1;
    //             direction = 'd';
    //             map[y][x].positions.push_back('d');
    //         }
    //         else {
    //             if (inLoop(map, x, y, 'd')) { cout << x << ' ' << y << endl; count++; }
    //             x += 1;
    //             map[y][x].positions.push_back('r');
    //         }
    //     }
    //     else if (direction == 'd') {
    //         if (map[y+1][x].c == '#') {
    //             if (inLoop(map, x, y, 'u')) { cout << x << ' ' << y << endl; count++; }
    //             x -= 1;
    //             direction = 'l';
    //             map[y][x].positions.push_back('l');
    //         }
    //         else {
    //             if (inLoop(map, x, y, 'l')) { cout << x << ' ' << y << endl; count++; }
    //             y += 1;
    //             map[y][x].positions.push_back('d');
    //         }
    //     }
    //     else {
    //         if (map[y][x-1].c == '#') {
    //             if (inLoop(map, x, y, 'r')) { cout << x << ' ' << y << endl; count++; }
    //             y -= 1;
    //             direction = 'u';
    //             map[y][x].positions.push_back('u');
    //         }
    //         else {
    //             if (inLoop(map, x, y, 'u')) { cout << x << ' ' << y << endl; count++; }
    //             x -= 1;
    //             map[y][x].positions.push_back('l');
    //         }
    //     }
    // }

    // cout << count << endl;

    // cout << map.size() << ' ' << map[0].size() << endl;
    
}
