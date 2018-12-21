#include<bits/stdc++.h>
int setbit(int n,int p)
{
    int mask=1;
    return (n|(mask<<p));

}
int resetbit(int n,int p)
{
    int mask=1;
    mask=mask<<p;
    mask=~mask;
    return (n&mask);

}
using namespace std;
int main()
{
    int test,s=1;
    cin>>test;
    for(s=1; s<=test; s++)
    {
        int n,mask=1;
        cin>>n;
        int i0,i1,p=0,q=0;
        for(int i=0; i<32; i++)
        {
            if((n&mask))
            {
                mask=mask<<1;
                if((n&mask)==0)
                {
                    i0=i+1;
                    i1=i;
                    break;
                }
                else
                    mask=mask>>1;
            }
            if((n&mask))
                p++;
            else
                q++;
            mask=mask<<1;
        }
        // cout<<p<<endl<<q<<endl;
        n=setbit(n,i0);
        n= resetbit(n,i1);
        int j,k;
        for( j=0; j<p; j++)
            n=setbit(n,j);
        for(k=p; j<=(p+q-1); j++)
            n=resetbit(n,j);
        cout<<"Case "<<s<<": "<<n<<endl;
        //s++;

    }
}
