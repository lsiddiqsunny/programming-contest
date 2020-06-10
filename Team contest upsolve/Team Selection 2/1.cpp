#include<bits/stdc++.h>
using namespace std;
#define mx 255
long long dp[mx][mx];
long long coin[mx];
int m;
long long cal(long long n,int id){
    if(n<0) return 0;
    if(n==0) return 1;
    if(id>=m) return 0;
    if(dp[n][id]!=-1){
        return dp[n][id];
    }
    dp[n][id]=cal(n-coin[id],id)+cal(n,id+1);
    return dp[n][id];
}

int main(){
    int n;
    cin>>n>>m;
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<m;i++){
        cin>>coin[i];
    }
    cout<<cal(n,0);
}
