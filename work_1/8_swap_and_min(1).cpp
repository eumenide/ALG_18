#include <iostream>
#include <vector>
#include <sstream>
#include <cstring>
#include <algorithm>

using namespace std;

vector<int> vec;
int SUM;

void printVec(){
    for(int a: vec){
        cout<< a<<"\t";
    }
    cout<<endl;
}

void printArr(int arr[][5]){
    for(int i = 0; i < SUM / 2 + 1; i++){
        cout<<i<<"\t";
        for(int j = 1; j < 5; j++){
            cout<<arr[i][j]<<",";
        }
        cout<<endl;;
    }
}

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

    //int arr[SUM / 2 + 1][2];

    //int a[12] = {100,99,98,1,2,3,1,2,3,4,5,40};
    //vec.insert(vec.begin(), a, a+12);
    //SUM = 358;

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

    /*
    for(int i = 0; i < n+1;++i){
        cout<<i<<"\t";
        for(int j =0;j<SUM/2+1;++j){
            cout<<arr[i][j]<<",";
        }
        cout<<endl;
    }*/

    int sum;
    for(sum = SUM / 2; sum >0; --sum){
        if(arr[n][sum] != 0){
            break;
        }
    }

    cout<<SUM - 2 * sum <<endl;
    //cout<<(int)abs(SUM - 2 * arr[SUM / 2][n]);

    return 0;
}
