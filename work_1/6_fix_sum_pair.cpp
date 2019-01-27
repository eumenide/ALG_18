#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

int main(){
    string str;
    getline(cin, str);
    stringstream input(str);

    int left,right,num,a, counts  = 0;
    vector<int> vec;

    while(input >> a){
        vec.push_back(a);
    }

    cin >> num;

    sort(vec.begin(), vec.end());


    left = 0;
    right = vec.size() - 1;

    int num_l, num_r;

    while(left < right){
        if(vec[left] + vec[right] < num){
            left++;
        }
        else if(vec[left] + vec[right] > num){
            right--;
        }
        else{
            //counts++;
            num_l = num_r = 1;
            if(vec[left] == vec[right]){
                counts += (2 + right - left) * (right - left + 1) / 2;
                break;
            }else{
                while(vec[left] == vec[++left]){
                    num_l++;
                }
                while(vec[right] == vec[--right]){
                    num_r++;
                }
                counts += num_l * num_r;
            }
        }

    }

    cout << counts << endl;

    return 0;
}
