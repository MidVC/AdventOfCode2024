/**
 * Advent of Code 2024 - Day [2]
 * Solution by: [Your Name]
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
    string line;
    int count = 0;
    
    while (getline(cin, line)) {
        istringstream iss(line); 

        int num, prev;
        iss >> prev >> num;
        bool increasing = true, flag = true;
        if (prev == num) continue;
        else if (abs(num - prev) > 3) continue;

        if (prev - num > 0) increasing = false;

        prev = num;

        while (iss >> num) {
            if (num == prev){
                flag = false;
                break;
            }
            else if (abs(num - prev) > 3) {
                flag = false;
                break;
            }
            else if (((num < prev) && increasing) || ((num > prev) && !increasing)){
                flag = false;
                break;
            }
            prev = num;
        }
        if (flag) count++;
    }

    cout << count << endl;
}