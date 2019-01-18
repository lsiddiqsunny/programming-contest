#include <bits/stdc++.h>
using namespace std;



#define REP(i,n) for (int i = 1; i <= n; i++)


typedef long long ll;
typedef vector<vector<ll> > matrix;
const ll MOD = 1000000007;
int K=2 ;


matrix mul(matrix A, matrix B)
{
    matrix C(K+1, vector<ll>(K+1));
    REP(i, K) REP(j, K) REP(k, K)
    C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
    return C;
}

// computes A ^ p
matrix pow(matrix A, int p)
{
    if (p == 1)
        return A;
    if (p % 2)
        return mul(A, pow(A, p-1));
    matrix X = pow(A, p/2);
    return mul(X, X);
}

matrix fib(int N)
{


    matrix T(K+1, vector<ll>(K+1));


    T[1][1]=0,T[1][2]=1;
    T[2][1]=1,T[2][2]=1;



    T = pow(T, N);
    return T;


}


int main()
{

    int t;

    scanf("%d", &t);


    for (int cs = 1; cs <= t; cs++)
    {
        long long   int n, x, m, y, k;
        scanf("%lld%lld%lld%lld%lld",&n,&x,&m,&y,&k);
        matrix a=fib(n),b=fib(m);

        long long   int  c  = a[2][1], d  = a[2][2];
        long long   int  cp = b[2][1], dp = b[2][2];

        if ((c * dp - d * cp) == 0)
        {
            cout<<"Case "<<cs<<": Impossible"<<endl;
            continue;
        }
        long long a0 = (x * dp - y * d) / (c * dp - d * cp);
        long long b0 = (c * y - x * cp) / (c * dp - d * cp);
        if (((x * dp - y * d) % (c * dp - d * cp)) || ((c * y - x * cp) % (c * dp - d * cp))|| a0 < 0 || b0 < 0)
        {
            cout<<"Case "<<cs<<": Impossible"<<endl;
            continue;
        }

        matrix z=fib(k);
        cout<<"Case "<<cs<<": "<<(z[2][1] * a0 + z[2][2] * b0) % MOD<<endl;
    }


}

