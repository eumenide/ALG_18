#include <iostream>
#include <sstream>
#include <stdio.h>
#include <cstring>

using namespace std;

string findPatternIndex(string text, string pattern);

string findPatternIndex(string text, string pattern){
    string result = "";
    ostringstream oss;

    for(int i = 0; i < text.size(); ++i){
        for(int j = 0; j < pattern.size();){
            if(text[i+j] == pattern[j]){
                j++;
            }else{
                break;
            }
            if(j == pattern.size()){
                oss << i << " ";
            }
        }
    }

    result = oss.str();
    if(result != ""){
        result = result.substr(0, result.size() - 1) ;
    }

    return result;
}

int main(){
    int T;
    cin >> T;
    getchar();
    while(T--){
        string text;
        string pat;

        getline(cin, text);
        int index = text.find(",");
        pat = text.substr(index + 1, text.size());
        text = text.substr(0, index);

        cout << findPatternIndex(text, pat) << endl;
    }

    return 0;
}
