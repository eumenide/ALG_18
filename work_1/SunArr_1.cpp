#include <iostream>
#include <sstream>
#include <vector>
#include <deque>
#include "function.h"


void SunArr_1(){
    string str;

    int left,right,num,counts,a;
    vector<int> vec;
    deque<int> qmax,qmin;

    getline(cin, str);
    stringstream input(str);
    while(input >> a){
        vec.push_back(a);
    }
    cin >> num;

    counts = 0;

    while(left < vec.size()){
        while(right < vec.size()){
            while(!qmax.empty() && vec[right] >= vec[qmax.back()]){
                qmax.pop_back();
            }
            qmax.push_back(right);
            while(!qmin.empty() && vec[right] <= vec[qmin.back()]){
                qmin.pop_back();
            }
            qmin.push_back(right);

            if(vec[qmax.front()] - vec[qmin.front()] > num){
                break;
            }

            right++;
        }


        if(left == qmax.front()){
            qmax.pop_front();
        }
        if(left == qmin.front()){
            qmin.pop_front();
        }
        counts += right - left;
        left++;

    }

    cout << counts << endl;

}
