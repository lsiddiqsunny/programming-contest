//http://shoshikkha.com/archives/4816
#include<bits/stdc++.h>
using namespace std;



double func(double H,double L)
{
    double r,a;
    double b=H;
    double c=L*0.5;

    r = b/2 + (c*c/(2*b));
    a = 2*asin(c/r);
    return r*a;
}

int main()

{
    int t;
    scanf("%d",&t);
    for(int x=1; x<=t; x++)
    {
        double W,n,C,L,S;
        scanf("%lf%lf%lf",&L,&n,&C);

        S=(1.0+(n*C))*L;

        double st=0.0,en=L,mid;

        for(int i=0; i<60; i++)
        {
            mid=(st+en)/2;
            if(func(mid,L)>S) en=mid;
            else st=mid;
        }
        printf("Case %d: %.6f\n",x,mid);
    }

    return 0;
}
