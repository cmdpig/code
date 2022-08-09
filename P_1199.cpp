#include<bits/stdc++.h>
using namespace std;
const int MAXN=5000+5;
int n;
int ans,s[MAXN][MAXN];
int main(){
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            cin>>s[i][j];
            s[j][i]=s[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        sort(s[i]+1,s[i]+n+1);
        ans=max(ans,s[i][n-1]);
    }
    cout<<1<<endl<<ans;

}