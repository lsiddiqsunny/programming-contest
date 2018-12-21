#include<bits/stdc++.h>
using namespace std;
vector<int>g[100005];
int main(){
int n;
cin>>n;
int a[n];
map<int,int>mp;
for(int i=0;i<n;i++){
    cin>>a[i];
    g[a[i]].push_back(i);
    mp[a[i]]++;
}
vector<pair<int,int> >v;
for(auto x:mp){
    v.push_back(make_pair(x.second,x.first));
}
sort(v.begin(),v.end());
int now=1;
int b[n];
memset(b,0,sizeof(b));
int need=n;
for(int i=0;i<v.size();i++){

int x=v[i].second;
int co=0;
for(int j=0;j<g[x].size();j++){
    b[g[x][j]]=now;
    co++;
}
//cout<<co<<endl;
if(x!=(n-co)){
    cout<<"Impossible"<<endl;
    return 0;
}
now++;
}


    

cout<<"Possible"<<endl;
for(int i=0;i<n;i++){
    cout<<b[i]<<" ";
}



}