#include "bits/stdc++.h"
using namespace std;

void setIO(string s){
	ios::sync_with_stdio(0); cin.tie(0);
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}

#define int long long
#define ff first
#define ss second

int32_t main(){
	setIO("rental");

	int n, m, r; cin >> n >> m >> r;
	
	vector<int>cow(n); for(auto &x : cow) cin >> x;
	
	vector<pair<int, int>>buy;
	for(int i=0; i<m; i++){
		int p, q; cin >> p >> q;
		buy.push_back({q, p});
	}
	
	vector<int>rent(r); for(auto &x : rent) cin >> x;
	
	sort(cow.rbegin(), cow.rend());
	sort(buy.rbegin(), buy.rend());
	sort(rent.rbegin(), rent.rend());
	
	int cow_at=0, buy_at=0, rent_at=0;
	int ans=0;
	
	while(cow_at<n){
		int milk=cow[cow_at];
		int curr_buy=buy_at;
		int profit=0;
		int last=0;
		
		while(curr_buy<m){
			int qnt=min(milk, buy[curr_buy].ss);	
			profit+=qnt*buy[curr_buy].ff;
			milk-=qnt;
			
			if(milk==0){
				last=qnt;
				break;
			} else {
				curr_buy++;
			}
		}
		
		if(rent_at>=r || profit>rent[rent_at]){
			ans+=profit;
			buy_at=curr_buy;
			if(buy_at<m) buy[buy_at].second-=last;
			cow_at++;
		} else {
			ans+=rent[rent_at];
			n--;
			rent_at++;
		}
	}
	
	cout << ans << '\n';
	return 0;
}
