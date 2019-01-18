#include<bits/stdc++.h>
using namespace std;
#define mx 1005
string s;
int dp[mx];
int pal[mx][mx];
bool check(int st,int e)
{
    if(st>=e) return 1;
    if(pal[st][e]!=-1) return pal[st][e];
    pal[st][e]=((s[st]==s[e])&&check(st+1,e-1));
    return pal[st][e];
}
int pali(int pos)
{
    if(pos==s.size()) return 0;
    if(dp[pos]!=-1) return dp[pos];
    int co=INT_MAX;
    for(int i=pos; i<s.size(); i++)
    {
        if(check(pos,i))
        {
            co=min(co,1+pali(i+1));
        }
    }
    dp[pos]=co;
    return dp[pos];

}
int main()
{
    int test;
    cin>>test;
    for(int i=1; i<=test; i++)
    {

        cin>>s;
        memset(dp,-1,sizeof(dp));
        memset(pal,-1,sizeof(pal));
       cout<<"Case "<<i<<": "<< pali(0)<<endl;

    }

}
