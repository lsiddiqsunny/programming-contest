#include<bits/stdc++.h>
using namespace std;
int main()
{

    int test;
    scanf("%d",&test);
    for(int cs=1; cs<=test; cs++)
    {
        int n;
        scanf("%d",&n);
        double p=n*1.0;
        for(int i=1;i<n;i++){
            p=p+(i*1.0)/(n-i*1.0);
        }
        printf("Case %d: %.10f\n",cs,p);

    }
}
