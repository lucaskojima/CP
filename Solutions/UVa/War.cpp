#include <bits/stdc++.h>
using namespace std;

const int MAXN=2e4+10;
int n, pai[MAXN], prof[MAXN];

int find(int v){
    if(pai[v]==v) return v;
    return pai[v]=find(pai[v]);
}

void une(int a, int b){
    a=find(a); b=find(b);
    if(a==b) return;
    if(prof[a]>prof[b]){
        pai[b]=a;
        return;
    }
    pai[a]=b;
    if(prof[a]==prof[b]) prof[b]++;
}

int enemy(int x){
    return x+n;
}

bool is_friend(int a, int b){
    if(find(a)==find(b) && find(enemy(a))==find(enemy(b))) return true;
    return false;
}

bool is_enemy(int a, int b){
    if(find(a)==find(enemy(b)) && find(enemy(a))==find(b)) return true;
    return false;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i=0; i<2*n; i++) pai[i]=i;
    int c, x, y;
    while(cin >> c >> x >> y){
        if(c==0 && x==0 && y==0) break;
        if(c==1){
            if(is_enemy(x, y)){
                cout << "-1\n";
            } else {
                une(x, y);
                une(enemy(x), enemy(y));
            }
        } else if(c==2){
            if(is_friend(x, y)){
                cout << "-1\n";
            } else {
                une(x, enemy(y));
                une(enemy(x), y);
            }
        } else if(c==3){
            cout << (is_friend(x, y) ? "1\n" : "0\n");
        } else if(c==4){
            cout << (is_enemy(x, y) ? "1\n" : "0\n");
        }
    }
    return 0;
}
