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
    int arr[SUM / 2 + 1][n+1];
    memset(arr, 0, sizeof(arr));


    for(int i = 0; i < vec.size(); ++i){
       // for(int j = SUM /2 + 1; j >= vec[i]; --j){
        for(int j = SUM / 2; j >= vec[i]; --j){
            for(int k = 1; k <= min(n, i+1); k++){
                //arr[j][k] = arr[j][k] > arr[j - vec[i]][k-1] + vec[i]? arr[j][k] : arr[j - vec[i]][k-1] + vec[i];

                /*
                int tmp = arr[j-vec[i]][k-1];
                if(tmp != -1 && tmp + vec[i] > arr[j][k]){
                    arr[j][k] = tmp + vec[i];
                }
                */
                arr[j][k] = arr[j][k] > arr[j - vec[i]][k-1] + vec[i]? arr[j][k] : arr[j - vec[i]][k-1] + vec[i];
            }
            //arr[j] = arr[j] > arr[j - 1] + vec[i] ? arr[j] : arr[j - 1] + vec[i];
            /*int tmp = arr[j - vec[i]][0] + vec[i];
            if(tmp > arr[j][0]){
                arr[j][0] = tmp;
                arr[j][1]++;
            }*/

            //arr[j][0] = arr[j][0] > arr[j - vec[i]][0] + vec[i] ? arr[j] : arr[j - vec[i]] + vec[i];
        }
        //printArr(arr);
/*
        for(int i = 0; i < SUM / 2 + 1; i++){
        cout<<i<<"\t";
        for(int j = 1; j < n+1; j++){
            cout<<arr[i][j]<<",";
        }
        cout<<endl;;
    }*/

    }

    //printVec();


    for(int i = 0; i < SUM / 2 + 1; i++){
        cout<<i<<"\t";
        for(int j = 1; j < n+1; j++){
            cout<<arr[i][j]<<",";
        }
        cout<<endl;;
    }

    int sum;
    for(sum = SUM / 2; sum >0; --sum){
        if(arr[sum][n] != 0){
            break;
        }
    }

    int result = SUM - 2 * arr[sum][n];
    result = result >= 0 ? result : -1 * result;
    cout<<result <<endl;
    //cout<<(int)abs(SUM - 2 * arr[SUM / 2][n]);

    return 0;
}
