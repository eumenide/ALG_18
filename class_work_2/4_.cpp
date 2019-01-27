#include <stdio.h>

using namespace std;

int count_num(int n);

int count_num(int n){
    if(n < 36)  return 0;
    if(n == 36) return 1;

    int result = 1;

    int num = 36;
     for(int i = 7; ; ++i){
        //int t = i;
        num += (i << 1) - 1;
        //printf("%d\n", t << 2);
        if(num > n) break;

        int temp = 3;
        for(int j = 2; j < i; ++j){
            if(num % j == 0)
                temp += 2;
        }

        if(temp == 9)   result++;
    }

    return result;

}

int main(){
    int T;
    scanf("%d", &T);
    //cin >> T;
    while(T--){
        int n;
        //cin >> n;
        scanf("%d", &n);

        printf("%d\n", count_num(n));
        //cout << count_num(n) << endl;
    }

    return 0;
}
