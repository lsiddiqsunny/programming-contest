#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    int a[n];

    for(int i=0; i<n; i++)
    {
        cin>>a[i];
        a[i]-=m;
    }
    for(int i=0; i<n; i++)
    {
        if(a[i]<0)
        {
            cout<<"NO"<<endl;
            return 0;
        }
    }
    if(m*n==60)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;

}
