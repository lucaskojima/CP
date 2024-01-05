#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    vector<pair<int, int>>v;
    set<int>s;
    int a;
    while(cin >> a){
        if(s.find(a)==s.end()){
            v.push_back(make_pair(a, 1));
            s.insert(a);
        } else {
            for(int i=0; i<v.size(); i++){
                if(v[i].first==a){
                    v[i].second++;
                }
            }
        }
    }
    for(int i=0; i<v.size(); i++){
        cout << v[i].first << " " << v[i].second << '\n';
    }
    return 0;
}
