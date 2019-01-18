#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,k;
    cin>>n>>k;
    int a[n];
    for(int i=0; i<n; i++)
        cin>>a[i];
    int maxi=0;
    int cur=1;
    for(int i=1;i<n;i++){
        if(a[i]!=a[i-1]){
            cur++;
        }
        else{
                maxi=max(maxi,cur);
            cur=1;

        }
    } maxi=max(maxi,cur);
    cout<<maxi<<endl;
}
