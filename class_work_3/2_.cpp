#include <iostream>

using namespace std;

int main(){
    int T;
    cin >> T;
    while(T--){
        int M,N;
        cin >> N >> M;
        int arr[N];
        int arr1[2][M];

        for(int i = 0; i < N; ++i){
            cin >> arr[i];
        }
        for(int i = 0; i < M; ++i){
            cin >> arr1[0][i];
            arr1[1][i]=0;
        }


        for(int i = 0; i < M; ++i){
            for(int j = 0; j < N; ++j){
                if(arr[j] % arr1[0][i] == 0)
                    arr1[1][i]++;
            }
        }

        for(int i = 0; i < M - 1; ++i){
            cout << arr1[1][i] << " ";
        }
        cout<<arr1[1][M-1]<<endl;

    }


    return 0;
}
