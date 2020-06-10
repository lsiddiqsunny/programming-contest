#include<bits/stdc++.h>
using namespace std;
int num[1005];
int n;

int ava()
{

    for(int i=1; i<=1000; i++)
    {
        if(num[i]==0)
            continue;
        if(num[i]>=4)

            return i;


    }
    return -1;

}


int ava1()
{

    for(int i=1; i<=1000; i++)
    {
        if(num[i]==0)
            continue;

        return i;


    }
    return -1;

}




int ava3()
{

    for(int i=1; i<=1000; i++)
    {
        if(num[i]==0)
            continue;
 if(num[i]>=2)

            return i;


    }
    return -1;

}
int main()
{


    cin>>n;
    bool ok=true;
    for(int i=1; i<=n*n; i++)
    {
        int x;
        cin>>x;
        num[x]++;
    }
    if(n==1)
    {
        cout<<"YES\n"<<ava1();
        return 0;
    }

    int b[n+1][n+1];
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            b[i][j]=-1;
        }
    }

    for(int i=1; i<=n/2; i++)
    {
        for(int j=1; j<=n/2; j++)
        {
            if(n%2==1 and ((n==(i*2-1)) ||(n==(j*2-1))))
                continue;


            int now=ava();
            if(now==-1)
            {
                // cout<<"here"<<endl;
                ok=false;
                break;
            }
            num[now]-=4;
            b[i][j]=now;
            b[i][n-j+1]=now;
            b[n-i+1][j]=now;
            b[n-i+1][n-j+1]=now;
        }
        if(!ok)
        {
            break;
        }
    }

    if(n%2==1)
    {
        for(int i=1; i<=n/2; i++)
        {



            int now=ava3();
            if(now==-1)
            {
                //cout<<"here"<<endl;
                ok=false;
                break;
            }
            num[now]-=2;
            b[n/2+1][i]=now;
            b[n/2+1][n-i+1]=now;
        }



        for(int i=1; i<=n/2; i++)
        {



            int now=ava3();
            if(now==-1)
            {
                //cout<<"here"<<endl;
                ok=false;
                break;
            }
            num[now]-=2;
           // b[n/2+1][i]=now;
            b[i][n/2+1]=now;
            b[n-i+1][n/2+1]=now;
           // b[n/2+1][n-i+1]=now;
        }
        ///5 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 3 3 3 3 3 3 3 3
        int now=ava1();
        if(now==-1)
        {
            ok=false;
        }
        num[now]--;
        b[n/2+1][n/2+1]=now;
    }


    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(b[i][j]==-1)
            {
                // cout<<"here"<<endl;
                ok=false;
                break;
            }
        }
    }
    if(!ok || ava1()!=-1)
    {
        cout<<"NO"<<endl;
        return 0;
    }
    cout<<"YES"<<endl;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            cout<<b[i][j]<<" ";
        }
        cout<<endl;
    }


}
