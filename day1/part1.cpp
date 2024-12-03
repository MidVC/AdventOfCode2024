/**
 * Advent of Code 2024 - Day [1]
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
    // Could use heap to achieve O(n) time, but not worth it because O(n*log(n)) also works well
    int a, b;
    vector<int> l1, l2;
    while (cin >> a >> b) {
        l1.push_back(a);
        l2.push_back(b);
    }

    sort(l1.begin(),l1.end());
    sort(l2.begin(),l2.end());

    int sum = 0;
    for (int i = 0; i < l1.size(); ++i) {
        sum += abs(l1[i]-l2[i]);
    }
    
    cout << sum << endl;
}
