#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	vector<int>v(7);
	for(int i=0; i<7; i++){
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	cout << v[0] << " " << v[1] << " ";
	if(v[0]+v[1]+v[2]==v[6]){
		cout << v[2];
	} else {
		cout << v[3];
	}
	return 0;
}
