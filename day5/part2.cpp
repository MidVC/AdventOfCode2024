/**
 * Advent of Code 2024 - Day 5
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
    string line; char c; int value, value2, sum = 0;
    bool map[100][100] = {0};

    while (getline(cin, line)) {
        if (line == "") break;
        istringstream iss{line};
        iss >> value >> c >> value2;
        map[value][value2] = 1;
        cout << value << ' ' << value2 << endl;
    }

    while (getline(cin, line)) {
        vector<int> values;
        istringstream iss{line};
        while (iss >> value) {
            values.push_back(value);
            iss >> c;
        }
        bool flag = false, flag2 = true;
        while (flag2) {
            for (int i = 0; i < values.size(); ++i) {
                for (int j = i+1; j < values.size(); ++j) {
                    if (map[values[j]][values[i]]){
                        flag = true;
                        flag2 = true;
                        swap(values[i], values[j]);
                    
                }
            }
            flag2 = false;
        }
        }
        if (flag) sum += values[values.size()/2];
    }
    cout << sum << endl;
}
