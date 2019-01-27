#include <bits/stdc++.h>
using namespace std;

struct Point
{
	int x, y;
};

int orientation(Point p, Point q, Point r)
{
	int val = (q.y - p.y) * (r.x - q.x) -
			(q.x - p.x) * (r.y - q.y);

	if (val == 0) return 0;
	return (val > 0)? 1: 2;
}

static bool myCompare(const Point& p, const Point& q){
    return p.x <= q.x;
}

void convexHull(vector<Point> points, int n)
{
	if (n < 3) return;

	vector<Point> hull;

	int l = 0;
	for (int i = 1; i < n; i++)
		if (points[i].x < points[l].x)
			l = i;

	int p = l, q;
	do
	{
		hull.push_back(points[p]);

		q = (p+1)%n;
		for (int i = 0; i < n; i++){
            if (orientation(points[p], points[i], points[q]) == 2)
                q = i;
		}
		p = q;

	} while (p != l);

	if(hull.size() == 0){
        cout<<-1<<endl;
        return;
	}

	sort(hull.begin(), hull.end(), myCompare);
	for (int i = 0; i < hull.size() - 1; i++){
        cout<<hull[i].x<<" " << hull[i].y << ", ";
	}
    cout<<hull[hull.size() - 1].x<<" "<<hull[hull.size() - 1].y<<endl;
}


int main(){
    int T;
    cin >> T;
    while(T--){
        vector<Point> vec;
        int n;
        cin >>n;
        for(int i = 0; i < n; ++i){
            Point p;
            cin >> p.x >> p.y;
            vec.push_back(p);
        }

        convexHull(vec, n);
    }

	return 0;
}
