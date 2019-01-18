#include<bits/stdc++.h>
using namespace std;
long long two[63];
int main()
{
    two[0]=1;
    for(int i=1; i<=62; i++)
    {
        two[i]=2LL*two[i-1];//cout<<two[i]<<endl;
    }
    int test;
    scanf("%d",&test);
    while(test--)
    {
        long long s,m;
        scanf("%lld%lld",&s,&m);
        //if(s>m) swap(s,m);
        long long diff=abs(s-m);
       // cout<<diff<<endl;
        int step=0;
        for(int i=62; i>=0; i--)
        {
            if(diff<two[i])
                continue;
            if(diff==0)
                break;
            diff-=two[i];
            step++;
           // cout<<diff<<" "<<two[i]<<endl;

        }
        printf("%d\n",step);
    }
}
