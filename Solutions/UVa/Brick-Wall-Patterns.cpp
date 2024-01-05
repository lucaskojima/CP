#include <bits/stdc++.h>
using namespace std;

int rec(int n){
	if(n==1) return 1;
	if(n==2) return 2;
	return rec(n-1)+rec(n-2);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	while(true){
		cin >> n;
		if(n==0) break;
		cout << rec(n) << '\n';
	}
	return 0;
}

