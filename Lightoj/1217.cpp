#include<bits/stdc++.h>
using namespace std;
int main()
{
    int test;
    cin>>test;
    for(int cs=1; cs<=test; cs++)
    {
        int n;
        cin>>n;
        int a[n+1];
        for(int j=1; j<=n; j++) cin>>a[j];
        int f[n+1],s[n+1];
        memset(f,0,sizeof f);
        memset(s,0,sizeof s);
        s[1]=a[1];
        for(int i=2; i<=n; i++)
        {
            f[i]=max(f[i-1],f[i-2]+a[i]);
            s[i]=max(s[i-1],s[i-2]+a[i]);

        }
        cout<<"Case "<<cs<<": "<<max(f[n],s[n-1])<<endl;
    }
}
