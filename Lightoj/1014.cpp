#include<bits/stdc++.h>
using namespace std;
int main()
{
    int test;
    scanf("%d",&test);
    for(int i=1; i<=test; i++)
    {
        int p,l;
        scanf("%d%d",&p,&l);
        int n=p-l;
        if(n<=l)
        {
            cout<<"Case "<<i<<": impossible"<<endl;
            continue;
        }
        vector<int>divisors;
        for(int j=1; j<=sqrt(n); j++)
        {
            if(n%j==0)
            {
                divisors.push_back(j);
                if((n/j)!=j)divisors.push_back(n/j);
            }
        }
        sort(divisors.begin(),divisors.end());
        cout<<"Case "<<i<<":";
        for(int j=0; j<divisors.size(); j++)
        {
            if(divisors[j]>l)
            cout<<" "<<divisors[j];
        }
        cout<<endl;
    }
}
