#include <iostream>
#include <vector>
#include <sstream>
#include <cstring>

using namespace std;

vector<int> vec;
int SUM;

void inputArr(){
    string str;
    stringstream input;
    int a;
    input.clear();
    getline(cin, str);
    input.str(str);
    while(input >> a){
        vec.push_back(a);
        SUM += a;
    }
}

int main(){
    SUM = 0;
    inputArr();
    inputArr();

    int n = vec.size() / 2;
    int arr[n+1][SUM/2+1];
    memset(arr, 0, sizeof(arr));
    for(int i = 0; i < n+1;++i){
        arr[i][0] = 1;
    }

    for(int i = 0; i < vec.size(); ++i){
        for(int j = min(i+1,n);j>0;--j){
            for(int k = 1; k < SUM / 2 + 1; ++k){
                if(k>=vec[i] && arr[j-1][k-vec[i]]!=0){
                    arr[j][k] = 1;
                }
            }
        }

    }

    int sum;
    for(sum = SUM / 2; sum >0; --sum){
        if(arr[n][sum] != 0){
            break;
        }
    }

    cout<<SUM - 2 * sum <<endl;

    return 0;
}
