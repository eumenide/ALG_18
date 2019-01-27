#include <iostream>
#include <vector>
#include <unordered_map>
#include <utility>
#include <algorithm>

using namespace std;

int T,N;
vector<int> vec;
vector<pair<int, int>> myVec;
unordered_map<int, int> myMap;

void frequenceSort(){
    for(auto it = myMap.begin(); it != myMap.end(); it++){
        myVec.push_back(make_pair(it->first, it->second));
    }

    sort(myVec.begin(), myVec.end(), [](const pair<int, int>& x, const pair<int, int>& y) -> int{
            if(x.second > y.second) return x.second > y.second;
            else return x.first < y.first;
         });

    for(auto it = myVec.begin(); it != myVec.end(); ++it){
        for(int i =0; i < it->second; ++i){
            vec.push_back(it->first);
        }
    }
}

int main(){
    cin >> T;
    while(T--){
        myMap.clear();
        myVec.clear();
        vec.clear();
        int n,a;
        cin >> N;
        n = N;
        while(n--){
            cin >> a;
            myMap[a]++;
        }

        frequenceSort();

        /*
        cout<<vec[0];
        for(int i = 1; i < vec.size(); ++i){
            cout<<" "<<vec[i];
        }
        */
        for (auto it : vec){
            cout<<it<<" ";
        }
        cout<<endl;
    }



    return 0;
}
