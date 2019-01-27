#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_map>
#include <set>
#include <numeric>
#include <climits>

using namespace std;

int toInt(const string &str) {
    return atoi(str.c_str());
}

size_t split(const std::string &txt, std::vector<std::string> &strs, char ch) {
    size_t pos = txt.find(ch);
    size_t initialPos = 0;
    strs.clear();

    // Decompose statement
    while (pos != std::string::npos) {
        strs.push_back(txt.substr(initialPos, pos - initialPos));
        initialPos = pos + 1;

        pos = txt.find(ch, initialPos);
    }

    // Add the last one
    strs.push_back(txt.substr(initialPos, std::min(pos, txt.size()) - initialPos + 1));

    return strs.size();
}

class Solution {
public:
    void print(vector<int> data) {
        for (auto a:data) {
            cout << a << " ";
        }
        cout << endl;
    }

    void solve(vector<int> v1, vector<int> v2) {
        v1.insert(v1.end(), v2.begin(), v2.end());
        int len = static_cast<int>(v1.size());
        int sumAll = accumulate(v1.begin(), v1.end(), 0);

        int n = len, m = len / 2, l = sumAll / 2;

        vector<vector<int>> dp(l + 1, vector<int>(m + 1, INT_MIN));

        dp[0][0] = 0;

        for (int i = 0; i < n; i++) {
            for (int j = l; j >= v1[i]; j--) {
                for (int k = m; k >= 1; k--) {
                    dp[j][k] = max(dp[j][k], dp[j - v1[i]][k - 1] + v1[i]);
                }
            }
        }

        int ans = INT_MIN;
        for (int i = 1; i <= l; i++) {
            if (dp[i][m] > ans)
                ans = dp[i][m];
        }

        cout << sumAll - 2 * ans << endl;
    }
};

int main() {

    // get input
    string s;
    getline(cin, s);
    vector<string> line;
    split(s, line, ' ');
    vector<int> input1;
    transform(line.begin(), line.end(), back_inserter(input1), toInt);

    getline(cin, s);
    split(s, line, ' ');
    vector<int> input2;
    transform(line.begin(), line.end(), back_inserter(input2), toInt);

    // solve
    Solution solution;
    solution.solve(input1, input2);
//    vector<int> v1{100, 40, 69, 69};
//    vector<int> v2{69,69,96,40};
//    vector<int> v1{100, 99, 98, 1, 2, 3};
//    vector<int> v2{1, 2, 3, 4, 5, 40};
//    solution.solve(v1, v2);
    return 0;
}
