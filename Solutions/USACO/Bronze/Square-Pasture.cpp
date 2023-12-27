#include "bits/stdc++.h"
using namespace std;

void setIO(string s){
	ios::sync_with_stdio(0); cin.tie(0);
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}

struct rect{
	int x1, y1, x2, y2;
	int area() {return (x2-x1)*(y2-y1);}
};

int main(){
	setIO("square");

	rect a, b;
	cin >> a.x1 >> a.y1 >> a.x2 >> a.y2;
	cin >> b.x1 >> b.y1 >> b.x2 >> b.y2;
	
	int k=max(max(a.x2, b.x2)-min(a.x1, b.x1), max(a.y2, b.y2)-min(a.y1, b.y1));
	cout << k*k;
	return 0;
}
