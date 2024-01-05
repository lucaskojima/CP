#include <bits/stdc++.h>
using namespace std;

const int MAXN=2e5+10;
int n, m, pai[MAXN], prof[MAXN], sz[MAXN], sum[MAXN];

int find(int v){
    if(pai[v]==v) return v;
    return pai[v]=find(pai[v]);
}

void une(int a, int b){
    a=find(a); b=find(b);
    if(a==b) return;
    if(prof[a]>prof[b]){
        pai[b]=a;
        sz[a]+=sz[b];
        sum[a]+=sum[b];
        return;
    }
    pai[a]=b;
    sz[b]+=sz[a];
    sum[b]+=sum[a];
    if(prof[a]==prof[b]) prof[b]++;
}

void move(int a, int b){
    int k=a;
    a=find(a); b=find(b);
    sz[b]++; sum[b]+=k;
    sz[a]--; sum[a]-=k;
    pai[k]=b;
}

void ini(){
    for(int i=1, j=n+1; i<=n; i++, j++){
        pai[i]=j;
        pai[j]=j;
        sz[j]=1;
        sum[j]=i;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    while(cin >> n >> m){
        ini();
        for(int i=0; i<m; i++){
            int t; cin >> t;
            if(t==1){
                int p, q; cin >> p >> q;
                une(p, q);
            } else if(t==2){
                int p, q; cin >> p >> q;
                move(p, q);
            } else if(t==3){
                int p; cin >> p;
                int f=find(p);
                cout << sz[f] << " " << sum[f] << '\n';
            }
        }
        
        //clear
        for(int i=1; i<=2*n; i++){
            pai[i]=0; prof[i]=1; sz[i]=0; sum[i]=0;
        }
    }
    return 0;
}

