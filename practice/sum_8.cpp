#include <iostream>

using namespace std;

int main(){
    int m,n,sum,a;

    cin >> m;
    while(m--){
        sum = 0;
        cin >> n;
        while(n--){
            cin >> a;
            sum += a;
        }
        cout<<sum<<endl;
        if(m)
            cout<<endl;
    }

    return 0;
}
