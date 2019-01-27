#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int T;
int N;

int minSwarp(int *A, int *B, int N){
    int counts = 0;

    for(int i = 0; i < N; ++i){
        if(A[i] == B[i]) continue;
        else{
            for(int j = i + 1; j < N; ++j){
                if(A[i] == B[j]){
                    swap(A[i], A[j]);
                    counts++;
                    i--;
                }
            }
        }
    }

    return counts;

}

int main(){
    int A[100];
    int B[100];
    cin >>T;
    while(T--){
        int i = 0;
        int b, n;
        cin>>n;
        N = n;
        memset(A, 0, N * sizeof(A[0]));
        memset(B, 0, N * sizeof(B[0]));
        while(n--){
            cin >> b;
            A[i] = b;
            B[i++] = b;
        }
        sort(B, B + N);

        cout<<minSwarp(A,B,N)<<endl;
    }

    return 0;
}


