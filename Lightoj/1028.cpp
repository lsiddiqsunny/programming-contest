#include<bits/stdc++.h>
using namespace std;


#define M 1000010
int marked[M/64 + 2];

#define on(x) (marked[x/64] & (1<<((x%64)/2)))
#define mark(x)  marked[x/64] |= (1<<((x%64)/2))

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

vector<int>primes;

long long int countDivisor(long long int n)
{
    if(n<=1000000)
    {
        if(isPrime(n))
            return 2;
    }
    long long  int divisor = 1;
    for (int i = 0; i*i <=n and i<primes.size(); i++)
    {
        if (n % primes[i] == 0)
        {
            long long  int cnt = 1;
            while (n % primes[i] == 0)
            {
                n /= primes[i];
                cnt++;
            }
            divisor *= cnt;
        }
        if(n<=1)
            return divisor;
        if(n<=1000000 and n!=1)
        {
            if(isPrime(n))
            {
                return divisor*2;
            }
        }
    }
    if(n!=1){
        divisor*=2;
    }
    return divisor;
}



int main()
{
    sieve(1000005);
    for(int i=2; i<=1000000; i++)
    {
        if(isPrime(i))
            primes.push_back(i);
    }
    int test;
    scanf("%d",&test);
    for(int cs=1; cs<=test; cs++)
    {
        long long n;
        scanf("%lld",&n);
        long long res=countDivisor(n)-1;
        printf("Case %d: %lld\n",cs,res);

    }


}

