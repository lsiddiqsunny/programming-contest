#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int n;
    cin>>n;
    long long x=sqrtl(n*1.0);
    long long y=ceil(n/(1.0*x));
    cout<<x+y<<endl;

}
