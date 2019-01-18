#include<bits/stdc++.h>
using namespace std;
int main()
{

    int n;
    cin>>n;
    int a[n+1];
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];

    }
    int ans=INT_MAX;
    for(int i=1;i<=n;i++){
        int now=0;
        for(int j=1;j<=n;j++){
            now+=(abs(i-j)*2+abs(j-1)*2+abs(i-1)*2)*a[j];//cout<<now<<endl;
        }


        ans=min(ans,now);
    }
    cout<<ans<<endl;
}
