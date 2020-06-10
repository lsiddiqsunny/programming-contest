#include<bits/stdc++.h>
using namespace std;
int main()
{

    int q;
    cin>>q;
    while(q--)
    {
        long long n,a,b;
        cin>>n>>a>>b;
        long long lo=0,hi=n;
        long long mid;
        long long cost1=(n*a);
        long long cost2;
        if(n%2==0){
            cost2=(n/2)*b;
        }
        else cost2=(n/2)*b+a;
        cout<<min(cost1,cost2)<<endl;

    }


}
