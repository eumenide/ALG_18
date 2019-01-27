#include <iostream>

using  namespace std;

int main(){
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        int f1 = 1, f2=1;
        int sum = 1;
        if(n == 1) cout << 1<<endl;
        else{
            for(int i = 2; i <= n; ++i){
                sum = f1 + f2;
                f1 = f2;
                f2 = sum;
            }
            cout << sum <<endl;
        }
    }

    return 0;
}
