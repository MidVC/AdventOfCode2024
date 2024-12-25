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


// Decides if the block is valid
// s1 __ s2
// __ s3 __
// s4 __ s5
bool validBlock(char s1, char s2, char s3, char s4, char s5) {
    // check the \ direction
    if (!(s1=='M' && s3=='A' && s5=='S') && !(s1=='S' && s3=='A' && s5=='M')) return false;
    // check the \ direction
    if (!(s2=='M' && s3=='A' && s4=='S') && !(s2=='S' && s3=='A' && s4=='M')) return false;
    return true;
}

int main() {
    vector<string> in;
    string line;
    while (getline(cin, line)) { in.push_back(line); }

    int count = 0;
    for (int i = 0; i < in.size()-2; ++i) {
        for (int j = 0; j < line.size()-2; ++j) {
            if (validBlock(in[i][j], in[i][j+2], in[i+1][j+1], in[i+2][j], in[i+2][j+2])) count++;
        }
    }

    cout << count << endl;    

}
