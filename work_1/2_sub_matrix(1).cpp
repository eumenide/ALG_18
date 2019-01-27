#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

vector<vector<int>> matrix;

void printMatrix(){
    for(int i = 0; i < matrix.size(); ++i){
        for(int j = 0; j < matrix[0].size(); ++j){
            cout<<matrix[i][j]<<"\t";
        }
        cout<<endl;
    }
}


void inputMatrix(){
    istringstream input;
    string str;
    int tmp;

    while(getline(cin, str)){
        input.clear();
        input.str(str);
        vector<int> tmpV;
        while(input >> tmp){
            tmpV.push_back(tmp);
        }
        matrix.push_back(tmpV);
        //getline(cin, str);
    }
}

int max_rec(){
    int ans = 0;
    int tmp;

    for(int i = 0; i < matrix.size(); ++i){
        for(int j = 0; j < matrix[0].size(); ++j){
            if(matrix[i][j]){
                tmp = 1;
                for(int k = j - 1;k >= 0; --k){
                    if(matrix[i][k] >= matrix[i][j]){
                        tmp++;
                    }else{
                        break;
                    }
                }
                for(int k = j + 1; k < matrix[0].size(); ++k){
                    if(matrix[i][k] >= matrix[i][j]){
                        tmp++;
                    }else{
                        break;
                    }
                }
                ans = max(ans, tmp * matrix[i][j]);
            }
        }
    }

    return ans;
}

int main(){

    inputMatrix();
    //printMatrix();

    for(int i = 1; i < matrix.size(); ++i){
        for(int j = 0; j < matrix[0].size(); ++j){
            if(matrix[i][j]){
                matrix[i][j] += matrix[i-1][j];
            }
        }
    }

    //printMatrix();

    cout<<max_rec()<<endl;


    return 0;
}
