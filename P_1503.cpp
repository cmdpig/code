#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e4+7;
struct Splay{
    int rt,fa[MAXN],ch[MAXN][2],size[MAXN],tot,cnt[MAXN],val[MAXN];
    /*
    ch[i][0]:左子树
    ch[i][1]:右子树
    cnt[i]:去重后序号i的数的出现次数
    size[i]:以i为根的子树的大小
    tot:去重后的节点总数
    */
    void update(int x){size[x]=size[ch[x][0]]+size[ch[x][1]]+cnt[x];}
    bool son(int x){return x==ch[fa[x]][1];}
    void destory(int x){fa[x]=size[x]=cnt[x]=val[x]=ch[x][1]=ch[x][0]=0;}
    void rotate(int x){
        int y=fa[x],z=fa[y],son_num=son(x);
        ch[y][son_num]=ch[x][son_num^1];
        if(ch[x][son_num^1]) fa[ch[x][son_num^1]]=y;
        fa[y]=x;
        ch[x][son_num^1]=y;
        fa[x]=z;
        if(z) ch[z][y==ch[z][1]]=x;
        update(y);
        update(x);
    }
    void splay(int x){
        for(int f=fa[x];f=fa[x],f;rotate(x))
            if(fa[f]) rotate(son(x)==son(f)? f : x);
        rt=x;
    }
    void insert(int x){
        if(!rt){
            val[++tot]=x;
            cnt[tot]++;
            rt=tot;
            update(rt);
            return;
        }
        int pos=rt,Fa=0;
        while(1){
            if(val[pos]==x){
                cnt[pos]++;
                update(pos);
                update(Fa);
                splay(pos);
                break;
            }
            Fa=pos;
            pos=ch[pos][val[pos]<x];
            if(!pos){
                val[++tot]=x;
                cnt[tot]++;
                fa[tot]=Fa;
                ch[Fa][val[Fa]<x]=tot;
                update(tot);
                update(Fa);
                splay(tot);
                break;
            }
        }
    }
    int rk(int x){
        int ans=0,pos=rt;
        while(1){
            if(x<val[pos]){
                pos=ch[pos][0];
            }
            else{
                ans+=(ch[pos][0]?size[ch[pos][0]]:0);
                if(x==val[pos]){
                    splay(pos);
                    return ans+1;
                }
                ans+=cnt[pos];
                pos=ch[pos][1];
            }
        }
    }
    int kth(int k){
        int pos=rt;
        while(1){
            if(ch[pos][0]&&k<=size[ch[pos][0]]){
                pos=ch[pos][0];
            }
            else{
                k-=cnt[pos]+size[ch[pos][0]];
                if(k<=0){
                    splay(pos);
                    return val[pos];
                }
                pos=ch[pos][1];
            }
        }
    }
    int pre(){
        int pos=ch[rt][0];
        if(!pos) return pos; 
        while(ch[pos][1]) pos=ch[pos][1];
        splay(pos);
        return pos;
    }
    int nxt(){
        int pos=ch[rt][1];
        if(!pos) return pos;
        while(ch[pos][0]) pos=ch[pos][0];
        splay(pos);
        return pos;
    }
    void del(int x){
        rk(x);
        if(cnt[rt]>1){
            cnt[rt]--;
            update(rt);
            return;
        }
        if(!ch[rt][0]&&!ch[rt][1]){
            destory(rt);
            rt=0;
            return;
        }
        if(!ch[rt][0]){
            int pos=rt;
            rt=ch[rt][1];
            fa[rt]=0;
            destory(pos);
            return;
        }
        if(!ch[rt][1]){
            int pos=rt;
            rt=ch[rt][0];
            fa[rt]=0;
            destory(pos);
            return;
        }
        int pos=rt,k=pre();
        fa[ch[pos][1]]=k;
        ch[k][1]=ch[pos][1];
        destory(pos);
        update(rt);
    }
};
Splay tree;
int n,m;
bool vis[MAXN];
stack<int> work;
int main(){
    ios::sync_with_stdio(false);
    cin>>n>>m;
    tree.insert(0);
    tree.insert(n+1);
    for(int i=1;i<=m;i++){
        char s;
        int a;
        cin>>s;
        if(s=='D'){
            cin>>a;
            work.push(a);
            tree.insert(a);
            vis[a]=true;
        }
        else if(s=='R'){
            int u=work.top();
            work.pop();
            tree.del(u);
            vis[u]=false;
        }
        else{
            cin>>a;
            if(vis[a]){
                cout<<0<<endl;
            }
            else{
                tree.insert(a);
                cout<<tree.val[tree.nxt()]-tree.val[tree.pre()]-1<<endl;
                tree.del(a);
            }
        }
    }
    return 0;
}