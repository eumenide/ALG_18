#include <iostream>

using namespace std;


string A = "12345$54321";

char findChar(long long int pos){
    if(pos == 0) return '\0';

    int step = 1;

    long long int len = 11;
    long long int query = pos;

    while(len < pos){
        len = 2 * len + (++step);
    }

    while(query > 11){
        long long int pre = (len - step) / 2;

        if(query > pre){
            query -= pre;
            if(query <= step){
                return '$';
            }
            query -= step;
        }

        step--;
        len = pre;
    }

    return A[(query - 1) % 11];
}

int main(){

    int Q;
    cin >> Q;
    while(Q--){
        long long int pos;
        cin >> pos;



        cout << findChar(pos) << endl;
    }


    return 0;
}
