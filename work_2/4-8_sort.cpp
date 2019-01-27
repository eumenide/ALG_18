#include <iostream>
#include <algorithm>
#include <stack>
#include <cstring>

#define MAX_VAL 100001

using namespace std;

void print_arr(int *arr, int n);

void bubble_sort(int *arr, int n){
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n - 1 - i; ++j ){
            if(arr[j] > arr[j + 1]){
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

void insert_sort(int *arr, int n){
    for(int i = 1; i < n; ++i){
        int j = i;
        while(j > 0 && arr[j] < arr[j - 1]){
            swap(arr[j], arr[j - 1]);
            --j;
        }
    }
}


//递归快速排序
void quick_sort(int *arr, int left, int right){
    if(left >= right){
        return;
    }
    int first = left;
    int last = right - 1;
    int key = arr[first];

    while(first < last){
        while(first < last && arr[last] >= key){
            --last;
        }
        if(first < last){
            arr[first++] = arr[last];
        }

        while(first < last && arr[first] < key){
            ++first;
        }
        if(first < last){
            arr[last--] = arr[first];
        }
    }
    arr[last] = key;

    quick_sort(arr, left, last);
    quick_sort(arr, last + 1, right);
}


//非递归快排
void unrecur_quick_sort(int *arr, int left, int right){
    if(left >= right){
        return;
    }

    stack<int> s;

    s.push(left);
    s.push(right);

    int temp = 0;
    while(!s.empty()){
        right = s.top();
        int last = right - 1;
        s.pop();
        int first = s.top();
        left = first;
        s.pop();
        int key = arr[first];

        //cout<<first << "\t" << last << "\t" << key << endl;

        if(first < last){
            while(first < last){
                while(first < last && arr[last] >= key){
                    --last;
                }
                if(first < last){
                    arr[first++] = arr[last];
                }

                while(first < last && arr[first] < key){
                    ++first;
                }
                if(first < last){
                    arr[last--] = arr[first];
                }
            }
            arr[last] = key;

           // print_arr(arr, 13);
            s.push(left);
            s.push(last);
            s.push(last + 1);
            s.push(right);
            //cout<<left<<"\t"<<last<<"\t"<<right<<endl;
        }
    }
}


//归并合并
void unrecur_merge(int *arr, int low, int mid, int high){
    int i = low, j = mid + 1, k = 0;
    int *tmp = new int[high - low + 1];
    while(i <= mid && j <= high){
        if(arr[i] <= arr[j])
            tmp[k++] = arr[i++];
        else
            tmp[k++] = arr[j++];
    }
    while(i <= mid)
        tmp[k++] = arr[i++];
    while(j <= high)
        tmp[k++] = arr[j++];

    for(i = low, k = 0; i <= high; ++i, ++k)
        arr[i] = tmp[k];

    delete[] tmp;
}

//非递归归并
void unrecur_merge_sort(int *arr, int n){
    int m = 1, low, mid, high;

    while(m < n){
        low = 0;
        while(low + m < n){
            mid = low + m - 1;
            high = mid + m;
            if(high > n - 1){
                high = n - 1;
            }
            unrecur_merge(arr, low, mid, high);
            low = high + 1;
        }
        m <<= 1;
    }
}


//计数排序
void count_sort(int *arr, int n){
    if(n < 1) return;
    int counts[MAX_VAL] = {0};
    int *tmp = new int[n];

    memcpy(tmp, arr, n * sizeof(int));

    int m_max = arr[0];
    for(int i = 0; i < n; ++i){
        counts[arr[i]]++;
        m_max = max(m_max, arr[i]);
    }

    for(int i = 1; i <= m_max; ++i){
        counts[i] += counts[i - 1];
    }
    for(int i = n - 1; i >= 0; --i){
        arr[counts[tmp[i]] - 1] = tmp[i];
        counts[tmp[i]]--;

    }
}

void print_arr(int *arr, int n){
    for(int i = 0; i < n - 1; ++i){
            cout << arr[i] << " ";
        }
    cout << arr[n - 1] <<endl;
}

int main(){
    int n;
    while(cin >> n){
        int i = 0;
        int *arr = new int[n];

        while(i < n){
            cin >> arr[i++];
        }

        //bubble_sort(arr, n);
        //insert_sort(arr, n);
        //quick_sort(arr, 0, n);
        //unrecur_quick_sort(arr, 0, n);
        //unrecur_merge_sort(arr, n);
        count_sort(arr, n);

        print_arr(arr, n);

        delete[] arr;
    }
    return 0;
}
