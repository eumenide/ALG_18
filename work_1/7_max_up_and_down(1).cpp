#include <iostream>
#include <sstream>
#include <vector>
#include <cstring>
#include <deque>

using namespace std;

vector<int> vec;

void printArr(int arr[], int n){
    for(int i = 0; i < n; ++i){
        cout<<arr[i]<<"\t";
    }
    cout<<endl;
}

void LIS(int *arr, int n, int *ascNum){
   arr[0] = 1;
   for(int i = 1; i < n; ++i){
        arr[i] = 1;
        for(int j = 0; j < i; ++j){
            if(vec[j] < vec[i]){
                if(arr[i] < arr[j] + 1){
                    arr[i] = arr[j] + 1;
                    ascNum[i] = j;
                }
            }
        }
   }
}

int LDS(int *arr, int n, int *descNum){
    arr[n - 1] = 1;
    for(int i = n - 2; i >=0; --i){
        arr[i] = 1;
        for(int j = n - 1; j >= i; --j){
            if(vec[j] < vec[i]){
                if(arr[i] < arr[j] + 1){
                    arr[i] = arr[j] + 1;
                    descNum[i] = j;
                }
            }
        }
    }
}

void printAll(int *asc, int *desc, int *ascNum, int *descNum, int m_index, int n){
    deque<int> que;
    int m_current = m_index;
    while(m_current >= 0){
        que.push_front(vec[m_current]);
        m_current = ascNum[m_current];
    }
    que.pop_back();
    m_current = m_index;
    while(m_current >= 0){
        que.push_back(vec[m_current]);
        m_current = descNum[m_current];
    }

    while(!que.empty()){
        cout<< que.front()<<" ";
        que.pop_front();
    }
    cout<<endl;
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
    int ascNum[n];
    int descNum[n];
    memset(asc, 0, sizeof(asc));
    memset(desc, 0, sizeof(desc));
    memset(ascNum, -1, sizeof(ascNum));
    memset(descNum, -1, sizeof(descNum));

    LIS(asc, n, ascNum);
    LDS(desc, n, descNum);

    m_max = 0;
    for(int i = 0; i < n; ++i){
        m_max = max(m_max, asc[i] + desc[i] - 1);
    }

    for(int i = 0; i < n; ++i){
        if(asc[i] + desc[i] - 1 == m_max){
            printAll(asc, desc, ascNum, descNum, i, n);
        }
    }

    return 0;
}
