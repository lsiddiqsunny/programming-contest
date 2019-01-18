#include<bits/stdc++.h>
using namespace std;
int main(){
long long n,m;
cin>>n>>m;
if(m==1){
    cout<<n*n<<endl;
    return 0;
}
long long co=0;
vector<int>mp[m+1];
for(long long int i=1;i<=min(m,n);i++){
    for(long long int j=1;j<=min(m,n);j++){
        if((i*i+j*j)%m==0){
           // co++;
            mp[i].push_back(j);
        }
    }
}
for(long long int i=1;i<=min(m,n);i++){
    for(long long int j=0;j<mp[i].size();j++ ){
        long long now=(n-mp[i][j])/m+1;
       long long now1=(n-i)/m+1;
       co+=(now*now1);

    }
}

cout<<co<<endl;
}
