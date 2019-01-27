#include <iostream>
#include <limits>

using namespace std;

int MinSum(int n, int m, int **arr);

int MinSum(int n, int m, int *arr){
    int result = 0;
    int dp[m + 1][n + 1] = {0};

    for(int i = 1; i <=n; ++i){
        dp[1][i] = dp[1][i - 1] + arr[i - 1];
    }
    for(int i = 1; i <= m; ++i){
        dp[i][1] = arr[0];
    }


    for(int i = 2; i <= m; ++i){
        for(int j = 2; j <= n; ++j){
            int m_max = INT_MAX;
            for(int k = 1; k <= j; ++k){
                m_max = min(m_max, max(dp[i - 1][k], dp[1][j] - dp[1][k]));
            }
            dp[i][j] = m_max;
        }
    }

    return dp[m][n];
}

/**
*   ×îĞ¡m¶ÎºÍ
*/
int main(){
    int T;
    cin >> T;
    while(T--){
        int k,n;
        cin >> k >> n;
        int *arr = new int[n];
        int i = 0;
        while(i < n){
            cin >> arr[i++];
        }

        int result = MinSum(n, k, arr);
        cout << result << endl;

        delete[] arr;
    }

    return 0;
}
