#include<bits/stdc++.h>
using namespace std;
const int MAXN=16000+3;
int n;
long long dp[MAXN],a[MAXN];
long long ans=-1000000000000;
bool vis[MAXN];
vector<int> tree[MAXN];
void dfs(int num,int fa){
    dp[num]=a[num];
    for(int i=0;i<tree[num].size();i++){
        int y=tree[num][i];
        if(y!=fa){
            dfs(y,num);
            if(dp[y]>0){
                dp[num]+=dp[y];
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<n;i++){
        int A,B;
        cin>>A>>B;
        tree[A].push_back(B);
        tree[B].push_back(A);
    }
    dfs(1,0);
    for(int i=1;i<=n;i++){
        ans=max(ans,dp[i]);
    }
    cout<<ans;
}