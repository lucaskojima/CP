#include "bits/stdc++.h"
using namespace std;

void setIO(string s){
	ios::sync_with_stdio(0); cin.tie(0);
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}

struct type{
	int a, t, o;
	
	bool operator<(const type& other) const {
        return (o<other.o);
    }
};

int main(){
	setIO("convention2");
	
	int n; cin >> n;
	
	vector<type>v;
	for(int i=0; i<n; i++){
		int a, t; cin >> a >> t;
		v.push_back({a, t, i});
	}
	
	sort(v.begin(), v.end(), [&](type x, type y){
		if(x.a!=y.a) return (x.a<y.a);
		return (x.t<y.t);
	});
	
	set<type>st={v[0]};
	int ans=0, t=0, idx=1;
	while(!st.empty()){
		auto ptr=*st.begin(); st.erase(st.begin());
		int ai=ptr.a, ti=ptr.t, oi=ptr.o;
		
		ans=max(ans, t-ai);
		t=max(ai+ti, t+ti);
		
		while((v[idx].a<=t || st.empty()) && idx<n){
			st.insert(v[idx]);
			idx++;
		}
	}
	
	cout << ans;
	return 0;
}
