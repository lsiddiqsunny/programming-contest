#include<bits/stdc++.h>
using namespace std;
int main()
{
    int test;
    scanf("%d",&test);
    for(int cs=1; cs<=test; cs++)
    {
        int n,m;
        scanf("%d",&n);

        int now=0;
        int co=0;
        for(int j=0; j<n; j++)
        {
            int x;
            scanf("%d",&x);
            if(x==1)
                co++;
            now^=x;
        }
        if(co==n)
        {
            if(!now)
            {
                printf("Case %d: Alice\n",cs);
            }
            else
                printf("Case %d: Bob\n",cs);
            continue;
        }


        if(now)
        {
            printf("Case %d: Alice\n",cs);
        }
        else
            printf("Case %d: Bob\n",cs);





    }
}


