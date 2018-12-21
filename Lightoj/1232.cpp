#include<bits/stdc++.h>
using namespace std;
int mod=100000007;
int main(){
    int test;
    cin>>test;
    for(int cs=1;cs<=test;cs++){
        int n,k;
        cin>>n>>k;
        int a[n];
        for(int j=0;j<n;j++) cin>>a[j];
        int w[k+1];
        memset(w,0,sizeof(w));
        w[0]=1;
        for(int i=0;i<n;i++){
            for(int j=1;j<=k;j++){
                if(a[i]<=j){
                    w[j]+=w[j-a[i]];
                }
                w[j]=w[j]%mod;
            }
        }
        cout<<"Case "<<cs<<": "<<w[k]<<endl;
    }
}
