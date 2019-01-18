#include<bits/stdc++.h>
using namespace std;

#define M 100010
#define MOD 1000000007
int marked[M/64 + 2];

#define on(x) (marked[x/64] & (1<<((x%64)/2)))
#define mark(x)  marked[x/64] |= (1<<((x%64)/2))
long long bigmod ( long long a, long long p, long long m=MOD )
{
    long long res = 1;
    long long x = a;

    while ( p )
    {
        if ( p & 1 ) //p is odd
        {
            res = ( res * x ) % m;
        }
        x = ( x * x ) % m;
        p = p >> 1;
    }

    return res;
}
typedef pair<long long int,long long  int> pii;
#define x first
#define y second

pii extendedEuclid(long long int a,long long int b)   // returns x, y | ax + by = gcd(a,b)
{
    if(b == 0)
        return pii(1, 0);
    else
    {
        pii d = extendedEuclid(b, a % b);
        return pii(d.y, d.x - d.y * (a / b));
    }
}
int modularInverse(long long int a)
{
    pii ret = extendedEuclid(a, MOD);
    return ((ret.x % MOD) + MOD) % MOD;
}


void sieve(int n)
{
    for (int i = 3; i * i < n; i += 2)
    {
        if (!on(i))
        {
            for (int j = i * i; j <= n; j += i + i)
            {
                mark(j);
            }
        }
    }
}

bool isPrime(int num)
{
    return num > 1 && (num == 2 || ((num & 1) && !on(num)));
}
vector<int> primes; // we'll preload primes once at the beginning
int sod(long long int n,long long m)
{
    long long k=n;
    long long sum=1;
    long long nowsum=0;
    long long rt=sqrtl(n);
    for (int i = 0; primes[i]<=rt; i++)
    {
        if (n % primes[i] == 0)
        {   //cout<<primes[i]<<endl;
            int cnt = 0;
            while (n % primes[i] == 0)
            {
                n /= primes[i];
                cnt++;
            }
            rt=sqrtl(n);
           //cout<<cnt<<endl;
            long long x=bigmod(primes[i],(cnt*m)+1);
            long long y=modularInverse(primes[i]-1);
            nowsum=(((x-1+MOD)%MOD)*(y%MOD))%MOD;
            sum=((sum%MOD)*(nowsum%MOD))%MOD;

        }

    }
    if(n>1)
    {
        long long x=bigmod(n,m+1);
        long long y=modularInverse(n-1);
        nowsum=(((x-1+MOD)%MOD)*(y%MOD))%MOD;
        sum=((sum%MOD)*(nowsum%MOD))%MOD;
    }
    return sum;
}



int main()
{
    sieve(100005);
    for(int i=2; i<=100000; i++)
    {
        if(isPrime(i))
            primes.push_back(i);
    }
    int test;
    scanf("%d",&test);
    for(int cs=1; cs<=test; cs++)
    {
        long long n,m;
        scanf("%lld%lld",&n,&m);
        printf("Case %d: %lld\n",cs,sod(n,m));
    }


}
