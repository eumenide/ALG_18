#include <iostream>
#include <cstring>
#include <vector>
#include <sstream>
#include <set>
#include <algorithm>

using namespace std;

vector<vector<int> > vec;
set<string> s;

void LCS(string str1, string str2){
    int m = str1.size(), n = str2.size();

    for(int i = 0; i < m + 1; ++i){
        for(int j = 0; j < n + 1; ++j){
            if(i == 0 || j == 0){
                vec[i][j] = 0;
            }else if(str1[i - 1] == str2[j - 1]){
                vec[i][j] = vec[i - 1][j - 1] + 1;
            }else{
                vec[i][j] = max(vec[i - 1][j], vec[i][j - 1]);
            }
        }
    }
}

void LCSPrint(string str1, string str2, int len1, int len2, string curStr){
    while(len1 > 0 && len2 > 0){
        if(str1[len1 - 1] == str2[len2 - 1]){
            curStr += str1[len1 - 1];
            --len1;
            --len2;
        }else{
            if(vec[len1 - 1][len2] > vec[len1][len2 - 1]){
                --len1;
            }else if(vec[len1- 1][len2] < vec[len1][len2 - 1]){
                --len2;
            }else{
                LCSPrint(str1, str2, len1 - 1, len2, curStr);
                LCSPrint(str1, str2, len1, len2 - 1, curStr);
                return;
            }
        }
    }
    reverse(curStr.begin(), curStr.end());
    //如果不pop，不知为何末尾会多出一个空格。。
    //curStr.pop_back();
    s.insert(curStr);
}

int main(){
    string str1, str2, rest;
    getline(cin, str1);
    getline(cin, str2);

    int m = str1.size();
    int n = str2.size();

    vec.resize(m + 1);
    for(int i = 0; i < m + 1; ++i){
        vec[i].resize(n + 1);
    }

    LCS(str1, str2);
    LCSPrint(str1, str2, m, n, rest);

    for(auto str : s){
        cout<<str+"0"<<endl;
    }

    return 0;
}
