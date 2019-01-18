#include<bits/stdc++.h>
using namespace std;
int Set(int N,int pos)
{
    return N=N | (1<<pos);
}
int reset(int N,int pos)
{
    return N= N & ~(1<<pos);
}
bool check(int N,int pos)
{
    return (bool)(N & (1<<pos));
}
int main()
{

    int n;
    cin>>n;
    int a[n];
    int sum=0;
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
        sum+=a[i];
    }
    if(sum==360)
    {
        cout<<"YES"<<endl;
        return 0;
    }
    int po=1;
    for(int i=1; i<=n; i++)
    {
        po*=2;
    }

    for(int i=0; i<po; i++)
    {
        int nowsum=0,nowsum1=0;;
        for(int j=0; j<n; j++)
        {
            if(check(i,j))
            {
                nowsum+=a[j];
            }
            else
            {
                nowsum1+=a[j];
            }

        }
        nowsum%=360;
        nowsum1%=360;
        if(nowsum==nowsum1)
        {
            cout<<"YES"<<endl;
            return 0;
        }

    }

    cout<<"NO"<<endl;
    return 0;
}
