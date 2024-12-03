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

// -1 for success, otherwise fault point
int check(vector<int> &nums) {
    int num = nums[1], prev = nums[0];
        bool increasing = true;
        int flag = -1;
        if (prev == num) return 0;
        else if (abs(num - prev) > 3) return 0;
        if (prev - num > 0) increasing = false;
        prev = num;

        for (int i = 2; i < nums.size(); ++i) {
            num = nums[i];
            if (num == prev){
                flag = i;
                break;
            }
            else if (abs(num - prev) > 3) {
                flag = i;
                break;
            }
            else if (((num < prev) && increasing) || ((num > prev) && !increasing)){
                flag = i;
                break;
            }
            prev = num;
        }
        return flag;
}

int main() {
    string line;
    int count = 0;
    
    while (getline(cin, line)) {
        istringstream iss(line); 

        int num, prev;
        iss >> prev >> num;
        bool increasing = true, flag = true, tolerate = true;
        if (prev == num) {

        }
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