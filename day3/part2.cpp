/**
 * Advent of Code 2024 - Day [3]
 * Solution by: [MidC]
 * Repository: https://github.com/MidVC/AdventOfCode2024
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
#include <cmath>

using namespace std;

pair<int, int> valuePos(string s, int n){
    // Find the integer at position n of string s.
    // Return a pair <value, nextPosition>
    int val = 0;

    while (s[n] >= '0' && s[n] <= '9') {
        val *= 10;
        val += s[n] - '0';
        n += 1;
    }

    cout << val << ' ' << n << endl;

    return pair<int,int>(val, n);

}


int main() {

    // Could use modified KMP for O(n) time, but too complicated and not worth it for this small input

    // Get the full string
    string s = "";
    char c;
    while (cin >> c) { s.push_back(c); }

    int pos = s.find("mul(");
    int nextDont = s.find("don't()");
    int sum = 0;

    while (pos != string::npos) {

        if (nextDont != -1 && pos >= nextDont) {
            pos = s.find("do()", nextDont);
            nextDont = s.find("don't()", pos);
            pos = s.find("mul(", pos);
            continue;
        }

        // cout << pos << endl;
        pos += 4;
        if (s[pos] > '9' || s[pos] < '0') {
            pos = s.find("mul(", pos);
            continue;
        }
        pair<int, int> kppair = valuePos(s, pos);
        pos = kppair.second;
        if (s[pos] != ',') {
            pos = s.find("mul(", pos);
            continue;
        }
        pos += 1;
        if (s[pos] > '9' || s[pos] < '0') {
            pos = s.find("mul(", pos);
            continue;
        }
        pair<int, int> kppair2 = valuePos(s, pos);
        pos = kppair2.second;
        if (s[pos] != ')') {
            pos = s.find("mul(", pos);
            continue;
        }
        sum += kppair.first * kppair2.first;
        pos += 1;
        pos = s.find("mul(", pos);
    }

    cout << sum << endl;

}
