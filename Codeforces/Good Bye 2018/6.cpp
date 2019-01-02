#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<long long int>v,x;
    for(int i=1; i<=n; i++)
    {
        v.push_back(i);
    }
    do
    {
        for(int i=0; i<n; i++)
        {
            x.push_back(v[i]);
        }
       // cout<<endl;

    }
    while(next_permutation(v.begin(),v.end()));
    long long int sum=(n*(n+1))/2LL;
    long long int co=1;
    long long cur=sum;
    for(int i=n;i<x.size();i++){
        cur-=x[i-n];
        cur+=x[i];
        if(sum==cur){
            co++;
        }
    }
    cout<<co<<endl;


}
