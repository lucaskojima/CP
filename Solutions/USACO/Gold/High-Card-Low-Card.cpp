#include "bits/stdc++.h"
using namespace std;

#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()

template<typename T>
using matrix = vector<vector<T>>;
using pii = pair<int, int>;
using ll = long long;

const char nl = '\n';

const ll LINF = (1LL<<60);
const int INF = (1<<30);

void setIO(string s){
	ios::sync_with_stdio(0); cin.tie(0);
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}

int main(){
	setIO("cardgame");

	int n; cin >> n;

	vector<int>marc(2*n+1);
	vector<int>essie;

	for(int i=0; i<n; i++){
		int a; cin >> a;
		essie.push_back(a);	
		marc[a]=1;
	}	

	vector<int>bessie;
	for(int i=1; i<=2*n; i++){
		if(marc[i]==0) bessie.push_back(i);
	}

	set<int>st_min, st_max;
	for(int i=0; i<n/2; i++) st_min.insert(bessie[i]);
	for(int i=n/2; i<n; i++) st_max.insert(bessie[i]);

	int ans=0;
	for(int i=0; i<n/2; i++){
		auto it=st_max.upper_bound(essie[i]);
		if(it!=st_max.end()){
			ans++;
			st_max.erase(it);
		}
	}

	for(int i=n/2; i<n; i++){
		auto it=st_min.lower_bound(essie[i]);
		if(it!=st_min.begin()){
			it--;
			ans++;
			st_min.erase(it);
		}
	}

	cout << ans << nl;
	return 0;
}
