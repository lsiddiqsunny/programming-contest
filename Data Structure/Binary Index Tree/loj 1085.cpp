
#include<bits/stdc++.h>
using namespace std;
#define mx 100005
long long mod=1000000007;
long long tree[mx*4];
int n;
void update(int x,long long int val)
{
    if(x == 0)
    {
        return ;
    }

    while(x <= n)
    {
        tree[x] +=  val;
        tree[x]%=mod;
        x += x & -x;
    }

}

long long int query(int x)
{
    long long int  ans;
    ans = 0;

    while(x > 0)
    {
        ans = ans + tree[x];
        ans%=mod;

        x = x - (x & (-x));
    }

    return ans;
}


int main()
{
    int test;
    scanf("%d",&test);
    for(int cs=1; cs<=test; cs++)
    {
        scanf("%d",&n);
        long long a[n+1];
        set<long long>s;
        for(int i=1; i<=n; i++)
        {
            scanf("%lld",&a[i]);
            s.insert(a[i]);
        }
        int idx=1;
        map<long long,int>mp;
        set<long long>::iterator it=s.begin();
        for(; it!=s.end(); it++)
        {
            mp[*it]=idx;
            idx++;
        }
        long long ans=0;
        for(int i=0; i<=s.size(); i++)
            tree[i]=0;
        for(int i=1; i<=n; i++)
        {
            ans+=(query(mp[a[i]]-1))+1;
            ans%=mod;
            update(mp[a[i]],(query(mp[a[i]]-1))+1);
        }
        printf("Case %d: %lld\n",cs,ans);

    }
}
