/**
 * Advent of Code 2024 - Day [X]
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
    int a, b;
    vector<int> l1;
    
    int ht[100000] = {0};
    while (cin >> a >> b) {
        l1.push_back(a);
        ht[b]++;
    }

    

    int sum = 0;
    for (int i = 0; i < l1.size(); ++i) {
        sum += l1[i] * ht[l1[i]];
    }
    
    cout << sum << endl;
}
