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

        int num;
        vector<int> linenums;
        while (iss >> num) {
            linenums.push_back(num);
        }

        int result = check(linenums);
        if (result == -1) count++;
        else{
            for (int i = 0; i < linenums.size(); ++i) {
                vector<int> erasethis = linenums;
                erasethis.erase(erasethis.begin()+i);
                if (check(erasethis) == -1) {
                    count++;
                    break;
                }
            }
        }
    }

    cout << count << endl;
}