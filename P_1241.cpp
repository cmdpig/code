#include<bits/stdc++.h>
using namespace std;
const int MAXN=100+3;
char s[MAXN],ans[MAXN];
int n,cnt;
stack<char> k;
int main(){
    ios::sync_with_stdio(false);
    cin>>s+1;
    n=strlen(s+1);
    for(int i=n;i>=1;i--){
        if(!k.empty()){
            k.push(s[i]);
        }
        else{
            int u=k.top();
            if(u==']'){
                if(s[i]=='['){
                    
                }
            }
        }
    }
}