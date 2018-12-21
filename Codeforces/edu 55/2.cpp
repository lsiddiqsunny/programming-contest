#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    int left[n+1],right[n+1];
    memset(left,0,sizeof(left));
    memset(right,0,sizeof(right));
    int co=0;
    for(int i=0;i<n;i++){
        if(s[i]=='G') co++;
    }
    if(co==n){
        cout<<n<<endl;
        return 0;
    }
    for(int i=0;i<n;i++){
        if(s[i]=='G') {
            left[i]=1;
            if(i>0) left[i]+=left[i-1];
        }
    }
    for(int i=n-1;i>=0;i--){
        if(s[i]=='G') {
            right[i]=1;
            if(i<n-1) right[i]+=right[i+1];
        }
    }
    int ans=0;
    for(int i=0;i<n;i++){
        if(s[i]=='G') continue;
        int res=1;
        if(i>0){
            res+=left[i-1];
        }
        if(i<n-1) res+=right[i+1];
        ans=max(ans,res);
    }
    if(co<ans) ans=co;
    cout<<ans<<endl;


}

