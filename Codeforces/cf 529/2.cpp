#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    if(n==2){
        cout<<0<<endl;
        return 0;
    }
    int ans=a[n-2]-a[0];
    int ans2=a[n-1]-a[1];
    cout<<min(ans,ans2);


}

