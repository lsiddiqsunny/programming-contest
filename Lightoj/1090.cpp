#include<bits/stdc++.h>
using namespace std;
long long fact(int val, long long p)
{
    long long ans = 0;
    long long b = p;
    while (b <= val)
    {
        ans += val / b;
        b *= p;
    }
    return ans;
}

long long get(int n, int r, int p, int q, int cur)
{
    long long ans = fact(n, cur) - fact(r, cur) - fact(n - r, cur);
    int exp = 0;
    while (p % cur == 0)
    {
        exp++;
        p /= cur;
    }

    ans += q * exp;
    return ans;
}
int main()
{
    int test;
    scanf("%d",&test);
    for(int cs=1; cs<=test; cs++)
    {

        long long n,r,p,q;
        scanf("%lld%lld%lld%lld",&n,&r,&p,&q);

        long long ans=min(get(n,r,p,q,2),get(n,r,p,q,5));
        printf("Case %d: %lld\n",cs,ans);

    }




}
