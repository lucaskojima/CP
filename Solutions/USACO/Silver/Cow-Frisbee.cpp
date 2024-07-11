#include "bits/stdc++.h"
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define int long long

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const char nl = '\n';
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f;

int32_t main(){
	ios::sync_with_stdio(0), cin.tie(0);

	int n; cin >> n;
	vector<int>v(n); for(auto &x : v) cin >> x;

	stack<pii>mono_stack;
	int ans=0;

	for(int i=0; i<n; i++){
		while(!mono_stack.empty() && mono_stack.top().ff<v[i]){
			ans+=(i-mono_stack.top().ss+1);
			mono_stack.pop();
		}
		mono_stack.push({v[i], i});
	}

	while(!mono_stack.empty()) mono_stack.pop();

	for(int i=n-1; i>=0; i--){
		while(!mono_stack.empty() && mono_stack.top().ff<v[i]){
			ans+=(mono_stack.top().ss-i+1);
			mono_stack.pop();
		}
		mono_stack.push({v[i], i});
	}

	cout << ans << nl;
	return 0;
}
