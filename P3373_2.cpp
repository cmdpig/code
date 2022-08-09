#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5*4+3;
struct tree{
	long long left,right,sum,plus_det,mul_det=1;
};
tree k[MAXN];
long long a[MAXN];
int n,m,mod;
void build(int num,int l,int r){
	k[num].left=l,k[num].right=r;
	if(l==r){
		k[num].sum=a[l];
		k[num].left=l;
		k[num].right=r;
	}
	else{
		long long mid=(l+r)/2;
		build(num*2,l,mid);
		build(num*2+1,mid+1,r);
		k[num].sum=k[num*2].sum+k[num*2+1].sum;
		k[num].left=l;
		k[num].right=r;
	}
}
void pushdown(int num){
		k[num*2].sum=k[num*2].sum*k[num].mul_det+k[num].plus_det*(k[num*2].right-k[num*2].left+1);
		k[num*2+1].sum=k[num*2+1].sum*k[num].mul_det+k[num].plus_det*(k[num*2+1].right-k[num*2+1].left+1);	
		
		k[num*2].mul_det*=k[num].mul_det;
		k[num*2].plus_det=k[num*2].plus_det*k[num].mul_det+k[num].plus_det;
		k[num*2+1].mul_det*=k[num].mul_det;
		k[num*2+1].plus_det=k[num*2+1].plus_det*k[num].mul_det+k[num].plus_det;
		
		k[num].mul_det=1;		
		k[num].plus_det=0;
	
}
long long get_sum(int num,int l,int r){
	if( (k[num].left==l) && (k[num].right==r) ){
		return k[num].sum%mod;
	}
	else{
		pushdown(num);
		int mid=(k[num].left+k[num].right)/2;
		if(r<=mid){
			return get_sum(num*2,l,r)%mod;
		}
		else if(l>mid){
			return get_sum(num*2+1,l,r)%mod;
		}
		else{
			return (get_sum(num*2,l,mid)%mod+get_sum(num*2+1,mid+1,r)%mod)%mod;
		}
	}
}
void sec_plus(int num,int l,int r,long long x){
	if(k[num].left>=l&&k[num].right<=r){
		k[num].sum+=x*(k[num].right-k[num].left+1);
		k[num].plus_det+=x;
	}
	else{
		pushdown(num);
		int mid=(k[num].left+k[num].right)/2;
		if(r<=mid) {
			sec_plus(num*2,l,r,x);
		}
		else if(l>mid) {
			sec_plus(num*2+1,l,r,x);
		}
		else{
			sec_plus(num*2,l,mid,x);
			sec_plus(num*2+1,mid+1,r,x);			
		}
		k[num].sum=k[num*2].sum+k[num*2+1].sum;
	}
}
void sec_mul(int num,int l,int r,long long x){
	if(k[num].left>=l&&k[num].right<=r){
		k[num].sum*=x;
		k[num].mul_det*=x;
	}
	else{
		pushdown(num);
		int mid=(k[num].left+k[num].right)/2;
		if(r<=mid) {
			sec_mul(num*2,l,r,x);
		}
		else if(l>mid) {
			sec_mul(num*2+1,l,r,x);
		}
		else{
			sec_mul(num*2,l,mid,x);
			sec_mul(num*2+1,mid+1,r,x);			
		}
		k[num].sum=k[num*2].sum+k[num*2+1].sum;
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin>>n>>m>>mod;
	for(int i=1;i<=n;i++){
   		cin>>a[i];
	}
	build(1,1,n);
	for(int i=1;i<=m;i++){
		int flag;
		cin>>flag;
		if(flag==1){
			int x,y,z;
			cin>>x>>y>>z;
			sec_mul(1,x,y,z);
		}
		else if(flag==2){
			int x,y,z;
			cin>>x>>y>>z;
			sec_plus(1,x,y,z);
		}
		else{
			int x,y;
			cin>>x>>y;
			long long d=get_sum(1,x,y);
			cout<<d<<endl;
		}
	}
}