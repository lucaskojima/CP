#include <bits/stdc++.h>
using namespace std;

int n, q;
vector<int>v(5e4+1);

int reverse_upperbound(int x){
    int l=-1; //l<x
    int r=n;  //r>=x
    while(r>l+1){
        int m=(r+l)/2;
        if(v[m]<x){
            l=m;
        } else {
            r=m;
        }
    }
    return l;
}

int upperbound(int x){
    int l=-1; //l<=x
    int r=n;  //r>x
    while(r>l+1){
        int m=(r+l)/2;
        if(v[m]<=x){
            l=m;
        } else {
            r=m;
        }
    }
    return r;
}

int main(){
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> v[i];
    }
    cin >> q;
    for(int i=0; i<q; i++){
        int a;
        cin >> a;
        int min=reverse_upperbound(a);
        int max=upperbound(a);
        if(min==-1){
            cout << "X ";
        } else {
            cout << v[min] << " ";
        }
        if(max==n){
            cout << "X";
        } else {
            cout << v[max];
        }
        cout << '\n';
    }
    return 0;
}
