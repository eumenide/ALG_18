#include <iostream>
#include <sstream>
#include <vector>
#include <cstring>
#include <climits>

using namespace std;

vector<int> vec;


void printArr(int *arr, int n){
    for(int i = 0; i < n; ++i){
        cout<<arr[i]<<"\t";
    }
    cout<<endl;
}

void LIS(int *arr, int n, int *inc){
    for(int i = 0; i < n; ++i){
        int left = 0, right = i;
        while(left < right){
            int mid = (left + right) / 2;
            if(inc[mid] < vec[i]){
                left = mid + 1;
            }else{
                right = mid;
            }
        }
        arr[i] = left + 1;
        inc[left] = vec[i];
    }
}

int LDS(int *arr, int n, int *inc){
    for(int i = n - 1; i >= 0; --i){
        int left = 0, right = i;
        while(left < right){
            int mid = (left + right) / 2;
            if(inc[mid] < vec[i]){
                left = mid + 1;
            }else{
                right = mid;
            }
        }
        arr[i] = left + 1;
        inc[left] = vec[i];
    }
}

int main(){
    string str;
    getline(cin, str);
    stringstream input(str);

    int tmp, m_max;
    while(input >> tmp){
        vec.push_back(tmp);
    }

    int n = vec.size();
    int asc[n];
    int desc[n];
    int inc[n];
    memset(asc, 1, sizeof(asc));
    memset(desc, 1, sizeof(desc));
    memset(inc, INT_MAX, sizeof(inc));

    LIS(asc, n, inc);
    LDS(desc, n, inc);

    m_max = 0;
    for(int i = 0; i < n; ++i){
        m_max = max(m_max, asc[i] + desc[i]);
    }

    printArr(asc, n);
    cout<<endl;
    printArr(desc, n);
    cout<<endl;
    printArr(inc, n);
    cout<<endl;

    cout<<m_max<<endl;



    return 0;
}
