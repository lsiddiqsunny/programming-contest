#include<bits/stdc++.h>
using namespace std;
int main(){
int n,k;
cin>>n>>k;
int a[n];
for(int i=0;i<n;i++){
        cin>>a[i];
}
sort(a,a+n);
int co=0;
for(int i = 0; i < n; i++)
    if (5 - a[i] >= k)
        co++;

int ans = co / 3;
cout<<ans<<endl;
}
