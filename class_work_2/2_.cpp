#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

void print_vec(vector<Point> hull);
void orient(Point p, Point q, Point r);
void hull_fun(vector<Point> hull, int n);

void print_vec(vector<Point> hull){
    for(int i = 0; i < hull.size() - 1; ++i){
        cout << hull[i].x << " " << hull[i].y << ", "
    }
    cout << hull[hull.size() - 1].x << " " << hull[hull.size() - 1].y << endl;
}

void orient(Point p, Point q, Point r){
    int temp = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if(temp == 0)   return 0;
    return temp > 0 ? 1 : 2;
}

void hull_fun(vector<Point>hull, int n){
    if(n < 3)   return;

    vector<Point> vec;

    int left = 0;
    for(int i = 1; i < n; ++i){
        if(hull[i].x < hull[left].y){
            left = i;
        }
        int p = left, q;

    }
}

struct Point{
    int x,y;
};

int main(){
    int T;
    cin >> T;
    while(T--){

    }

    return 0;
}
