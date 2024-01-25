#include "bits/stdc++.h"
using namespace std;

void setIO(string s){
	ios::sync_with_stdio(0); cin.tie(0);
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}

int main(){
	setIO("herding");

	vector<int>v(3);
	cin >> v[0] >> v[1] >> v[2];
	
	sort(v.begin(), v.end());
	
	int a=v[1]-v[0], b=v[2]-v[1];
	
	int maxn=max(a, b)-1;
	int minn;
	if(a==1 && b==1) minn=0, maxn=0;
	else if(a==2 || b==2) minn=1;
	else minn=2;
	
	cout << minn << '\n' << maxn << '\n';
	return 0;
}
