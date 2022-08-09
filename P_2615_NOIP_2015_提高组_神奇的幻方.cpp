#include<bits/stdc++.h>
using namespace std;
const int MAXN=39*39+3;
struct point{
    int x,y;
};
point k[MAXN];
int n,s[MAXN][MAXN];
int main(){
    ios::sync_with_stdio(false);
    cin>>n;
    k[1].x=1;
    k[1].y=n/2+1;
    s[k[1].x][k[1].y]=1;
    for(int i=2;i<=n*n;i++){
        if((k[i-1].x==1)&&k[i-1].y!=n){
            k[i].x=n,k[i].y=k[i-1].y+1;
        }
        else if((k[i-1].x!=1)&&k[i-1].y==n){
            k[i].x=k[i-1].x-1,k[i].y=1;
        }
        else if((k[i-1].x==1)&&k[i-1].y==n){
            k[i].x=k[i-1].x+1,k[i].y=n;
        }
        else if(s[k[i-1].x-1][k[i-1].y+1]==0){
            k[i].x=k[i-1].x-1,k[i].y=k[i-1].y+1;
        }
        else{
            k[i].x=k[i-1].x+1,k[i].y=k[i-1].y;
        }
        s[k[i].x][k[i].y]=i;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<s[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}