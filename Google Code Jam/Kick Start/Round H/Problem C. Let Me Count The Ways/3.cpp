#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

//inclusion exclusion principle
#define mx 200005
#define mod 1000000007
ll fact[mx];
ll power[mx];
ll inv[mx];

ll fastpower(ll a,ll p)
{
    if(p==0)
        return 1%mod;
    if(p==1)
        return (a%mod);
    ll x=fastpower(a,p/2);
    if(p%2==0)
    {
        return ((x%mod)*(x%mod))%mod;
    }
    else
        return ((a%mod) *(((x%mod)*(x%mod))%mod))%mod;


}

void precal()
{
    fact[0]=1;
    for(int i=1; i<mx; i++)
    {
        fact[i]=(fact[i-1]%mod * i%mod)%mod;
    }
    inv[mx-1]=fastpower(fact[mx-1],mod-2);
    for(int i=mx-2; i>=0; i--)
    {
        inv[i]=(inv[i+1]%mod *(i+1)%mod)%mod;
    }

    power[0]=1;
    for(int i=1; i<mx; i++)
    {
        power[i]=(power[i-1]%mod * 2%mod)%mod;
    }



}


ll combin(int n,int r) {
    return ((fact[n] * inv[r]) %mod * (inv[n - r] % mod))%mod;
}

int main()
{
    freopen("C-large-practice.in","r",stdin);
    freopen("output.txt", "w", stdout);
    precal();
    int test;
    cin>>test;
    for(int cs=1; cs<=test; cs++)
    {

        int n,k;
        cin>>n>>k;
        n*=2;
        ll ans=0;
        for(int i=0;i<=k;i++){
            ll subans = (combin(k,i) * (power[i] % mod * fact[n - i] % mod))%mod;
            if(i % 2) ans = (ans + mod - subans) % mod;
            else ans = (ans + subans) % mod;
        }
        cout<<"Case #"<<cs<<": "<<ans<<endl;

    }
}
