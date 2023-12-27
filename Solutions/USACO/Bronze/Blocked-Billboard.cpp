#include "bits/stdc++.h"
using namespace std;

void setIO(string s){
	ios::sync_with_stdio(0); cin.tie(0);
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}

struct rect{
	int x1, y1, x2, y2;
	int area() {return(x2-x1)*(y2-y1);}
};

int itc(rect a, rect b){
	int x=max(min(a.x2, b.x2)-max(a.x1, b.x1), 0);
	int y=max(min(a.y2, b.y2)-max(a.y1, b.y1), 0);
	return x*y;
}

int main(){
	setIO("billboard");

	rect a, b, t;
	cin >> a.x1 >> a.y1 >> a.x2 >> a.y2;
	cin >> b.x1 >> b.y1 >> b.x2 >> b.y2;
	cin >> t.x1 >> t.y1 >> t.x2 >> t.y2;
	
	cout << a.area()+b.area()-itc(a, t)-itc(b, t);
	return 0;
}
