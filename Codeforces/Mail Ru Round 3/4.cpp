#include<bits/stdc++.h>
using namespace std;
#define mx 100005
vector<int>g[mx];
int child[mx];
int vis[mx];
void dfs(int s,int u){
    vis[s]=1;

    bool ok=0;
    for(int j=0;j<g[s].size();j++){
        int v=g[s][j];
        if(v==u) continue;
        ok=1;

            dfs(v,s);
        child[s]+=child[v];
    }
if(!ok) child[s]=1;


}

int main(){
int n;
cin>>n;
for(int i=2;i<=n;i++){
    int x;
    cin>>x;
   // x=1;
    g[i].push_back(x);
    g[x].push_back(i);

}
dfs(1,0);
int co=0;
map<int ,int >mp;
for(int i=1;i<=n;i++){
    //child[i]--;
    mp[child[i]]++;
   // cout<<child[i]<<endl;
}
int k=1;
for(int i=1;i<=n;i++){
    if(k>n) break;
    for(int j=1;j<=mp[i];j++){
        if(k>n) break;
        cout<<i<<" ";
        k++;
       // mp[i]--;
    }
}





}
