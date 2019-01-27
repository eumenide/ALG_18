#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

vector<int> vec;
int counts;

void reverseMain(int left, int right, int *temp){
    if(left < right){
        int mid = (left + right) / 2;
        reverseMain(left, mid, temp);
        reverseMain(mid + 1, right, temp);

        int i = left, j = mid + 1;
        int m = mid, n = right;
        int k = left;

        while(i <= m && j <= n){
            //cout<<vec[i]<<"\t"<<vec[j]<<"\t"<<counts<<"\t"<<j<<"\t"<<mid<<endl;
            if(vec[i] <= vec[j]){
                temp[k++] = vec[i++];
            }else{
                counts += j - k;
                temp[k++] = vec[j++];
            }
        }
        while(i <= m){
            temp[k++] = vec[i++];
        }
        while(j <= n){
            temp[k++] = vec[j++];
        }
        for(i = left; i <= right; ++i){
            vec[i] = temp[i];
        }
    }
}

void reversePairs(int N){
    int *temp = new int[N];

    reverseMain(0, N - 1, temp);
    delete [] temp;

}



int main(){
    int T;
    int N, n, a;

    cin >> T;
    while(T--){
        vec.clear();
        counts = 0;
        cin >> N;
        n = N;
        while(n--){
            cin >> a;
            vec.push_back(a);
        }

        reversePairs(N);
        cout << counts << endl;
    }

    return 0;
}
