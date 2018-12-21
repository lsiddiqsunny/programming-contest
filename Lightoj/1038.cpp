#include<bits/stdc++.h>
using namespace std;
#define mx 100005

vector<long long int >divisors[mx];
double dp[mx];

int main()
{
     for(int i=1; i<mx; i++)
    {
        for(int j=i; j<mx; j+=i)
        {
            divisors[j].push_back(i);
            //cout<<j<<" "<<i<<endl;

        }
    }
    for(int i=1; i<mx; i++)
    {
        sort(divisors[i].begin(),divisors[i].end());
    }

    for(int i=2; i<mx; i++)
    {
        dp[i]=1.0;
        for(int j=0; j<divisors[i].size(); j++)
        {
            if(divisors[i][j]!=i)
                dp[i]+=(dp[divisors[i][j]]+1);
        }
        dp[i]=dp[i]/(double)(divisors[i].size()-1);
    }
    int test;
    cin>>test;
    for(int i=1; i<=test; i++)
    {
        int n;
        cin>>n;
        printf("Case %d: %.10f\n",i,dp[n]);
    }

}

