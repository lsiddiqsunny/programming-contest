#include<bits/stdc++.h>
using namespace std;
int Div[1001];
int pos[1000];

bool cmp (int i,int j)
{
    if(Div[i]==Div[j])return j<i;
    return Div[i]< Div[j];
}

int main()
{

    for(int i=1; i<1001; ++i)
    {
        pos[i-1]=i;
        int x=0;
        for(int j=1; j<i; ++j)
            if(i%j==0)x++;
        Div[i]=x;
    }


    sort(pos,pos+1000,cmp);
    int test;
    cin>>test;

    for(int i=1;i<=test;i++)
    {
        int n;
        cin>>n;
        cout<<"Case "<<i<<": "<<pos[n-1]<<endl;
    }
    return 0;
}
