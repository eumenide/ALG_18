#include <iostream>

using namespace std;

int main(){
    int m,n,sum,a;

    cin >> m;
    while(m--){
        cin >> n;
        sum = 0;
        while(n--){
            cin >> a;
            sum += a;
        }
        cout << sum << endl;
    }

    return 0;
}
