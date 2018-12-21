#include<bits/stdc++.h>
using namespace std;
int main(){
int test;
cin>>test;
for(int i=1;i<=test;i++){
    int n;
    cin>>n;
    string s;
    cin>>s;
    int ans=0;
    for(int j=0;j<n;j++){
        if(s[j]=='.') {ans++;
        j=j+2;
        }
    }
    cout<<"Case "<<i<<": "<<ans<<endl;
}
}
