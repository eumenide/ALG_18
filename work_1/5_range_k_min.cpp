#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

int main(){
    string str;
    getline(cin, str);
    stringstream input(str);

    vector<int> vec;
    int left,right,k,a;

    while(input >> a){
        vec.push_back(a);
    }
    cin >> left >> right;
    cin >> k;

    sort(vec.begin() + left - 1, vec.begin() + right);

    cout << vec[left + k - 2] << endl;

    return 0;
}


