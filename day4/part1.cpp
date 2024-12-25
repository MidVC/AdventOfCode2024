/**
 * Advent of Code 2024 - Day 4
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

const string xmas = "XMAS";

int main() {
    vector<string> in;
    string line;
    while (getline(cin, line)) { in.push_back(line); }

    int count = 0;
    for (int i = 0; i < in.size(); ++i) {
        bool flag = true;
        for (int j = 0; j < line.size()-3; ++j) {
            // horizontal forward
            bool flag = true;
            for (int k = 0; k < 4; ++k) {
                if (in[i][j+k] != xmas[k]) {
                    flag = false;
                    break;
                }
            }
            if (flag) count++;
            // horizontal backward
            flag = true;
            for (int k = 0; k < 4; ++k) {
                if (in[i][j+k] != xmas[3-k]) {
                    flag = false;
                    break;
                }
            }
            if (flag) count++;
        }
    }

    for (int j = 0; j < line.size(); ++j) {
        for (int i = 0; i < in.size()-3; ++i) {
            // vertical downward
            bool flag = true;
            for (int k = 0; k < 4; ++k) {
                if (in[i+k][j] != xmas[k]) {
                    flag = false;
                    break;
                }
            }
            if (flag) count++;
            // vertical upward
            flag = true;
            for (int k = 0; k < 4; ++k) {
                if (in[i+k][j] != xmas[3-k]) {
                    flag = false;
                    break;
                }
            }
            if (flag) count++;
        }
    }

    for (int j = 0; j < line.size()-3; ++j) {
        for (int i = 0; i < in.size()-3; ++i) {
            // \ direction, downwards
            bool flag = true;
            for (int k = 0; k < 4; ++k) {
                if (in[i+k][j+k] != xmas[k]) {
                    flag = false;
                    break;
                }
            }
            if (flag) count++;
            // \ direction, upwards
            flag = true;
            for (int k = 0; k < 4; ++k) {
                if (in[i+k][j+k] != xmas[3-k]) {
                    flag = false;
                    break;
                }
            }
            if (flag) count++;
        }
    }

    for (int j = 3; j < line.size(); ++j) {
        for (int i = 0; i < in.size()-3; ++i) {
            // / direction, downwards
            bool flag = true;
            for (int k = 0; k < 4; ++k) {
                if (in[i+k][j-k] != xmas[k]) {
                    flag = false;
                    break;
                }
            }
            if (flag) count++;
            // / direction, upwards
            flag = true;
            for (int k = 0; k < 4; ++k) {
                if (in[i+k][j-k] != xmas[3-k]) {
                    flag = false;
                    break;
                }
            }
            if (flag) count++;
        }
    }
    
    cout << count << endl;

}
