#include <iostream>
#include <vector>
#include <deque>
#include <sstream>

using namespace std;

int main(){
    string str;
    getline(cin, str);
    stringstream input(str);

    int sum, left, right, a, num;
    vector<int> vec;
    deque<int> qmax;

    while(input >> a){
        vec.push_back(a);
    }

    cin >> num;

    qmax.push_back(0);
    for(right = 1; right < num; ++right){
        while(!qmax.empty() && vec[right] >= vec[qmax.back()]){
            qmax.pop_back();
        }
        qmax.push_back(right);
    }

    sum = vec[qmax.front()];
    left = 0;
    while(right < vec.size()){
        if(left == qmax.front()){
            qmax.pop_front();
        }
        while(!qmax.empty() && vec[right] >= vec[qmax.back()]){
            qmax.pop_back();
        }
        qmax.push_back(right);

        left++;
        right++;
        sum += vec[qmax.front()];
    }

    cout << sum << endl;

    return 0;
}
