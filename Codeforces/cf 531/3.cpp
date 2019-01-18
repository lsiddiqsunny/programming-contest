#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,x,y;
    cin>>n>>x>>y;
    if(x>y)
    {
        cout<<n<<endl;
        return 0;
    }
    int a[n];
    for(int i=0; i<n; i++)
        cin>>a[i];
    sort(a,a+n);
    int pos=-1;
    for(int i=0; i<n; i++)
    {
        if(a[i]>x)
            break;
        pos=i;
    }
    if(pos==-1)
    {
        cout<<0<<endl;
        return 0;
    }
    int co=0;
    bool ok=true;
    while(ok)
    {

        for(int i=0; i<=pos; i++)
        {
            if(a[i]==-1)
            {
                continue;
            }
            if(a[i]>x)
            {
                continue;
            }
            if(a[i]<=x)
            {
                a[i]=-1;
                co++;
                if(i+1<=pos and a[i+1]!=-1)
                {
                    a[i+1]+=y;
                }
            }
        }
        int z=0;
        for(int i=0; i<=pos; i++)
        {
            if(a[i]==-1)
                continue;
            if(a[i]<=x)
            {
                z++;
                break;
            }
            //pos=i;
        }

        if(z==0)
        {
            ok=false;
        }

    }
    cout<<co<<endl;

}

