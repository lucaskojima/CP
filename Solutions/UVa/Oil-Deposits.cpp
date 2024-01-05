#include <bits/stdc++.h>
using namespace std;

int m, n;
char ma[101][101];

void dfs(int l, int c){
    if(l<0 || c<0 || l>=m || c>=n || ma[l][c]=='*' || ma[l][c]==1){
        return;
    }
    ma[l][c]=1;
    //vertical e horizontal
    dfs(l-1, c);
    dfs(l+1, c);
    dfs(l, c-1);
    dfs(l, c+1);
    //diagonais
    dfs(l-1, c-1);
    dfs(l-1, c+1);
    dfs(l+1, c-1);
    dfs(l+1, c+1);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    while(true){
        cin >> m >> n;
        if(m==0){
            break;
        }
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                cin >> ma[i][j];
            }
        }
        int ans=0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(ma[i][j]=='@'){
                    dfs(i, j);
                    ans++;
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
