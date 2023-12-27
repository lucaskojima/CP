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

int itc_area(rect a, rect b){
	int x=max(min(a.x2, b.x2)-max(a.x1, b.x1), 0);
	int y=max(min(a.y2, b.y2)-max(a.y1, b.y1), 0);
	return x*y;
}

int main(){
	setIO("billboard");

	rect a, b;
	cin >> a.x1 >> a.y1 >> a.x2 >> a.y2;
	cin >> b.x1 >> b.y1 >> b.x2 >> b.y2;
	
	int ans=a.area();
	if((b.x1<=a.x1 && b.x2>=a.x2 && !(a.y1<b.y1 && a.y2>b.y2)) || (b.y1<=a.y1 && b.y2>=a.y2 && !(a.x1<b.x1 && a.x2>b.x2))){
		ans-=itc_area(a, b);
	}
	
	cout << ans;
	return 0;
}
