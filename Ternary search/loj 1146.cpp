#include<bits/stdc++.h>

using namespace std;
double ax,ay,bx,by,cx,cy,dx,dy;
double dx1,dy1,dx2,dy2;
double f(double x)
{
    double x1 = ax + dx1 * x;
    double y1 = ay + dy1 * x;
    double x2 = cx + dx2 * x;
    double y2 = cy + dy2 * x;

    double dx3 = x2 - x1;
    double dy3 = y2 - y1;

    return sqrt(dx3*dx3 + dy3*dy3);
}

double ternary_search(double l, double r)
{
    double eps = 1e-9;              //set the error limit here
    while (r - l > eps)
    {
        double m1 = l + (r - l) / 3;
        double m2 = r - (r - l) / 3;
        double f1 = f(m1);      //evaluates the function at m1
        double f2 = f(m2);      //evaluates the function at m2
        if (f1 > f2)
            l = m1;
        else
            r = m2;
    }
    return f(l);                    //return the maximum of f(x) in [l, r]
}
int main()
{
    int test;
    cin>>test;

    for(int cs=1; cs<=test; cs++)
    {
        cin>>ax>>ay>>bx>>by>>cx>>cy>>dx>>dy;
        dx1=bx-ax;
        dy1=by-ay;
        dx2=dx-cx;
        dy2=dy-cy;
        double ans=ternary_search(0.0,1.0);
        printf("Case %d: %.10f\n",cs,ans);

    }

}
