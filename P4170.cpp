#include<bits/stdc++.h>
using namespace std;
const long long INF=999999999999;
const int MAXN=50+4;
int n;
char color[MAXN];
long long dp[MAXN][MAXN];
int main(){
    ios::sync_with_stdio(false);
    cin>>color+1;
    n=strlen(color+1);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            dp[i][j]=INF;
        }
    }
    for(int i=1;i<=n;i++){
        dp[i][i]=1;
    }
    for(int len=2;len<=n;len++){
        for(int i=1;i+len-1<=n;i++){
            int j=i+len-1;
            if(color[i]==color[j]){
                dp[i][j]=min(dp[i+1][j],dp[i][j-1]);
            }
            else{
                for(int k=i;k<j;k++){
                    dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]);
                }
            }
            
        }
    }
    cout<<dp[1][n];
}