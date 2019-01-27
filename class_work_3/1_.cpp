#include <iostream>

using namespace std;

int getMaxEqualLength(string str);

int getMaxEqualLength(string str){
    int result = 0;

    for(int i = 0; i < str.size() - 1; ++i){
        int leftS = 0;
        int rightS = 0;
        for(int j = i, k = i + 1, l = 2; j >= 0 && k < str.size(); j--, k++, l+=2){
            leftS += int(str[j]) - 48;
            rightS += int(str[k]) - 48;
            if(leftS == rightS && l > result){
                result = l;
            }
        }
    }

    return result;

}

int main(){
    int T;
    cin >> T;
    while(T--){
        string str;
        cin >> str;

        cout << getMaxEqualLength(str) << endl;

    }

    return 0;
}
