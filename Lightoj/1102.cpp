#include<bits/stdc++.h>
using namespace std;
const long long mod=1000000007;
long long fact[2000005];

long long mod_pow(long long b, long long e, long long m)
{
    long long ans = 1;
    while (e > 0)
    {
        if (e & 1)
            ans = (ans * b) % m;
        b = (b * b) % m;
        e >>= 1;
    }
    return ans;
}
int main()
{
    fact[0]=fact[1]=1;
    for(long long i=2; i<=2000004; i++)
    {
        fact[i]=(fact[i-1]%mod*(i%mod))%mod;
    }
    int test;
    scanf("%d",&test);
    for(int cs=1; cs<=test; cs++)
    {
        int n,k;
        scanf("%d%d",&n,&k);
        long long ans=fact[n+k-1];
        long long ans2=(fact[n]%mod * fact[k-1]%mod)%mod;
        ans2=mod_pow(ans2,mod-2,mod);
        printf("Case %d: %lld\n",cs,(ans%mod *ans2%mod)%mod);
    }
}


