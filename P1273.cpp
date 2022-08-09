#include<bits/stdc++.h>
using namespace std;
const int MAXN=3000+3;
struct point{
    int num,money;
    point(int a,int b){num=a,money=b;}
};
vector<point> tree[MAXN];
int n,m;
int dp[MAXN];
int main(){
    ios::sync_with_stdio(false);
    cin>>n>>m;
    for(int i=1;i<=n-m;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            int a,c;
            cin>>a>>c;
            tree[i].push_back(point(a,c));
        }
    }
}
