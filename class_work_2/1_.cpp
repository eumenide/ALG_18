#include <iostream>

using namespace std;

int large_mod(int a, int b, int c){
    int result = 1;
    while(b){
        if(b & 1){
            result = (result * a) % c;
        }
        b >>= 1;
        a = (a * a) % c;
    }
    return result;
}

int main(){
    int n, result;
    cin >> n;
    while(n--){
        int A, B, C;
        cin >> A >> B >> C;

        result = large_mod(A, B, C);
        cout << result << endl;
    }

    return 0;
}
