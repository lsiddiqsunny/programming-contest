#include<bits/stdc++.h>
using namespace std;
#define PI acos(-1.0)
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        double total=0;
        double a,b,c;
        int x[3];
        cin>>a>>b>>c;

        total=a+b+c;
        a=sqrt(a*1.0);
        b=sqrt(b*1.0);
        c=sqrt(c*1.0);

        double s=a+b+c;
        s/=2.0;
        total+=sqrt(s*(s-a)*(s-b)*(s-c));
        double theta=acos((b*b+c*c-a*a)/(2.0*b*c));
        theta=PI-theta;

        total+=(b*c*.5*sin(theta));

       // printf("%.10f %.10f\n",total,theta);

        theta=acos((b*b+a*a-c*c)/(2.0*b*a));
        theta=PI-theta;
        total+=(a*b*.5*sin(theta));

        theta=acos((c*c+a*a-b*b)/(2.0*c*a));
        theta=PI-theta;
        total+=(a*c*.5*sin(theta));

        printf("%.10f\n",total);


    }


}
