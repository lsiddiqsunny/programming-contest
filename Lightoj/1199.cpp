#include<bits/stdc++.h>
using namespace std;

int g[10005];
int exist[10005];
int getgrundy(int n)
{
    memset(exist,0,sizeof(exist));
    for(int i=1; i<=n/2; i++)
    {
        if(i==n-i)
            continue;
        exist[g[i]^g[n-i]]=1;
    }
    int grundy=0;
    while(exist[grundy])
        grundy++;
    return grundy;

}
int main()
{

    for(int i=3; i<=10000; i++)
        g[i]=getgrundy(i);
    int test;
    scanf("%d",&test);
    for(int cs=1; cs<=test; cs++)
    {
        int n;
        scanf("%d",&n);
        int ans=0;
        for(int i=0;i<n;i++){
            int x;
            scanf("%d",&x);
            ans^=g[x];
        }
        if(ans){
            printf("Case %d: Alice\n",cs);
        }
        else             printf("Case %d: Bob\n",cs);




    }
}



