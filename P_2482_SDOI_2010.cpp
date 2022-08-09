/*
主猪/MP：自己存活的情况下消灭所有的反猪。
忠猪/ZP：不惜一切保护主猪，胜利条件与主猪相同。
反猪/FP：杀死主猪。
*/
#include<bits/stdc++.h>
using namespace std;
const int MAXN=2000+3;
const int pin_yin=20;
#define zhu_zhu "MP"
#define zhong_zhu "ZP"
#define fan_zhu "FP"
#define tao "P"
#define sha "K"
#define shan "D"
#define jue_dou "F"
#define nan_zhu_ru_qin "N"
#define wan_zhu_qi_fa "W"
#define wu_xie_ke_ji "J"
#define zhu_ge_lian_nu "Z"
struct ren_wu{
    char shen_fen[10];
    char shou_pai[MAXN];
    int zhuang_bei_flag;
    int pai_shu=4;
    int pai_wei=4;
    int dead_flag;
    int life=4;
};
ren_wu pig[MAXN];
char pai[MAXN];
int shi_jiao[MAXN][MAXN]; //
int wan_jia_num,pai_num,fan_zhu_num;
int pai_zhi_zhen;
void read(){
    cin>>wan_jia_num>>pai_num;
    for(int i=1;i<=wan_jia_num;i++){
        cin>>pig[i].shen_fen;
        for(int j=1;j<=pig[i].pai_wei;j++){
            char c=' ';
            while(c==' '){
                cin>>c;
            }
            pig[i].shou_pai[j]=c;
        }
    }
    for(int i=1;i<=pai_num;i++){
        char c=' ';
        while(c==' '){
            cin>>c;
        }
        pai[i]=c;
    }
}
void write(int num){
    if(num==0) return;
    if(num==1){
        cout<<fan_zhu<<endl;
    }
    else{
        cout<<zhu_zhu<<endl;
    }
    for(int i=1;i<=wan_jia_num;i++){
        if(pig[i].dead_flag==1){
            cout<<"DEAD"<<endl;
        }
        else{
            for(int j=1;j<=pig[i].pai_wei;j++){
                if(pig[i].shou_pai[j]==0) continue;
                cout<<pig[i].shou_pai[j]<<" ";
            }
            cout<<endl;
        }
    }
}
void chou_pai(int num){

}
void chu_pai(int num){

}
bool pan_ding_dead(int num){

}
int pan_ding_victory(){

}
int main(){
    ios::sync_with_stdio(false);
    read();
}